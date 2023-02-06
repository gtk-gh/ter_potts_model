#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    point A;
    A = point(1,2,0);

    point B;
    B = point(3,4,1);
    A.addVoisin(B,"g");

    point C;
    C = A.getVoisin("g");

    int x;
    x = C.getX();
    cout << x;

    B.changeX(99);
    x = C.getX();
    cout << endl << x;

    cout << C;

    return 0;
}
