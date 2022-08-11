#include <iostream>
#include <fstream>
#include <string>

/*
    rmq : le fichier est automatiquement fermé a la fin de la fonction
    si on veut le fermer avant => monFlux.close()
    "UNITILE" mais pour retarder l'ouverture => monFlux.open()  
*/

using namespace std;

int main(){

    // I] - declarer un flux de ecriture 
        // methode A)
    ofstream monFlux("text.txt");  // ofstream : ecriture

        // methode B)
    string const monFichier("text.txt");
    ofstream monFlux2(monFichier.c_str());

    /* 
        rmq : si le fichier existe deja, il va l'ecraser 
            => si on veut ecrire a la fin de ce fichier existant :
             il faut declarer comme ceci : 
    */

    ofstream monFlux3(monFichier.c_str() , ios::app);  // ecrire a la fin du fichier (app = append)


    // tester si ok
    if(monFlux){
        int num = 0;
        monFlux << "voila le contenue de mon fichier numero :" << num << "." << endl;

    }
    else{
        // erreur impossible d'ouvrir le fichier
    }



    // II] - declarer un flux de lecture 
    ifstream monFlux_lecture(monFichier.c_str());  // lecture

    /*
        1-Ligne par ligne, en utilisant ------------------ getline()  .
        2-Mot par mot, en utilisant les chevrons --------- >>  .
        3-Caractère par caractère, en utilisant ---------- get() 
    */

    if(monFlux_lecture)
    {
        // A) -lire une ligne
        string ligne;
        getline(monFlux_lecture , ligne); 

        monFlux_lecture.ignore();        //On change de mode lecture

        // B) -lire un mot
        string mot;                 // int , double ou string
        monFlux_lecture >> mot;     // lire jusqu'au prochain espace   

        monFlux_lecture.ignore();        //On change de mode lecture

        // C) - lire un char
        char c;
        monFlux_lecture.get(c);     

        /* 
            rmq : getline() == 0 <=> fin du fichier
        */

    }
    else{
        // erreur d'ouverture en lecture
    }

    // III] le curseur dans un fichier



    // A) - trouver la position du curseur

    int position = monFlux.tellp();          // tellp() pour un ofstream
    int position2 = monFlux_lecture.tellg(); // tellg() pour un ifsteam (lecture)

    // B) - deplacer le curseur dans un fichier

    /*
        flux.seekp(nombreCaracteres, position);
        position = c'est position actuelle du curseur.

        Le début du fichier     : ios::beg  
        La fin du fichier       : ios::end 
        La position actuelle    : ios::cur  

    */

    monFlux.seekp( 10 , ios::beg );          // tellp() pour un ofstream
    monFlux_lecture.seekg(10 , ios::cur);    // tellg() pour un ifsteam (lecture)

    // C) - trouver la taille d'un fichier
    int taille ;
    monFlux_lecture.seekg(0, ios::end);  // aller a la fin du fichier
    taille = monFlux_lecture.tellg();    // calcul de la taille du fichier

    return 0;
}