#include <iostream>
#include "swendsen_wang.h"

using namespace std;

int main() {
    srand (time(NULL));

    vector<double> etat({0,1});
    matrice config(10,10,etat);
    matrice clusters;
    clusters = generate_clusters(config,0.5);
    cout << clusters;
    return 0;
}
