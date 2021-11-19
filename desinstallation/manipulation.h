#ifndef MANIPULATIONPAQUET_H
#define MANIPULATIONPAQUET_H

typedef struct Paquet{


    struct Paquet **reverseDep; 
    char *nomPaquetCourant; 
    char *Priorite; 
    int nombrePaquetDependant; 

}Paquet; 

void ajouterPaquetReverse (Paquet *parent , Paquet *enfant); 

void afficherDependanceInversePaquet(Paquet *parent); 
#endif 
