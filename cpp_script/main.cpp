#include <iostream>
#include "metropolis_hastings.h"
using namespace std;

int main() {
    vector<double> etat({0,1});
    matrice M = matrice(5,5,etat);
    cout << M;
    double p = p_T_z(10,M);
    cout << p;
    return 0;
}
