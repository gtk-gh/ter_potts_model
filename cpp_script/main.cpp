#include <iostream>
#include "metropolis_hastings.h"

using namespace std;

int main() {
    vector<double> etat({0,1,2});
    matrice M = matrice(5,5,etat);
    vector<double> test=M.getVecEtat();
    //cout << etat << endl;
    //matrice P = q(M);
    //cout << p_T_z(290,M);
    vector<double> temp({1,2,3});
    cout << temp;
    int n = 10;

    vector<matrice> MH1;
    //MH1 = mh1(n,M,290);
    for (int i =0; i<n; i++){
        //cout << endl <<MH1[i];
    }
    return 0;
}
