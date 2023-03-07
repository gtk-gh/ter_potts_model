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

point::point(point const & A){
    this->x = A.x;
    this->y = A.y;
    this->etat = A.etat;
}

point::~point(){
    //cout << "Le point : " << this << " " << this->x << "," << this->y << " a été supprimé." << endl;
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


point& point::operator = (const point& A)
{
    this->x = A.x;
    this->y = A.y;
    this->etat = A.etat;
    return (*this);
}

shared_ptr<point> point::operator = (const shared_ptr<point> A){
    this->x = A->x;
    this->y = A->y;
    this->etat = A->etat;
    point *ptr = new point(*A);
    shared_ptr<point> sptr(ptr);
    return (sptr);
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

ostream& operator << (ostream& s,  shared_ptr<point> P){
    int x,y;
    double e;
    x = P->getX();
    y = P->getY();
    e = P->getEtat();
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


int delta(point& x1, point& x2){
    //assert(((x1.getX() == x2.getX())||(x1.getY() == x2.getY()))); condition de voisinage
    int res;
    if (x1.getEtat() == x2.getEtat()){res = 1;}
    else res = 0;
    return res;
}

int z(point& p, double etat){
    int res;
    if(p.getEtat() == etat){res = 1;}
    else res = 0;
    return res;
}

void changeEtat(shared_ptr<point> A, double e){
    A->changeEtat(e);
}