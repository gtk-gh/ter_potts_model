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

point::point(int x, int y,double etat){
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

double point::getEtat() {
    return this->etat;
}

void point::changeEtat(double e) {
    this->etat = e;
}

void point::changeX(int x2){
    this->x = x2;
}

void point::changeY(int y2){
    this->y = y2;
}

void point::addVoisin(point & p, string dir) {
    if (dir == "g") this->voisin.gauche = & p;
}

point point::getVoisin(string dir){
    //if (dir == "g")
        return *(this->voisin.gauche);
}

point& point::operator = (const point& A)
{
    this->x = A.x;
    this->y = A.y;
    this->etat = A.etat;
    this->voisin = A.voisin;
    return (*this);
}

ostream& operator << (ostream& s,  point & P){
    int x,y;
    double e;
    x = P.getX();
    y = P.getY();
    e = P.getEtat();
    s <<"("<< x << "," << y << "," << e<<")";
    return s;
}

point& point:: operator + (point& p){
    this->x = x + p.getX();
    this->y = y + p.getY();
    return (*this);
}

double p_scalaire(point& x1, point& x2){
    return x1.getX()*x2.getX() + x1.getY()*x2.getY();
}


double delta(point& x1, point& x2){
    //assert(((x1.getX() == x2.getX())||(x1.getY() == x2.getY()))); condition de voisinage
    if (x1.getEtat() == x2.getEtat()){return(1);}
    else return 0;
}