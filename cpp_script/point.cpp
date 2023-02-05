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

int point::getX() {
    return this->x;
}

int point::getY() {
    return this->y;
}

int point::getEtat() {
    return this->etat;
}

void point::changeEtat(int e) {
    this->etat = e;
}

void point::addVoisin(point & p, string dir) {
    if (dir == "g") this->voisin.gauche = & p;
}

point point::giveVoisin(string dir){
    if (dir == "g") return this->voisin.gauche;
}