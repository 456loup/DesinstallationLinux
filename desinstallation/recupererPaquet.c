#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manipulationPaquet.h"
#include "recupererPaquet.h"
#define FICHIER "rdep.txt"
#define  TAILLE_CHAINE_CARAC 300




/*
 *
 * Cette fonction a pour but de verifier si l on peut renvoyer un 
 *
 */
Paquet * testRetourPaquet( char *nom){

    Paquet *parent = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant1 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant2 = calloc(1 , sizeof(Paquet));


    parent->nomPaquetCourant = nom; 
    enfant1->nomPaquetCourant = "enfant1"; 
    enfant2->nomPaquetCourant = "enfant2"; 

    ajouterPaquetReverse(parent , enfant1); 
    ajouterPaquetReverse(parent , enfant2);

    return parent;  
}

/*
 *
 * creationPaquet 
 *
 * */


char * copierValeurChaine( char chaineACopier[] , int tailleChaine ){

    int i = 0;
    char *chaine = calloc(tailleChaine , sizeof(char)) ; 
    for(i = 0 ; i < tailleChaine &&  chaineACopier[i] != '\0' ; i++){
        chaine[i] = chaineACopier[i];  
    }
    return chaine; 
}

Paquet * creationPaquet( char  nom[] ){
	Paquet *paquet = calloc(1 , sizeof(Paquet));
	paquet->nomPaquetCourant = copierValeurChaine(nom , TAILLE_CHAINE_CARAC);
	return paquet; 
}

/*
 * Creation arborescence niveau 1 
 */


void ajouterToutesLesRdependsDirectes(Paquet *parent){

   /* definition des parametre de la commande  */ 
   char chaine1[TAILLE_CHAINE_CARAC] = "../scriptBash/auxiliaireBash.sh ";  
   char chaine2[TAILLE_CHAINE_CARAC];
   char lecture[TAILLE_CHAINE_CARAC]; 
   int i = 0;  
   strcat(chaine1 , parent->nomPaquetCourant);

   system(chaine1);

   FILE *fichier = fopen(FICHIER , "r");
         
   while( (fgets(lecture , TAILLE_CHAINE_CARAC , fichier)) != NULL  ){
        ajouterPaquetReverse(parent , creationPaquet(lecture) ); 	
   }   
}


void dresserArborescencePaquet(Paquet *parent , char ***chaineSuppression , int *tailleListe){

    if(*tailleListe < 1000){
    	int i = 0; 
    	int paquetPresent = 0;
    	int sauvegardeTailleListe = *tailleListe;  
    	Paquet *temp = creationPaquet(parent->nomPaquetCourant);
    	ajouterToutesLesRdependsDirectes(temp);


    	for(i = 0 ; i < temp->nombrePaquetDependant ; i++){
        	paquetPresent = chaineDejaPresenteDansLeTableauDeChar(*chaineSuppression , temp->reverseDep[i]->nomPaquetCourant , *tailleListe); 
        	if(paquetPresent != 1){
	    		ajouterPaquetReverse(parent , temp->reverseDep[i]);
	    		ajouterElementAListeChar(chaineSuppression , temp->reverseDep[i]->nomPaquetCourant , tailleListe); 	    
		}	 	
    	}

    	/* si on a reussi a rejouter des paquets   */
    	if(sauvegardeTailleListe < *tailleListe){
        	for(i = 0 ; i < parent->nombrePaquetDependant ; i++){
	    		dresserArborescencePaquet(parent->reverseDep[i] , chaineSuppression , tailleListe);  	     
		}
    	}
    }
}










/*------------------------------------  TEST SUR LES CHAINES DE CARACTERE ------------------------------------  */

void testChaineChar (char truc[]){
	
    char chaineLocal[TAILLE_CHAINE_CARAC] ; 

   
    char chaine2[TAILLE_CHAINE_CARAC] = " ARARAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; 
    char chaine3[TAILLE_CHAINE_CARAC] = " DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEL"; 
    strcpy(chaineLocal , chaine2); 
    printf(" chaineLocal %s : et sa taille est de  %d  " , chaineLocal , strlen(chaineLocal)); 

    strcpy(chaineLocal , chaine3); 

    printf(" la chaine final : %s " , chaineLocal);  

}
