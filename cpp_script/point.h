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
    int etat;

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
    point(int,int,int);

    int getX();
    int getY();
    int getEtat();

    void changeEtat(int);
    void changeX(int);

    void addVoisin(point &, string);
    point& giveVoisin(string);

    point& operator = (const point&);
};

#endif //CPP_SCRIPT_POINT_H
