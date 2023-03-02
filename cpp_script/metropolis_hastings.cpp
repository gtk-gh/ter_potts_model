//
// Created by Naïl Khalifa on 01/03/2023.
//

#include "metropolis_hastings.h"

#include <iostream>

using namespace std;

double p_T_z(double T, matrice M){
    double res = 0;
    double delta;
    int s = 1;
    vector<shared_ptr<point>> AllSommet = M.getAllSommet();
    int n = AllSommet.size();
    shared_ptr<point> point_i;
    shared_ptr<point> point_j;
    for (int i = 0;i<n;i++){
        point_i = AllSommet[i];
        for (int j = 0;j<n;j++){
            delta = 0;
            point_j = AllSommet[j];
            if(abs(point_i->getEtat() - point_j->getEtat()) < pow(10,-9)) delta = 1;
            res = res + (1-delta)*s;
        }
    }
    cout << "stopfinal";
    res = 0;
    return res;
}