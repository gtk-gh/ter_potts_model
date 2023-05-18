#include <iostream>
#include "metropolis_hastings.h"
#include "swendsen_wang.h"

using namespace std;

int main() {
    vector<double> etat({0,1});
    // Configuration initiale aléatoire
    matrice config = matrice(10,10,etat);
    cout << config<< endl;
    matrice clusters = generate_clusters(config, 0.5);
    cout << clusters;
    return 0;
}

