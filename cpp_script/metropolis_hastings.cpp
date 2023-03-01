//
// Created by Naïl Khalifa on 01/03/2023.
//

#include "metropolis_hastings.h"

#include <iostream>

using namespace std;

double p_T_z(double T, matrice M){
    int n = M.getSize1()*M.getSize2();
    double res = 0;
    double delta;
    int s = 1;
    shared_ptr<point> point_i;
    shared_ptr<point> point_j;
    for (int i = 0;i<n;i++){
        point_i = M.getSommet(i);
        for (int j = 0;j<n;j++){
            delta = 0;
            point_j = M.getSommet(j);
            if(abs(point_i->getEtat()- point_j->getEtat()) < pow(10,-9)) delta = 1;
            res = res + (1-delta)*s;
            cout << point_i << " "<<point_j<<endl;
        }
        cout << "stop";
    }
    return res;
}