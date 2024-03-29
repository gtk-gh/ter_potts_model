//
// Created by Farid Briouat on 17/05/2023.
//

#ifndef CPP_SCRIPT_SWENDSEN_WANG_H
#define CPP_SCRIPT_SWENDSEN_WANG_H

#include "metropolis_hastings.h"
#endif //CPP_SCRIPT_SWENDSEN_WANG_H

matrice generate_clusters(matrice& config, double beta );
matrice update_configuration(matrice& config, matrice& clusters);
vector<matrice> sw(int n,matrice & X0,double beta);