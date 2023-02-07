//
// Created by Naïl Khalifa on 06/02/2023.
//

#ifndef CPP_SCRIPT_MATRICE_H
#define CPP_SCRIPT_MATRICE_H
#include "point.h"

class matrice {
private:
    int size1;  // dimension des lignes de la matrice
    int size2;  // dimension des colonnes de la matrice
    vector<point>* matrix;     // chaque ligne de la matrice est un vecteur de points

public:
    matrice() {this -> size1 = this -> size2 = 0;}; // on initialise la taille de la matrice à 0
    matrice(int,int);   // Affecte deux entiers à size1,2 de la matrice et initialise les coefficients à 0
    ~matrice();         // destructeur

    point& operator() (int , int) const; // Renvoie le point i,j
    matrice& operator = (const matrice&); // surcharge de = (affectation)
    point& operator() (int , int) const; // Renvoie le point i,j
    matrice transpose();    // transpose une matrice

    friend ostream& operator <<(ostream&, matrice&);
    friend void save_matr(const char*, const matrice &);
    friend ostream& operator <<(ostream&, matrice&); // Affichage matrice
};


#endif //CPP_SCRIPT_MATRICE_H
