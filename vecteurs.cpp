#include <vector>
#include <iostream>

using namespace std;


void fct( vector<int> const& tab);   // const& si on veut eviter de copier le tableau (bcp de temps)

int main()
{
    int taille = 5, valeur = 0;
    vector<int> tableau(taille , valeur);

    vector<int> tab; // tableau vide (zero cases)
    int const t = tab.size() ; // afficher taille (constante malgré que sa taille change)
    tab.push_back(10);  // ajouter une case valant 10
    tab.pop_back();     // retirer la derniere case


    // multidimentsion

    vector<vector <int> > matrice; // ce n'est pas un tableau 2d mais plutot un tableau de lines (tailles differentes)
    matrice.push_back( vector<int> (5)); // line de 5 elts
    matrice.push_back( vector<int> (3,0)); // line de 3elts de 0

        // acces aux lignes
    matrice[0].push_back(5); // ajouter un elt a la 1ere line
    matrice[0][0] = 10 ; // changer la valeur de la 1ere case (il faut etre sure que ça existe)
    


    return 0;
}