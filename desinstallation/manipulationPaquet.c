#include <stdio.h>
#include <stdlib.h> 
#include "manipulationPaquet.h"


/* Bloc des fonctions principales    */

void initialiserPaquet(Paquet *parent , char *nomPaquet , char *Priorite){

    parent->nomPaquetCourant = nomPaquet; 
    parent->Priorite = Priorite; 

} 


void ajouterPaquetAPaquet(Paquet *parent , Paquet *paquetARajouter){


      Paquet  **listePaquetTransition = calloc(parent->nombrePaquetDependant , sizeof(void*)); 
      int i = 0;
      for(i = 0 ; i < parent->nombrePaquetDependant ; i++){
          listePaquetTransition[i] = parent->reverseDep[i]; 
      }
      parent->nombrePaquetDependant += 1;
      parent->reverseDep = realloc( parent->reverseDep ,  parent->nombrePaquetDependant ); 

      for(i = 0 ; i < parent->nombrePaquetDependant-1 ; i++){
          parent->reverseDep[i] =  listePaquetTransition[i];
	  printf(" je te hais %s " ,  parent->reverseDep[i]->nomPaquetCourant); 
      }
      parent->reverseDep[i] = paquetARajouter; 
}
      
/* Fonctionnalités principales  */

void ajouterPaquetReverse ( Paquet *parent , Paquet *enfant){

    if(parent->reverseDep == NULL){
    
	parent->reverseDep = calloc(1 , sizeof(void*)); 
        parent->reverseDep[0] = enfant; 	
        parent->nombrePaquetDependant = 1; 
    }else{
        ajouterPaquetAPaquet(parent , enfant) ;  
    }

}

void afficherDependanceInversePaquet(Paquet *parent){

    int i = 0 ; 
    printf(" \n --------------------- DEPENDANCES INVERSES DU PAQUET %s ------------------------ " , parent->nomPaquetCourant); 
    for(i = 0 ; parent->reverseDep != NULL &&  i < parent->nombrePaquetDependant ; i++){
        printf("\n le paquet parent %s a pour enfant %s    " , parent->nomPaquetCourant  , parent->reverseDep[i]->nomPaquetCourant); 
    }
    printf(" \n ------------------------- FIN DES DEPENDANCES INVERSES DU PAQUET %s ---------------------  \n\n" , parent->nomPaquetCourant); 
    
    if(parent->reverseDep != NULL){ 
    	for(i = 0 ; i < parent->nombrePaquetDependant ; i++){
        	afficherDependanceInversePaquet(parent->reverseDep[i]);  
    	}
    }
} 
