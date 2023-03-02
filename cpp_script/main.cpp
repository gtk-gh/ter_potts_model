#include <iostream>
#include "metropolis_hastings.h"
using namespace std;

int main() {
    vector<double> etat({0,1});
    matrice M = matrice(5,5,etat);
    cout << M;
    double p ;
    p= p_T_z(10,M);
    vector<shared_ptr<point>> test;
    test = M.getAllSommet();
    cout << test[24]->getEtat();
    return 0;
}
