#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    matrice M = matrice(10,10);
    cout << M;
    save_matr("mat.txt",M);
    return 0;
}
