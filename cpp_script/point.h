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
    //~point();

    int getX(); // renvoie la coordonnée x
    int getY(); // renvoie la coordonnée y
    int getEtat(); // renvoie l'état

    void changeEtat(int); // change l'état du point
    void changeX(int); // change la coord x
    void changeY(int); // change la coord y

    void addVoisin(point &, string); // ajoute un voisin
    point getVoisin(string);

    point& operator = (const point&);
    friend ostream& operator << (ostream&, point &);
};

#endif //CPP_SCRIPT_POINT_H
