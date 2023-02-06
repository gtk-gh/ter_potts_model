#include <iostream>
#include "matrice.h"
using namespace std;

int main() {
    point A;
    A = point(1,2,0);
    int x;
    x = A.getEtat();
    cout << x;

    return 0;
}
