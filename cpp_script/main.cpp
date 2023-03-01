#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    vector<double> etat({0,1,2,3,4,5,6,7,8,9,10});
    matrice M = matrice(5,5,etat);
    cout << M;
    shared_ptr<point> temp;
    temp = M.getSommet(0);
    cout << temp << endl;
    changeEtat(temp,222222.0);
    double test;
    test = temp->getEtat();
    cout << test;
    cout << endl << temp;

    return 0;
}
