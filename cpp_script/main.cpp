#include <iostream>
#include "metropolis_hastings.h"

using namespace std;

int main() {
    srand (time(NULL));

    vector<double> etat({0,1});
    int size = 10;

    vector<int> simil;
    vector<double> som;

    for (int i = 0; i < size; i++){
        for (int j = 0; j< size ; j++){
            int tempsim = 1;
            double tempsom = 0;
            if ((i <= size/2) && (j <= size/2)){
                tempsim =2;
                tempsom =1;
            }
            simil.push_back(tempsim);
            som.push_back(tempsom);
        }

    }
    //cout << som[30];

    matrice M = matrice(size,size,som,etat);
    //cout << M;
    int n = 1000;
    vector<matrice> MH1;
    MH1 = mh1(n,M,290,simil);

    save_matr2("../../py_script/temp.txt", MH1);
    return 0;
}
