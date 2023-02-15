//
// Created by Naïl Khalifa on 06/02/2023.
//

#include "matrice.h"

matrice :: matrice(int n, int m){
    this ->size1 = n;
    this ->size2 = m;
    this -> matrix = new vector<point>[n];
    vector<point> vec(n*m);
    this -> sommet = vec;
    vector<point> v(m);
    //point p = point(0,0,0);
    for (int i = 0; i<n; i++){
        this -> matrix[i] = v;
        for (int j = 0; j<m; j++){
            point temp;
            temp = point(i,j,0);
            this -> matrix[i][j] = temp;
            this -> sommet[n*i + j] = temp;
        }
    }
}

matrice::matrice(int n,int m ,vector<double> etat){
    srand (time(NULL));
    this ->size1 = n;
    this ->size2 = m;
    this -> matrix = new vector<point>[n];
    vector<point> vec(n*m);
    this -> sommet = vec;
    vector<point> v(m);
    for (int i = 0; i<n; i++){
        this -> matrix[i] = v;
        for (int j = 0; j<m; j++){
            point temp;
            int randEtat;
            randEtat = rand() % etat.size();
            temp = point(i,j,etat[randEtat]);
            this -> matrix[i][j] = temp;
            this -> sommet[n*i+j] = temp;
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

void save_matr(const char* Nomfich, const matrice & mat){
    ofstream fichier;
    fichier.open(Nomfich); // ouverture du fichier

    assert(mat.size1>0 && mat.size2>0);
    fichier << mat.size1 << "\n" << mat.size2 << "\n";
    for (int i=0; i<mat.size1 ; i++){
        for (int j = 0 ; j < mat.size2-1 ; j++){
            fichier << mat(i,j).getEtat() << " ";
        }
        fichier << mat(i,mat.size2-1).getEtat() << "\n";
    }
    fichier.close();           // fermature du fichier
}


point& matrice::getSommet(int i){
    return (this->sommet[i]);
}