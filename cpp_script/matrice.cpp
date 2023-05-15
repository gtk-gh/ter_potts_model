//
// Created by Naïl Khalifa on 06/02/2023.
//

#include "matrice.h"

matrice :: matrice(int n, int m){
    this ->size1 = n;
    this ->size2 = m;
    this -> fullsize = n*m;
    this -> matrix = new vector<point>[n]; // vecteur de pointeur de vecteur
    vector<double> etat({0});
    this -> etats = etat;
    vector<point> v(m); // vecteur de point (il représente une ligne)
    for (int i = 0; i<n; i++){
        this -> matrix[i] = v;
        for (int j = 0; j<m; j++){
            point temp = point(i,j,0); // crée un point à la pos i,j à l'état 0
            auto temp2 = make_shared<point>(i,j,0); // crée un pointeur intelligent pour le point i j
            this -> matrix[i][j] = temp; // on remplace chaque point dans matrix par le point temp
            sommet.push_back(temp2); // on push le pointeur intelligent dans le vecteur sommet
        }
    }
}

matrice::matrice(int n,int m ,vector<double> etat){
    // on fait la meme chose que le premier constructeur sauf que l'état n'est plus 0 mais une valeur random
    // du vecteur etat
    srand (time(NULL)); // initialisation du random en fonction du timer de l'ordinateur
    this ->size1 = n;
    this ->size2 = m;
    this->fullsize = n*m;
    this -> matrix = new vector<point>[n];
    this -> etats = etat;
    vector<point> v(m);
    for (int i = 0; i<n; i++){
        this -> matrix[i] = v;
        for (int j = 0; j<m; j++){
            int randEtat = rand() % etat.size();// on génère une valeur comprise entre 0 et length d'état
            double tempEtat = etat[randEtat];
            point temp = point(i,j,tempEtat);
            auto temp2 = make_shared<point>(i,j,tempEtat);
            this -> matrix[i][j] = temp;
            sommet.push_back(temp2);
        }
    }
}

// Destructeur
matrice::~matrice()
{
    if (this->size1||this->size2){
        delete[] this->matrix;
    }
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

// Retourne le coefficient (i,j)
point& matrice::operator() (int i, int j)
{
    return *(this) -> sommet[i*this->size1 + j];
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

// Transpose la matrice
matrice matrice::transpose()
{
    matrice T(this->size2,this->size1);
    for (int i=0; i<this->size2; i++)
        for (int j=0; j<this->size1; j++)
            T(i,j) = matrix[j][i];
    return T;
}

void save_matr(const char* Nomfich, matrice & mat){
    ofstream fichier;
    fichier.open(Nomfich); // ouverture du fichier

    assert(mat.getSize1()>0 && mat.getSize2()>0);
    fichier << mat.getSize1() << "\n" << mat.getSize2() << "\n";
    for (int i=0; i<mat.getSize1() ; i++){
        for (int j = 0 ; j < mat.getSize2()-1 ; j++){
            fichier << mat(i,j).getEtat() << " ";
        }
        fichier << mat(i,mat.getSize2()-1).getEtat() << "\n";
    }
    fichier.close();           // fermeture du fichier
}


point& matrice::getSommet(int i) const
{
    return *(this)->sommet[i];
}

shared_ptr<point> matrice::getSommet(int i){
    return (this)->sommet[i];
}

vector<shared_ptr<point>> matrice::getAllSommet(){
    return this->sommet;
}

vector<double> matrice::getVecEtat() {
    return this->etats;
}