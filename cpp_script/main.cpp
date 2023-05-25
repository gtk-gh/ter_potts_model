#include <iostream>
#include "swendsen_wang.h"

using namespace std;

int main() {
    srand (time(NULL));

    vector<double> etat({0,1,2,3,4});
    int size = 20;

    vector<int> simil;
    vector<double> som;

    for (int i = 0; i < size; i++){
        for (int j = 0; j< size ; j++){
            int tempsim = 1;
            double tempsom = 0;
            if ((i <= size/2) && (j <= size/2)){
                tempsim = 2;
                tempsom = 1;
            }
            simil.push_back(tempsim);
            som.push_back(tempsom);
        }

    }
//    cout << som[30];
//
//    for (int i = 0; i < size; i++){
//        for (int j = 0; j< size ; j++){
//            int val;
//            val = rand() %2;
//            simil.push_back(val+1);
//            som.push_back(0);
//        }
//
//    }

    matrice M = matrice(size,size,som,etat);
    //cout << M;
    int n = 1;
    vector<matrice> MH1;
    MH1 = mh1(n,M,3,simil);

    vector<matrice> mh2;
    mh2.push_back(MH1[10]);
    mh2.push_back(MH1[n-1]);
    save_matr2("../../py_script/extrait.txt", mh2);
    save_matr2("../../py_script/full.txt", mh2);

    cout << "";
    return 0;
}
