#include <iostream>
#include "metropolis_hastings.h"
using namespace std;

int main() {
    vector<double> etat({0,1,2,3});
    matrice M = matrice(5,5,etat);
    matrice P = q(M);
    return 0;
}
