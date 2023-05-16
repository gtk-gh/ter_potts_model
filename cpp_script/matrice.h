//
// Created by Naïl Khalifa on 15/05/2023.
//

#ifndef CPP_SCRIPT_MATRICE_H
#define CPP_SCRIPT_MATRICE_H
#include "point.h"
#include <time.h>
#include <stdlib.h>
#include <memory>

class matrice {
private:
    int size1;  // dimension des lignes de la matrice
    int size2;  // dimension des colonnes de la matrice
    int fullsize; // nb de lignes * nb de colonnes
    vector<shared_ptr<point>> sommet; // tous les points sont dans un seul vecteur
    vector<double> etats;

public:
    matrice() {this -> size1 =0; this -> size2 = 0;this->fullsize = 0; vector<double> etat({0}); this -> etats = etat;}; // on initialise la taille de la matrice à 0
    matrice(int,int);   // Affecte deux entiers à size1,2 de la matrice et initialise les coefficients à 0
    matrice(int,int,vector<double>); // construit une matrice avec état aléatoire selon un vecteur d'etat
    matrice(int,int,vector<double>,vector<double>); // constructeur avec un vecteur de sommet
    ~matrice();         // destructeur

    int getSize1(); // renvoie le nombre de lignes
    int getSize2(); // renvoie le nombre de colonnes
    int getFullSize(); // renvoie n*m

    vector<shared_ptr<point>> getAllSommet(); // renvoie tous les sommets sous forme de vecteur de pointeur
    shared_ptr<point> getSommet(int); // renvoie un sommet
    vector<double> getVecEtat();
    vector<double> getEtatSom();

    shared_ptr<point> operator() (int , int); // Renvoie le point i,j
    matrice& operator = (const matrice&); // surcharge de = (affectation)

    matrice transpose();    // transpose une matrice

    friend void save_matr(const char*, matrice &); // sauvegarde la matrice dans un txt
    friend ostream& operator <<(ostream&, matrice&); // Affichage matrice
    friend void save_matr2(const char*, vector<matrice> &);
};


#endif //CPP_SCRIPT_MATRICE_H
