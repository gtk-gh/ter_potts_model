//
// Created by Naïl Khalifa on 01/03/2023.
//

#include "metropolis_hastings.h"

#include <iostream>

using namespace std;

double p_T_z(double T, matrice & M){
    // Initialisation de variable
    double delta , res;
    int s = 1;
    res = 0;
    // on récupère toutes les valeurs de la matrice + sa taille
    vector<shared_ptr<point>> AllSommet = M.getAllSommet();
    int n = M.getFullSize();
    // on crée deux variables de point pour parcourir tous les points de la matrice
    shared_ptr<point> point_i;
    shared_ptr<point> point_j;
    for (int i = 0;i<n;i++){
        point_i = M.getSommet(i);
        for (int j = 0;j<n;j++){
            delta = 0;
            point_j = M.getSommet(j);

            // on calcule delta
            if(abs(point_i->getEtat() - point_j->getEtat() ) < pow(10,-9)) delta = 1;

            // on calcule s


            // on rajoute au res
            res = res + (1-delta)*s;
        }
    }
    return (1/T)*res;
}