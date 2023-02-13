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
    int x;
    int y;
    double etat;

    struct voisinage
    {
        point* gauche;
        point* droite;
        point* nord;
        point* sud;
    };
    voisinage voisin;

public:
    point() {this->x = 0; this->y = 0;this->etat = 0;};
    point(int,int);
    point(int,int,double);
    //~point();

    int getX(); // renvoie la coordonnée x
    int getY(); // renvoie la coordonnée y
    double getEtat(); // renvoie l'état

    void changeEtat(double); // change l'état du point
    void changeX(int); // change la coord x
    void changeY(int); // change la coord y

    void addVoisin(point &, string); // ajoute un voisin
    point getVoisin(string);

    point& operator = (const point&);
    point& operator + (point&); // renvoi la somme de deux points

    friend ostream& operator << (ostream&, point &);
    friend double p_scalaire(point&, point&);   // produit scalaire
    friend double delta(point&, point&);    //delta = 1 si deux sommets sont dans le mm état, 0 sinon
};

#endif //CPP_SCRIPT_POINT_H
