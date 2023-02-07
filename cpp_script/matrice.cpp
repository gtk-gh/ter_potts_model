//
// Created by Naïl Khalifa on 06/02/2023.
//

#include "matrice.h"

// Initialisation
matrice :: matrice(int n, int m){
    this ->size1 = n;
    this ->size2 = m;
    this -> matrix = new vector<point>[n];
    vector<point> v(m);
    //point p = point(0,0,0);
    for (int i = 0; i<n; i++){
        this -> matrix[i] = v;
        for (int j = 0; j<m; j++){
            point temp;
            temp = point(i,j,0);
            this -> matrix[i][j] = temp;
        }
    }
}

// Destructeur
matrice::~matrice()
{
    if (this->size1||this->size2) delete[] this->matrix;
}

// Retourne le coefficient (i,j)
point& matrice::operator() (int i, int j) const
{
    return this -> matrix[i][j];
}

// Surcharge << affichage matrice
ostream& operator <<(ostream& s, matrice& M){
    for (int i=0; i<M.size1; i++){
        for (int j = 0; j<M.size2; j++){
            s << M(i,j) << " ";
        }
        cout << endl;
    }

    return s;
}

// Surcharge =
matrice& matrice::operator = (const matrice& mat){
    if ((!this->size1)||(!this->size2))
    {this->size1 = mat.size1;
        this->size2 = mat.size2;
        this->matrix = new vector<point>[size1];}
    assert((this->size1==mat.size1)&&(this->size2==mat.size2));
    for (int i=0; i<this->size1 ; i++)
        this -> matrix[i]=mat.matrix[i];
    return (*this);
}

// Transposee
matrice matrice::transpose()
{
    matrice T(this->size2,this->size1);
    for (int i=0; i<this->size2; i++)
        for (int j=0; j<this->size1; j++)
            T(i,j) = matrix[j][i];
    return T;
}