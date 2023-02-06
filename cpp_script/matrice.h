

#if !defined (__IOSTREAM_H)
#include <iostream>
#endif
#if !defined (__FSTREAM_H)
#include <fstream>
#endif
#if !defined (__CASSERT_H)
#include <cassert>
#endif
#if !defined(__CMATH_H)
#include <cmath>
#endif
#if !defined (__VECTOR_H)
#include <vector>
#endif

#include "vecteur_template.h"

using namespace std;

class matrice
{
private:
    int size1;  // dimension 1 de la matrice (nb de lignes)
    int size2;  // dimension 2 de la matrice (nb de colonnes)
    vector<double>* matrix;    // chaque ligne est un vector<double> de doubles
  
public:
    matrice() {this->size1 = this->size2 = 0;};  // constructeur par defaut
    matrice(int,int);                // constructeur en donnant les 2 dimensions
    matrice(const matrice&);         // constructeur par recopie
    ~matrice();                      // destructeur

    int dim1() const {return this->size1;}    // retourne la 1ere dimension de la matrice
    int dim2() const {return this->size2;}    // retourne la 2eme dimension de la matrice
    vector<double>& operator [] (int) const;  // retourne une ligne complete
    double& operator () (int,int) const;      // retourne un coefficient
    
    matrice& operator = (const matrice&); // surcharge de = (affectation)

    matrice transpose();    // transpose une matrice
    vector<double> colonne(const int);    // une colonne de la matrice
    
    matrice operator+(const matrice&); // somme de 2 matrices
    matrice operator-(const matrice&); // difference de 2 matrices
    matrice operator*(matrice&); // produit de 2 matrices, pas const matrice& à cause de transpose()
  
    matrice operator*(const double&); // matrice x cte
    
    vector<double> operator*(const vector<double>&); // produit A*v
    friend vector<double> operator*(const vector<double>&, matrice&); // produit v^t * A
    
    friend ostream& operator << (ostream&, const matrice &);        // surcharge << pour une matrice
    friend istream& operator >> (istream&, const matrice &);        // surcharge >> pour une matrice
    
    friend void save_matr(const char*, const matrice &); // ecriture dans un fichier
    friend matrice read_matr(const char *);              // lecture dans un fichier
};

//------------------------------------------------------
//------------------------------------------------------
// Constructeur v1
matrice::matrice(int n, int m)
{
    assert((n>0)&&(m>0));
    this->size1 = n;
    this->size2 = m;
    this->matrix = new vector<double>[n];
    vector<double> v(m,0);
    for (int i=0; i<n ; i++)
        this->matrix[i]=v;
}

//-----------------------------------------------------
// Constructeur par copie
matrice::matrice(const matrice & mat)
{
  assert((mat.size1)&&(mat.size2));
  this->size1=mat.size1;
  this->size2=mat.size2;
  this->matrix=new vector<double>[size1];
  for (int i=0; i<mat.size1 ; i++)
      this->matrix[i]=mat.matrix[i];
}
//-----------------------------------------------------
// Destructeur
matrice::~matrice()
{
  if (this->size1||this->size2) delete[] this->matrix;
  this->size1=0;
  this->size2=0;
}
//-------------------------------------------------------
// Retourne la ligne i
vector<double>& matrice::operator [] (int i) const
{
  assert((i>=0)&&(i<this->size1));
  return this->matrix[i];
}
//------------------------------------------------------
// Retourne le coefficient (i,j)
double& matrice::operator () (int i, int j) const
{
  assert((i>=0)&&(i<this->size1)&&(j>=0)&&(j<this->size2));
  return this->matrix[i][j];
}

//-------------------------------------------------------
// Surcharge = (affectation)
matrice& matrice::operator = (const matrice& mat)
{
  assert((mat.size1>0)&&(mat.size2>0));
  if ((!this->size1)||(!this->size2))
    {this->size1=mat.size1;
     this->size2=mat.size2;
     this->matrix=new vector<double>[size1];}
  assert((this->size1==mat.size1)&&(this->size2==mat.size2));
  for (int i=0; i<this->size1 ; i++)
    this->matrix[i]=mat.matrix[i];
  return (*this);
  }
//-------------------------------------------------------
// Transposee d'une matrice
matrice matrice::transpose()
{
    matrice T(this->size2,this->size1);
    for (int i=0; i<this->size2; i++)
        for (int j=0; j<this->size1; j++)
            T(i,j) = matrix[j][i];
    return T;
}
//-------------------------------------------------------
// Retourner la colonne j d'une matrice
vector<double> matrice::colonne (const int j)
{
    assert((j>=0)&&(j<this->size2));
    vector<double> vcol(this->size1);
    for (int i=0; i<this->size1; i++)
        vcol[i] = this->matrix[i][j];
    return vcol;
}
//-------------------------------------------------------
// Surcharge operateur + non symetrique : somme de 2 matrices
matrice matrice::operator + (const matrice& A)
{
	assert((this->size1>0)&&(this->size1==A.size1));
	assert((this->size2>0)&&(this->size2==A.size2));
	matrice C(this->size1,this->size2);
	for (int i=0; i<this->size1; i++)
		C[i] = this->matrix[i]+A[i];
	return C;
}
//-------------------------------------------------------
// Surcharge operateur - non symetrique : difference de 2 matrices
matrice matrice::operator - (const matrice& A)
{
    assert((this->size1>0)&&(this->size1==A.size1));
    assert((this->size2>0)&&(this->size2==A.size2));
    matrice C(this->size1,this->size2);
    for (int i=0; i<this->size1; i++)
        C[i] = this->matrix[i]-A[i];
    return C;
}
//-------------------------------------------------------
// Surcharge operateur * non symetrique : produit de 2 matrices
matrice matrice::operator * (matrice& A) // pas const A à cause de la fonction transpose
{
    assert((this->size1>0)&&(this->size2>0)&&(A.size1>0)&&(A.size2>0));
    assert(this->size2==A.size1);
    matrice TA=A.transpose();
    matrice C(this->size1,A.size2);
    for (int i=0; i<this->size1; i++)
         for (int j=0; j<A.size2; j++)
             C(i,j) = matrix[i]*TA[j];
    return C;
}
//-------------------------------------------------------
// Surcharge operateur * non symetrique : matrice x cte
matrice matrice::operator * (const double& cte)
{
	assert((this->size1>0)&&(this->size2>0));
	matrice C(this->size1,this->size2);
	for (int i=0; i<this->size1; i++)
	     C[i] = this->matrix[i]*cte;
	return C;
}
//-------------------------------------------------------
// Surcharge operateur * non symetrique : produit A*v
vector<double> matrice::operator * (const vector<double>& v)
{
    assert((this->size1>0)&&(this->size2>0)&&(this->size2==v.size()));
    vector<double> w(this->size1);
    for (int i=0; i<this->size1; i++)
        w[i] = this->matrix[i]*v;
    return w;
}
//-------------------------------------------------------
// Surcharge operateur * symetrique : produit v^t * A
vector<double> operator * (const vector<double>& v, matrice& A) // pas const A à cause de la fonction transpose
{
	assert((A.size1>0)&&(A.size2>0)&&(A.size1==v.size()));
	vector<double> w(A.size2);
	matrice TA=A.transpose();
	for (int i=0; i<A.size2; i++)
	     w[i] = v*TA[i];
	return w;
}
//-------------------------------------------------------
// Surcharge operator << pour une matrice
ostream& operator << (ostream& s, const matrice & mat)
{
    assert((mat.size1>0)&&(mat.size2>0));
    for (int i=0; i<mat.size1; i++)
            s << mat[i];
    return s;
}
//-------------------------------------------------------
// Surcharge operator >> pour une matrice
istream& operator >> (istream& s, const matrice & mat)
{
    assert((mat.size1>0)&&(mat.size2>0));
    cout << "Entrer au clavier une matrice avec " << mat.size1 <<" lignes et " << mat.size2 << " colonnes \n";
    for (int i=0; i<mat.size1; i++)
        for (int j=0; j<mat.size2; j++)
            s >> mat(i,j);
    return s;
}
//---------------------------------------------
// Sauvegarde d'une matrice dans un fichier
void save_matr(const char *Nomfich, const matrice & mat)
{
    ofstream fichier;
    fichier.open(Nomfich); // ouverture du fichier
    
    assert(mat.size1>0 && mat.size2>0);
    fichier << "Dimension de la matrice = " << mat.dim1() << " " << mat.dim2() << "\n";
    for (int i=0; i<mat.size1 ; i++)
        fichier << mat[i];
    fichier.close();           // fermature du fichier
}
//---------------------------------------------
// lecture d'une matrice dans un fichier
// on va obtenir une matrice de la bonne taille
matrice read_matr(const char *Nomfich)
{
    ifstream fichier;
    fichier.open(Nomfich); // ouverture du fichier
    if (!fichier){
        cerr << "Probleme d'ouverture de fichier " << endl;
        exit(1);
    }
    
    int m,n;
    if (!fichier.eof()) 
      fichier >> m >> n;
    matrice M(m,n);

    for (int i=0;i<M.size1;i++){
        for (int j=0;j<M.size2;j++){
            fichier >> M(i,j);
            if (fichier.eof())
                cout << " Erreur dans le fichier, matrice incomplete \n ";
        }
    }
    fichier.close();   // fermeture du fichier
    return M;
}
