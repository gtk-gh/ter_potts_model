//
// Created by Naïl Khalifa on 01/03/2023.
//

#ifndef CPP_SCRIPT_METROPOLIS_HASTINGS_H
#define CPP_SCRIPT_METROPOLIS_HASTINGS_H

#include "matrice.h"


matrice q(const matrice & M);

double p_T_z(double T, matrice & M,vector<int> simil);

vector<matrice> mh1(int n, matrice & X0,double,vector<int> simil);

int sim(int,int,vector<int>);

#endif //CPP_SCRIPT_METROPOLIS_HASTINGS_H
