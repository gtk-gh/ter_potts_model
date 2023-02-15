#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    vector<double> etat({0,1,2,3,4});
    matrice M = matrice(5,5,etat);
    cout << M;
    point temp;
    temp = (M.getSommet(0));
    cout << endl << temp << endl;
    //save_matr("../../py_script/mat.txt",M);
    //cout << endl << M(0,0);
    M(0,0).changeX(9999);
    M(0,0).changeEtat(2222);
    cout << M;
    cout << temp;

    return 0;
}
