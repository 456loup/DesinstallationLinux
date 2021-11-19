#include <stdio.h> 
#include <stdlib.h> 
#include "manipulationPaquet.h" 

int main(void){

    Paquet *parent = calloc(1 , sizeof(Paquet));  
    Paquet *enfant1 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant2 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant11 = calloc(1 , sizeof(Paquet)); 


    parent->nomPaquetCourant = "DARON"; 
    enfant1->nomPaquetCourant = "enfant1"; 
    enfant2->nomPaquetCourant = "enfant2";
    enfant11->nomPaquetCourant = "enfant11"; 

    ajouterPaquetReverse(parent , enfant1); 
    ajouterPaquetReverse(parent , enfant2); 
    ajouterPaquetReverse(enfant1 , enfant11);
    


    printf(" bordel %s " , parent->reverseDep[0]->nomPaquetCourant); 
    afficherDependanceInversePaquet(parent); 

}
