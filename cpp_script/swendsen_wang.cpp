//
// Created by Farid Briouat on 17/05/2023.
//

#include "swendsen_wang.h"
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <random>

using namespace std;


// Fonction pour générer les clusters via la procédure de percolation
matrice generate_clusters(matrice& config, double beta ){
    int n = config.getSize1(); // taille de la grille
    int E = *max_element(config.getVecEtat().begin(), config.getVecEtat().end()); // nb d'états
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

            if((visited(voisin_row,voisin_col)->getEtat() == 0.0) && config(row,col)->getEtat() == config(voisin_row,voisin_col)->getEtat()){
                double p = 1.0 - exp(-beta);
                if(dis(gen)<=p){
                    active.emplace_back(voisin_row,voisin_col);
                    visited(voisin_row,voisin_col)->changeEtat(1.0);
                }
            }
        }
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited(i,j)->getEtat()==0){
                etendre_cluster(i,j,current_cluster);

                while(!active.empty()){
                    auto current = active.back();
                    active.pop_back();
                    etendre_cluster(current.first, current.second, current_cluster);
                }

                current_cluster++;
            }
        }
    }
    return clusters;
}


//Fonction pour mettre à jour la configuration ( à terminer)

matrice update_configuration(matrice& config, matrice& clusters){
    int n = config.getSize1();
    matrice new_config = matrice(n,n);
    return new_config;
}