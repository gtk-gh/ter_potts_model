//
// Created by Farid Briouat on 17/05/2023.
//

#include "swendsen_wang.h"
#include <iostream>
#include <time.h>
#include <unistd.h>


using namespace std;


// Fonction pour générer les clusters via la procédure de percolation
matrice generate_clusters(matrice& config, double beta ){
    int n = config.getSize1(); // taille de la grille
    int E = normeinf(config.getVecEtat()); // nb d'états
    matrice clusters = matrice(n,n); // nous indiquera à quel cluster est assigné chaque point
    matrice visited = matrice(n,n); // est ce que le point est visité ?

    int current_cluster = 1;
    vector<pair<int,int>> active;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<>dis(0.0,1.0);

    auto etendre_cluster = [&](int row, int col, int cluster){ // fonction lambda
        visited(row,col)->changeEtat(1.0);
        clusters(row,col)->changeEtat(cluster);

        vector<pair<int,int>> voisins; // on stockera les voisins de chaque point dans cette variable
        if(row>0) voisins.emplace_back(row-1,col); //voisin ouest
        if(row<n-1) voisins.emplace_back(row+1,col); // voisin est
        if(col>0) voisins.emplace_back(row,col-1); // voisin sud
        if(col<n-1) voisins.emplace_back(row,col+1); // voisin nord

        for(const auto& voisin : voisins){
            int voisin_row = voisin.first;
            int voisin_col = voisin.second;

            // Conditions pour ajouter le voisin au cluster
            if((visited(voisin_row,voisin_col)->getEtat() == 0.0) && config(row,col)->getEtat() == config(voisin_row,voisin_col)->getEtat()){
                double p = 1.0 - exp(-beta);
                if(dis(gen)<=p){
                    active.emplace_back(voisin_row,voisin_col);  // On ajoute le voisin pour le visiter plus tard
                    visited(voisin_row,voisin_col)->changeEtat(1.0); // On le marque comme visité
                }
            }
        }
    };

    // On parcourt la grille pour créer des clusters
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited(i,j)->getEtat()==0){
                etendre_cluster(i,j,current_cluster); // On regarde si on peut créer un cluster à partir de ce point

                // On regarde si on peut étendre le cluster à partir des voisins du point précédent
                while(!active.empty()){
                    pair<int,int> current = active.back();
                    active.pop_back();
                    etendre_cluster(current.first, current.second, current_cluster);
                }

                current_cluster++;
            }
        }
    }
    return clusters;
}



matrice update_configuration( matrice& config, matrice& clusters){
    int n = clusters.getSize1();
    int E = normeinf(config.getVecEtat());
    cout << E;
    matrice new_config(n,n,config.getVecEtat());

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, E);

    int new_etat;

    for(int cluster = 1; cluster<= clusters.getEtatSom().back(); cluster++){
        new_etat = dis(gen);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){

                // On vérifie qu'on est dans le bon cluster
                if(clusters(i,j)->getEtat() == cluster){
                    new_config(i,j)->changeEtat(new_etat);
                }
            }
        }
    }
    return new_config;
}