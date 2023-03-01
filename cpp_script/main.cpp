#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    vector<double> etat({0,1,2,3,4,5,6,7,8,9,10});
    matrice M = matrice(5,5,etat);
    cout << M;
    shared_ptr<point> temp;
    temp = M.getSommet2(0);
    cout << *temp << endl;
    //save_matr("../../py_script/mat.txt",M);
    //M(0,0).changeX(9999);
    //temp.changeEtat(2222);
    changeEtat(temp,222222.0);
    cout << M;
    cout << endl << *temp;

    return 0;
}
