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



    matrice M = matrice(size,size,som,etat);
    int n = 500;
    vector<matrice> MH1;
    vector<matrice> SW1;

    auto start = std::chrono::high_resolution_clock::now();

    MH1 = mh1(n,M,7,simil);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::seconds>(stop - start);
    cout <<endl << "Pour " << n << " itérations Métropolis-Hasting s'est exécuté en " << duration.count() << " seconde(s)." << endl;

    start = std::chrono::high_resolution_clock::now();
    SW1 = sw(n,M,1);
    stop = std::chrono::high_resolution_clock::now();
    duration = duration_cast<chrono::seconds>(stop - start);
    cout << "Pour " << n << " itérations Swendsen-Wang s'est exécuté en " << duration.count() << " seconde(s).";

    vector<matrice> mh2;
    mh2.push_back(MH1[0]);
    mh2.push_back(MH1[n-1]);
    vector<matrice> sw2;
    sw2.push_back(SW1[0]);
    sw2.push_back(SW1[n-1]);

    save_matr2("../../py_script/extraitmh.txt", mh2);
    save_matr2("../../py_script/fullmh.txt", MH1);
    save_matr2("../../py_script/extraitsw.txt", sw2);
    save_matr2("../../py_script/fullsw.txt", SW1);
    return 0;
}
