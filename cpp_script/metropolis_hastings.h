//
// Created by Naïl Khalifa on 01/03/2023.
//

#ifndef CPP_SCRIPT_METROPOLIS_HASTINGS_H
#define CPP_SCRIPT_METROPOLIS_HASTINGS_H

#include "matrice.h"


matrice q(matrice & M);

double p_T_z(double T, matrice & M);

vector<matrice> mh1(int n, matrice X0);

#endif //CPP_SCRIPT_METROPOLIS_HASTINGS_H
