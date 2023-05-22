//
// Created by Naïl Khalifa on 01/03/2023.
//

#ifndef CPP_SCRIPT_METROPOLIS_HASTINGS_H
#define CPP_SCRIPT_METROPOLIS_HASTINGS_H

#include "matrice.h"
#include <algorithm>
#include <random>

matrice q(const matrice & M); // fonction instrumentale de MH

int sim(int,int,vector<int>); // renvoie la similarité entre deux points

vector<int> voisin(int,matrice &); // renvoie les voisins d'un point

double p_T_z(double T, matrice & M,vector<int> simil); // fonction cible de MH

vector<matrice> mh1(int n, matrice & X0,double,vector<int> simil); // Metropolis Hasting

#endif //CPP_SCRIPT_METROPOLIS_HASTINGS_H
