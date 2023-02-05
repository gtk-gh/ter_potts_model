//
// Created by Naïl Khalifa on 05/02/2023.
//


#include <iostream>
#include "point.h"
using namespace std;

point::point(int x, int y){
    this->x = x;
    this->y = y;
    this->etat = 0;
}

point::point(int x, int y,int etat){
    this->x = x;
    this->y = y;
    this->etat = etat;
}