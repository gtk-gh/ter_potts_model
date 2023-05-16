#include <iostream>
#include "metropolis_hastings.h"

using namespace std;

int main() {
    srand (time(NULL));
    vector<double> etat({0,1});
    int size = 10;
    vector<double> som;
    for (int i = 0; i<size*size; i++){
        som.push_back(0);
    }
    matrice M = matrice(size,size,som,etat);
    cout <<M;
    //matrice P = q(M);
    //cout <<endl << M << endl << P;
    //cout << M<< endl <<P;
    //cout << p_T_z(290,M);

    int n = 100;

    vector<matrice> MH1;
    MH1 = mh1(n,M,400);
    for (int i =0; i<n; i++){
        //cout << endl <<MH1[i];
    }
    save_matr2("../../py_script/temp.txt", MH1);
    return 0;
}
