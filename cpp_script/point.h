//
// Created by Naïl Khalifa on 05/02/2023.
//
#include <iostream>
#include "vecteur_template.h"
#ifndef CPP_SCRIPT_POINT_H
#define CPP_SCRIPT_POINT_H

class point
{
private :
    int x; // coordonnée x
    int y; // coordonnée y
    double etat; // etat

public:

    point() {this->x = 0; this->y = 0;this->etat = 0;}; // constructeur de point null
    point(int,int); // constructeur de point simple sans état
    point(int,int,double); // constructeur de point avec état
    point(point const &); // constructeur par copie
    ~point();

    int getX(); // renvoie la coordonnée x
    int getY(); // renvoie la coordonnée y
    double getEtat(); // renvoie l'état

    void changeEtat(double); // change l'état du point
    void changeX(int); // change la coord x
    void changeY(int); // change la coord y

    point& operator = (const point&); // surcharge =
    shared_ptr<point> operator = (const shared_ptr<point>); // surcharge = avec pointeur intelligent
    point& operator + (point&); // renvoi la somme de deux points

    friend ostream& operator << (ostream&, point &); // surcharge << pour affichage
    friend ostream& operator << (ostream&, shared_ptr<point>); // surcharge << pour affichage avec pointeur intelligent

    friend double p_scalaire(shared_ptr<point>, shared_ptr<point>);   // produit scalaire
    friend int delta(point&, point&);    //delta = 1 si deux sommets sont dans le mm état, 0 sinon
    friend int z(point&,double); // z = 1 si le sommet i est dans l'état k
    friend void changeEtat(shared_ptr<point> , double); // change l'état d'un pointeur intel (utile quand les points sont dans une matrice)
};

#endif //CPP_SCRIPT_POINT_H
