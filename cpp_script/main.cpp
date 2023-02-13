#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    vector<double> etat(3);
    etat[0] = 0;
    etat[1] = 1;
    etat[2] = 1.5;
    matrice M = matrice(10,10,etat);
    cout << M;
    //save_matr("../../py_script/mat.txt",M);
    cout << endl << M(0,0);
    M(0,0).changeEtat(2222);
    cout << M;

    return 0;
}
