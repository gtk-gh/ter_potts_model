//
// Created by Naïl Khalifa on 15/05/2023.
//

#include "matrice.h"

matrice :: matrice(int n, int m){
    this ->size1 = n;
    this ->size2 = m;
    this -> fullsize = n*m;
    vector<double> etat({0});
    this -> etats = etat;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            point temp = point(i,j,0); // crée un point à la pos i,j à l'état 0
            auto temp2 = make_shared<point>(i,j,0); // crée un pointeur intelligent pour le point i j
            sommet.push_back(temp2); // on push le pointeur intelligent dans le vecteur sommet
        }
    }
}

matrice::matrice(int n,int m ,vector<double> etat){
    // on fait la meme chose que le premier constructeur sauf que l'état n'est plus 0 mais une valeur random
    // du vecteur etat
    this ->size1 = n;
    this ->size2 = m;
    this->fullsize = n*m;
    this -> etats = etat;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            int randEtat = rand() % etat.size();// on génère une valeur comprise entre 0 et length d'état
            double tempEtat = etat[randEtat];
            auto temp2 = make_shared<point>(i,j,tempEtat);
            sommet.push_back(temp2);
        }
    }
}

matrice::matrice(int n,int m,vector<double> sommets,vector<double> etat){
    // on fait la meme chose que le premier constructeur sauf que l'état n'est plus 0 mais une valeur random
    // du vecteur etat
    this ->size1 = n;
    this ->size2 = m;
    this->fullsize = n*m;
    this -> etats = etat;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            auto temp2 = make_shared<point>(i,j,sommets[i*n+j]);
            sommet.push_back(temp2);
        }
    }
}

// Destructeur
matrice::~matrice()
{
    sommet.clear();
    //cout << "La matrice : " << this << " a été supprimé." << endl;
}

int matrice::getSize1(){
    return this->size1;
}

int matrice::getSize2(){
    return this->size2;
}

int matrice::getFullSize(){
    return this->fullsize;
}

shared_ptr<point> matrice::operator() (int i, int j)
{
    return (this)->sommet[i*this->size1 + j];
}

// Surcharge =
matrice& matrice::operator = (const matrice& mat){
    if ((!this->size1)||(!this->size2))
    {this->size1 = mat.size1;
        this->size2 = mat.size2;}
    assert((this->size1==mat.size1)&&(this->size2==mat.size2));
    this->fullsize = mat.fullsize;
    this->etats = mat.etats;
    for (int i = 0 ; i < this->size1; i++){
        for (int j = 0; j < this->size2; j++){
            auto temp2 = make_shared<point>(i,j,mat.sommet[i*this->size1 + j]->getEtat());
            this->sommet.push_back(temp2);
        }
    }

    //vector<shared_ptr<point>> matS = mat.sommet;
    //    for (const auto& e : matS)
    //        this->sommet.push_back(e->clone());
    return (*this);
}

// Transpose la matrice
matrice matrice::transpose()
{
    matrice T(this->size2,this->size1);
    for (int i=0; i<this->size2; i++)
        for (int j=0; j<this->size1; j++)
            T(i,j) = sommet[j*this->size1 + i];
    return T;
}

void save_matr(const char* Nomfich, matrice & mat){
    ofstream fichier;
    fichier.open(Nomfich); // ouverture du fichier

    assert(mat.getSize1()>0 && mat.getSize2()>0);
    fichier << mat.getSize1() << "\n" << mat.getSize2() << "\n";
    for (int i=0; i<mat.getSize1() ; i++){
        for (int j = 0 ; j < mat.getSize2()-1 ; j++){
            fichier << mat(i,j)->getEtat() << " ";
        }
        fichier << mat(i,mat.getSize2()-1)->getEtat() << "\n";
    }
    fichier.close();           // fermeture du fichier
}

void save_matr2(const char* Nomfich, vector<matrice> & mats){
    ofstream fichier;
    fichier.open(Nomfich);

    int n = mats.size();
    fichier << n <<"\n" <<mats[0].getSize1() << "\n" << mats[0].getSize2() << "\n";
    for (int m = 0; m<n ; m++){
        for (int i=0; i<mats[m].getSize1() ; i++){
            for (int j = 0 ; j < mats[m].getSize2()-1 ; j++){
                fichier << mats[m](i,j)->getEtat() << " ";
            }
            fichier << mats[m](i,mats[m].getSize2()-1)->getEtat() << "\n";
        }
        fichier << "\n";
    }
    fichier.close();           // fermeture du fichier
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

shared_ptr<point> matrice::getSommet(int i)
{
    return this->sommet[i];
}

vector<shared_ptr<point>> matrice::getAllSommet(){
    return this->sommet;
}

vector<double> matrice::getVecEtat() {
    return this->etats;
}

vector<double> matrice::getEtatSom() {
    vector<double> res;
    for (int i = 0; i<this->fullsize; i++){
        res.push_back(this->sommet[i]->getEtat());
    }
    return res;
}