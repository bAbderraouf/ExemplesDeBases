#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
    int nombreElements;
};




Liste *initialisationListe(void);
void affichageListe(Liste *maListe);
void supprimerListeEntiere(Liste *maListe);
void ajouterElementAuDebut(Liste *maListe, int nbre);
void supprimerPremierElement(Liste *maListe);
void insererElemenentAuMilieu(Liste *maListe , int valeurPrecedente , int nouvelleValeur);
void supprimerElemenentAuMilieu(Liste *maListe , int valeurAsupprimer );

int main(){

    Liste *maListeChainee = initialisationListe();

    ajouterElementAuDebut(maListeChainee , 1);
    ajouterElementAuDebut(maListeChainee , 2);
    ajouterElementAuDebut(maListeChainee , 4);
    insererElemenentAuMilieu(maListeChainee ,  4 , 3);
    affichageListe(maListeChainee);
    supprimerPremierElement(maListeChainee);
    supprimerPremierElement(maListeChainee);
    supprimerElemenentAuMilieu(maListeChainee , 1);
    supprimerElemenentAuMilieu(maListeChainee , 2);
    affichageListe(maListeChainee);
    supprimerListeEntiere(maListeChainee);
    affichageListe(maListeChainee);

    return 0;
}


// Initialisation 
Liste *initialisationListe(){
    
    Liste *liste1 = (Liste*)malloc(sizeof(*liste1));  //*liste juste si jamais on decide de modifier le type du pointeur plutard
    Element *monElementDeListe = (Element*)malloc(sizeof(*monElementDeListe));  // le cast est ajouté a cause dun pb de compilation
   
    if(monElementDeListe == NULL || liste1 == NULL){
        exit(EXIT_FAILURE);
    }
    
    
    monElementDeListe->nombre = 0;
    monElementDeListe->suivant = NULL;
    liste1->premier = monElementDeListe;
    liste1->nombreElements = 1;

    return liste1;   // resultat :  premier --> element1 =0 --> NULL
}

//-------------------------------
// affichage 
//-------------------------------

void affichageListe(Liste *maListe){

    if(maListe == NULL){
        exit(EXIT_FAILURE);
    }

    printf("Affichage de la liste : \n\t");
    Element *actuel = maListe->premier;

    while(actuel != NULL)
    {
        printf("( %d )-->", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("(NULL).\n");
    printf("\tNombre d'elements = %d\n", maListe->nombreElements);
}

//-------------------------------
// supprimer toute la liste
//-------------------------------

void supprimerListeEntiere(Liste *maListe){
    if(maListe == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Element *actuel = maListe->premier;

    while(actuel != NULL)
    {
        maListe->premier = actuel->suivant;
        free(actuel);
        (maListe->nombreElements)--;
        actuel = maListe->premier;
    }
    maListe = NULL;
}

//-------------------------------
// void ajouterElement au debut
//-------------------------------

void ajouterElementAuDebut(Liste *maListe , int nbre)
{
    Element *nouveau = (Element*)malloc(sizeof(*nouveau));
    if (nouveau == NULL || maListe == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nbre;
    nouveau->suivant = maListe->premier;
    maListe->premier = nouveau;
    (maListe->nombreElements)++;
}

//-------------------------------
// supprimer le premier element
//-------------------------------

void supprimerPremierElement(Liste *maListe)
{

    if(maListe == NULL )
    {
        exit(EXIT_FAILURE);
    }

    Element *aSupprimer = (Element*)malloc(sizeof(*aSupprimer));

    if(aSupprimer == NULL)
    {
        aSupprimer = maListe->premier;
        maListe->premier = aSupprimer->suivant;
        free(aSupprimer);
        (maListe->nombreElements)--;
    }
}

//-------------------------------
// insertion d'un element au milieu
//-------------------------------

void insererElemenentAuMilieu(Liste *maListe , int valeurPrecedente , int nouvelleValeur)
{
    if( maListe == NULL )
    {
        exit(EXIT_FAILURE);
    }

    Element *precedent = (Element*)malloc(sizeof(*precedent)); // actuel doit prendre la valeur de l'element precedent
    Element *nouveau = (Element*)malloc(sizeof(*nouveau));
    
    if( precedent != NULL  && nouveau != NULL)
    {
        nouveau->nombre = nouvelleValeur;  // initialiser avec le nv nbre
        precedent = maListe->premier;

        while ( precedent->nombre != valeurPrecedente  && precedent->suivant != NULL)
        {
            precedent = precedent->suivant;  
        }
        
        if(precedent->suivant != NULL)
        {
            nouveau->suivant = precedent->suivant;
            precedent->suivant = nouveau; 
            (maListe->nombreElements)++;
        }

    }
}


//-------------------------------
// supprimer un element au milieu
//-------------------------------

void supprimerElemenentAuMilieu(Liste *maListe , int valeurAsupprimer)
{
    if( maListe == NULL )
    {
        exit(EXIT_FAILURE);
    }

    Element *precedent = (Element*)malloc(sizeof(*precedent)); 
    Element *actuel = (Element*)malloc(sizeof(*actuel)); 
    
    if( precedent != NULL  && actuel != NULL)
    {
        precedent = maListe->premier;

        while ( precedent->suivant->nombre != valeurAsupprimer  && actuel->suivant != NULL)
        {
            precedent = precedent->suivant;  
        }
        
        if( precedent->suivant != NULL)
        {   
            actuel = precedent->suivant;
            precedent->suivant = precedent->suivant->suivant;
            free(actuel);
            (maListe->nombreElements)--;
        }
        

    }
}