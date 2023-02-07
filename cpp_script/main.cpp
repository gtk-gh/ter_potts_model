#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    point A;
    A = point(1,2,0);
    int x;
    x = A.getEtat();
    matrice M = matrice(10,10);
    matrice N;
    N = M;
    cout << N;
    matrice T = N.transpose();
    return 0;
}
