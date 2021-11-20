#!/bin/bash

apt rdepends $1 | sed -E "s/\(.*\)//" > transition.txt 


sed -E "s/^.*://" transition.txt > autre.txt

sed "/$1/d" autre.txt > transition.txt 

sed "/^$/d" transition.txt > autre.txt 

sed "s/[[:space:]]//" autre.txt > transition.txt 

cat transition.txt > autre.txt

rm transition.txt 
