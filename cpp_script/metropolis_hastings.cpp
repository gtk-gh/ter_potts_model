//
// Created by Naïl Khalifa on 01/03/2023.
//

#include "metropolis_hastings.h"

#include <iostream>


using namespace std;

matrice q(const matrice & M){
    matrice res;
    res = M;
    int n = res.getFullSize();
    vector<double> etat = res.getVecEtat();
    int e = etat.size();
    int randU = rand() % n; // choix d'un sommet aléatoire uniformément
    int randV = rand() % e; // choix d'un état aléatoire uniformément
    shared_ptr<point> sommetPtr = (res.getSommet(randU));
    double etatValue = etat[randV];
    changeEtat(sommetPtr, etatValue);
    return res;
}

vector<int> voisin(int i, matrice & M){
    int n = M.getSize1();
    int m = M.getSize2();
    vector<int> voisin;
    if (i<n){ // premiere ligne
        if (i == 0){
            voisin.push_back(1);
            voisin.push_back(n);
        }
        else if (i == (n-1)){
            voisin.push_back(i-1);
            voisin.push_back(i+n);
        }
        else {
            voisin.push_back(i-1);
            voisin.push_back(i+1);
            voisin.push_back(i+n);
        }
    }
    else if (i>=n*m){} // hors de la matrice
    else if (i > (n*(m-1))){ // derniere ligne
        if ((i%n) == 0){
            voisin.push_back(i-n);
            voisin.push_back(i+1);
        }
        else if (i%n == (n-1)){
            voisin.push_back(i-n);
            voisin.push_back(i-1);
        }
        else {
            voisin.push_back(i-1);
            voisin.push_back(i+1);
            voisin.push_back(i+n);
        }
    }
    else {// le reste de la matrice
        if ((i%n) == 0) { // coté gauche
            voisin.push_back(i-n);
            voisin.push_back(i+1);
            voisin.push_back(i+n);
        }
        else if ((i%n) == (n-1)) { // coté droit
            voisin.push_back(i-n);
            voisin.push_back(i-1);
            voisin.push_back(i+n);
        }
        else { // le reste
            voisin.push_back(i-n);
            voisin.push_back(i-1);
            voisin.push_back(i+n);
            voisin.push_back(i+1);
        }
    }
    return voisin;
}

int sim(int i, int j, vector<int> classes){
    // le but ici est de construire des similarités entre les sommets
    // int i et j représentent lse sommets i et j respectivement que l'on veut tester
    // vector<double> classes représente un vector de sommet avec comme valeur sa classe par défaut la classe 0 ne
    // représente aucune similarité
    // exemple : [ 0 , 1, 0 ,1 ,2 ,2] ici le sommet 0 et 2 n'ont aucune similarité avec d'autres sommets,
    // le sommet 1 et 3 ont les memes similarités et le 4 et 5 aussi.
    int res = 0;
    if ((classes[i] == classes[j])){
        res = 1;
    }
    return res;
}

double p_T_z(double T, matrice & M, vector<int> simil){
    // Initialisation de variable
    double delta , res;
    int s;
    res = 0;
    int n = M.getSize1();
    int m = M.getSize2();
    // on récupère toutes les valeurs de la matrice + sa taille
    vector<shared_ptr<point>> AllSommet = M.getAllSommet();
    int f = M.getFullSize();
    // on crée deux variables de point pour parcourir tous les points de la matrice
    shared_ptr<point> point_i;
    shared_ptr<point> point_j;
    for (int i = 0;i<f;i++){
        point_i = M.getSommet(i);
        vector<int> voisinage = voisin(i,M);
        for (int j = 0;j<f;j++){
            delta = 0;
            s = 0;
            point_j = M.getSommet(j);

            // on calcule delta
            if(abs(point_i->getEtat() - point_j->getEtat() ) < pow(10,-9)) delta = 1;

            if (find(voisinage.begin(), voisinage.end(), j) != voisinage.end()){
                s = sim(i, j, simil);
            }
            res = res + (1-delta)*s;
        }
    }
    return exp(-(1/T)*res); // Renvoi 0, car trop grande valeur dans l'exponentielle
}

vector<matrice> mh1(int n, matrice & X0, double T,vector<int> simil){
    /// INITIALISATION ///
    vector<matrice> res;
    res.push_back(X0);//initialisation de X0 dans le vecteur résultat

    int accept = 0; // compteur pour le taux d'acceptation

    /// BOUCLE ///
    for (int i = 1 ; i<n; i++){
        matrice Y; // matrice Y généré par la loi instrumentale
        //usleep(rand()%10000);
        Y = q(res[i-1]); // generation du candidat depuis X_(n-1) grâce à la loi instrumentale

        // CALCUL DE ALPHA
        double alpha = 1;
        double temp = p_T_z(T,Y,simil) / p_T_z(T,res[i-1],simil);
        //cout << p_T_z(T,Y,simil) << endl;
        if(temp<alpha) alpha = temp;

        double u = ((double)rand()/(double)RAND_MAX); //génération d'un double compris entre 0 et 1 de manière uniforme

        //cout << alpha << endl;

        if (u < alpha){ // cas où on accepte Y
            res.push_back(Y);
            accept++;
        }
        else{
            res.push_back(res[i-1]);
        }

    }
    cout << "Il y a eu "<<accept<<" acceptations." << endl <<"Ce qui fait un taux d'acceptation de "<<double(accept)/n<<".";
    return res;
}
