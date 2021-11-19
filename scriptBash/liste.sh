#!/bin/bash

shopt -s extglob
rm !(liste.sh|sectionPackage.txt|chercher.sh) # on fait le menage , on vire tout les fichiers sauf le script
dpkg --status > status.txt

required=listeRouge.txt
important=listeImportant.txt
standard=listeStandard.txt
optional=listeOptionnel.txt
extra=listeExtra.txt

echo "" > $required
echo "" > $important
echo "" > $standard
echo "" > $optional
echo "" > $extra

flag=0
fichier="status.txt"
sauvegarde=""


#On dresse les listes required important standard optional extra
while IFS= read -r line
do
    if [[  $line == *Package:* ]];
    then
        flag=1
	sauvegarde=$line
    fi
    if [[ "$line" =~ ^Priority:[[:space:]]required &&  $flag -eq 1  ]];
    then
        flag=0
        echo $sauvegarde >> $required
    fi
    if [[ "$line" =~ ^Priority:[[:space:]]important && $flag -eq 1 ]];
    then
        flag=0
        echo $sauvegarde >> $important
    fi
    if [[ $line =~ ^Priority:[[:space:]]standard && $flag -eq 1 ]];
    then
        flag=0
        echo $sauvegarde >> $standard
    fi
    if [[ $line =~ ^Priority:[[:space:]]optional && $flag -eq 1 ]];
    then
        flag=0
        echo $sauvegarde >> $optional
    fi
    if [[ $line =~ ^Priority:[[:space:]]extra && $flag -eq 1 ]];
    then
        flag=0
        echo $sauvegarde >> $extra
        echo "ce paquet la $sauvegarde est conserve"
    fi
done < "$fichier"


# on enleve tout les :Package au debut de chaque ligne
sed "s|Package: ||" $required > transition
cat transition > $required

sed "s|Package: ||" $important > transition
cat transition > $important

sed "s|Package: ||" $standard > transition
cat transition > $standard

sed "s|Package: ||" $optional > transition
cat transition > $optional

sed "s|Package: ||" $extra > transition
cat transition > $extra

rm transition
