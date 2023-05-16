//
// Created by Naïl Khalifa on 01/03/2023.
//

#include "metropolis_hastings.h"

#include <iostream>
#include <unistd.h>

using namespace std;

matrice q(matrice & M){
    matrice res = M;
    int n = res.getFullSize();
    vector<double> etat = res.getVecEtat();
    int e = etat.size();
    srand (time(NULL));
    int randU = rand() % n;
    int randV = rand() % e;
    shared_ptr<point> sommetPtr = (res.getSommet(randU));
    double etatValue = etat[randV];
    changeEtat(sommetPtr, etatValue);
    return res;
}


double p_T_z(double T, matrice & M){
    // Initialisation de variable
    double delta , res, s;
    res = 0;
    // on récupère toutes les valeurs de la matrice + sa taille
    vector<shared_ptr<point>> AllSommet = M.getAllSommet();
    int n = M.getFullSize();
    // on crée deux variables de point pour parcourir tous les points de la matrice
    shared_ptr<point> point_i;
    shared_ptr<point> point_j;
    for (int i = 0;i<n;i++){
        point_i = M.getSommet(i);
        for (int j = 0;j<n;j++){
            delta = 0;
            s = 0;
            point_j = M.getSommet(j);

            // on calcule delta
            if(abs(point_i->getEtat() - point_j->getEtat() ) < pow(10,-9)) delta = 1;

            // on calcule s
            s = p_scalaire(point_i, point_j);
            s = 1;
            // on rajoute au res
            res = res + (1-delta)*s;
        }
    }
    return exp(-(1/T)*res); // Renvoi 0, car trop grande valeur dans l'exponentielle
}

vector<matrice> mh1(int n, matrice & X0, double T){
    /// INITIALISATION ///
    vector<matrice> res;
    res.push_back(X0);//initialisation de X0 dans le vecteur résultat

    int accept = 0; // compteur pour le taux d'acceptation

    /// BOUCLE ///
    for (int i = 1 ; i<n; i++){
        matrice Y; // matrice Y généré par la loi instrumentale
        Y = q(res[i-1]); // generation du candidat depuis X_(n-1) grâce à la loi instrumentale

        // CALCUL DE ALPHA
        double alpha = 1;
        double temp = p_T_z(T,Y) / p_T_z(T,res[i-1]);
        if(temp<alpha) alpha = temp;
        //cout << res[i-1].getVecEtat() << " " << Y.getVecEtat() << endl;
        cout << p_T_z(T,res[i-1]) << " " << p_T_z(T,Y) << endl;

        // VALIDATION DE ALPHA
        srand(time(NULL)); // initialisation de la seed
        usleep(rand()%10000); // sleep de l'ordinateur aléatoire en ms (pour une meilleure initialisation)

        double u = ((double)rand()/(double)RAND_MAX); //génération d'un double compris entre 0 et 1 de manière uniforme

        if (u < alpha){ // cas où on accepte Y
            res.push_back(Y);
            accept++;
        }
        else{
            res.push_back(res[i-1]);
        }

    }
    cout << "Il y à eu "<<accept<<" acceptations." << endl <<"Ce qui fait un taux d'acceptation de "<<double(accept)/n<<".";
    return res;
}
