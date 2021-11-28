#ifndef RECUPERERPAQUET_H
#define RECUPERERPAQUET_H



Paquet * testRetourPaquet( char *nom); 


void testChaineChar(char truc[]); 


Paquet * creationPaquet( char  nom[] );

char *  copierValeurChaine( char chaineACopier[] , int tailleChaine); 

void dresserArborescencePaquet(Paquet *parent , char ***chaine , int *tailleListe); 

void ajouterToutesLesRdependsDirectes(Paquet *parent);

char * recupererPriorite(char nom[]);

int cePaquetEstIlInstalle(char nom[]);



void dresserArborescenceFinale(Paquet *parent , char ***chaine , int *tailleListe); 

#endif 
 
