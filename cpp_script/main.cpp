#include <iostream>
#include "swendsen_wang.h"

using namespace std;

int main() {
    srand (time(NULL));

    vector<double> etat({0,1,2});
    int size = 30;

    vector<int> simil;
    vector<double> som;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int tempsim = 1;
            double tempsom = 0;
            if ((i <= size / 2) && (j <= size / 2)) {
                tempsim = 2;
                tempsom = 1;
            }
            simil.push_back(tempsim);
            som.push_back(tempsom);
        }
    }
//            if ((((j%size == 1) or (j%size == (size-2))) and ((i>0) and (i<size-1))) or (((i==1) or (i==(size-2))) and ((j>0) and (j<(size-2))))) {
//                tempsim = 2;
//                tempsom = 1;
//            }
//
//            else if ((((j%size == 6) or (j%size == (size-7))) and ((i>0) and (i<size-1))) or (((i==6) or (i==(size-7))) and ((j>0) and (j<(size-2))))) {
//                tempsim = 2;
//                tempsom = 1;
//            }
//            else if ((((j%size == 11) or (j%size == (size-12))) and ((i>0) and (i<size-1))) or (((i==11) or (i==(size-12))) and ((j>0) and (j<(size-2))))) {
//                tempsim = 2;
//                tempsom = 1;
//            }
//            simil.push_back(tempsim);
//            som.push_back(tempsom);
//        }
//    }
//    cout << som[30];
//
//    for (int i = 0; i < size; i++){
//        for (int j = 0; j< size ; j++){
//            int val;
//            val = rand() % 3;
//            simil.push_back(val+1);
//            som.push_back(val);
//        }



    matrice M = matrice(size,size,etat);
    int n = 100;
    vector<matrice> MH1;
    //MH1 = mh1(n,M,1,simil);
    MH1 = sw(n,M,0.5);

    vector<matrice> mh2;
    //mh2.push_back(MH1[0]);
    //mh2.push_back(MH1[n-2]);
    //save_matr2("../../py_script/extrait.txt", mh2);
    //save_matr2("../../py_script/full.txt", MH1);
    return 0;
}
