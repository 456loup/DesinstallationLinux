#include <stdio.h> 
#include <stdlib.h> 
#include "manipulationPaquet.h" 


void testAjout(){

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

void testDoublon(){

    char **listePaquet = calloc(3 , sizeof(void*)) ;
    listePaquet[0] = "truc"; 
    listePaquet[1] = "bidule";  
    listePaquet[2] = "machin";

    char *doublonChaine = "machin";
    int taille = 3;  
    int doublon = chaineDejaPresenteDansLeTableauDeChar( listePaquet , doublonChaine , taille); 
    if(doublon == 1){
        printf(" \n\n le doublon  a bien ete detecte  \n\n");
    }else{
        printf("\n\n le doublo  n a pas ete detecte \n\n"); 
    }
}


void testAjouterListeChar(){

    char **truc = calloc(2 , sizeof(void*)); 
    int i = 0; 
    truc[0] = "mira"; 
    truc[1] = "pierra"; 

    char *chaineARajouter1 = "autre";
     
    char *chaineARajouter2 = "longerlesmurs";
    char *chaineARajouter3 = "ailleurs"; 
    char *chaineARajouter4 = "ailleurs"; 
    char *chaineARajouter5 = "ailleurs"; 
    char *chaineARajouter6 = "ailleurs"; 
    
    
    int taille = 2;

    ajouterElementAListeChar(&truc , chaineARajouter1 , &taille);  
 
    ajouterElementAListeChar(&truc , chaineARajouter2 , &taille);  

    ajouterElementAListeChar(&truc , chaineARajouter3 , &taille); 
     
    ajouterElementAListeChar(&truc , chaineARajouter4 , &taille); 
    ajouterElementAListeChar(&truc , chaineARajouter5 , &taille); 
    ajouterElementAListeChar(&truc , chaineARajouter6 , &taille); 

    for(i = 0 ; i < taille ; i++){
        printf("\n element %d vaut : %s" , i , truc[i]);  
    }
    free(truc);  
}


void testDressageListeSuppression(){


    char **listePaquetASupprimer = calloc(1 , sizeof(void*)); 
    int taille = 0; 


    if(listePaquetASupprimer[0] == NULL){
    
        printf(" LA CHAINE EST BIEN NULLE   " ); 
    
    
    }

    Paquet *parent = calloc(1 , sizeof(Paquet));  
    Paquet *enfant1 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant2 = calloc(1 , sizeof(Paquet));
    Paquet *enfant3 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant11 = calloc(1 , sizeof(Paquet));
    Paquet *enfant21 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant22 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant31 = calloc(1 , sizeof(Paquet)); 
    Paquet *enfant32 = calloc(1 , sizeof(Paquet)); 
    

    initialiserPaquet(parent , "ROOT" , "required"); 
    initialiserPaquet(enfant1 , "enfant1" , "optionnal"); 
    initialiserPaquet(enfant2 , "enfant2" , "optionnal");
    initialiserPaquet(enfant3 , "enfant3" , "optionnal");
    initialiserPaquet(enfant11 , "enfant11" , "optionnal"); 
    initialiserPaquet(enfant21 , "enfant21" , "optionnal");
    initialiserPaquet(enfant22 , "enfant22" , "optionnal"); 
    initialiserPaquet(enfant31 , "enfant31" , "optionnal"); 
    initialiserPaquet(enfant32 , "enfant32" , "optionnal"); 
    
    
    /*
    parent->nomPaquetCourant = "DARON"; 
    enfant1->nomPaquetCourant = "enfant1"; 
    enfant2->nomPaquetCourant = "enfant2";
    enfant11->nomPaquetCourant = "enfant11";
    enfant21->nomPaquetCourant = "enfant21"; 
    enfant22->nomPaquetCourant = "enfant22";  
    */
    ajouterPaquetReverse(parent , enfant1); 
    ajouterPaquetReverse(parent , enfant2);
    ajouterPaquetReverse(parent , enfant3);  
    ajouterPaquetReverse(enfant1 , enfant11); 
    ajouterPaquetReverse(enfant2 , enfant21);
    ajouterPaquetReverse(enfant2 , enfant22);
        
    ajouterPaquetReverse(enfant3 , enfant31);
    ajouterPaquetReverse(enfant3 , enfant32); 
    
     
 
    afficherDependanceInversePaquet(parent); 

    
    dresserListePaquetASupprimer(&listePaquetASupprimer , &taille , parent); 

    afficherTableauChar(listePaquetASupprimer , taille);  

}

int main(void){

    //testAjout(); 
    //testDoublon(); 
    //testAjouterListeChar(); 
    testDressageListeSuppression(); 

}

