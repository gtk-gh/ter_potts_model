//
// Created by Naïl Khalifa on 20/09/2022.
//
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#ifndef TP3_VECTOR_DOUBLE_H
#define TP3_VECTOR_DOUBLE_H

template<class T>
istream& operator >> (istream& input ,vector<T> & vec){ // surcharge opération >> ex : cin >> vect;
    cout << "Tapez le vecteur avec des espaces : ";
    string tab;
    getline(input,tab);
    while (tab.size() > 0){
        //vec.push_back(stod(tab[i]));
        int sizetemp = tab.substr(0,tab.find(" ")).size();
        vec.push_back(stod(tab.substr(0,tab.find(" "))));
        tab.erase(0,sizetemp+1);
    }
    return input;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& vec){ // surcharge opération << ex : cout << vect;
    os << "[ ";
    for (int i =0; i< vec.size(); i++){
        os << vec[i] << " ";
    }
    os << "]" ;//<<endl;
    return os;
}

template<class T, class Y>
vector<T> operator*(const vector<T> & vec,const Y scal){ // ne pas mettre & sur le vector<T> avant operator
    // mais pas vraiment compris pourquoi...
    vector<T> temp;
    for (int i = 0; i< vec.size(); i++){
        temp.push_back(scal * vec[i]);
    }
    return temp;
}

template<class T>
vector<T> operator+(const vector<T> & veca,const vector<T> & vecb){
    assert (veca.size() == vecb.size()); // verifier la taille des deux vecteurs pour pas avoir d'érreurs plus tard
    vector<T> res;
    for (int i =0; i < veca.size(); i++){
        res.push_back(veca[i]+vecb[i]);
    }
    return res;
}

template<class T>
vector<T> operator-(const vector<T> & veca,const vector<T> & vecb){
    assert (veca.size() == vecb.size()); // verifier la taille des deux vecteurs pour pas avoir d'érreurs plus tard
    vector<T> res;
    for (int i =0; i < veca.size(); i++){
        res.push_back(veca[i]-vecb[i]);
    }
    return res;
}

template<class T>
T operator* (const vector<T> & veca,const vector<T> & vecb){
    T res =0;
    for (int i =0; i < veca.size(); i++){
        res += veca[i]*vecb[i];
    }
    return res;
}

template<class T>
T normeinf(vector<T> vec){
    T temp = vec[0];
    for (int i = 0; i<vec.size();i++){
        if (vec[i]>temp) temp = vec[i];
    }
    return temp;
}

template <class T>
T normeun(vector<T> vec){
    T res = 0.0;
    for (int i = 0; i<vec.size();i++){
        res += abs(vec[i]);
    }
    return res;
}

template <class T>
T normeeuc(vector<T> vec) {
    T res = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        res += abs(vec[i])*abs(vec[i]);
    }
    return sqrt(res);
}

template <class T>
T normedeux(vector<T> vec) {
    T res = 0.0;
    for (int i = 0; i < vec.size(); i++) {
        res += abs(vec[i])*abs(vec[i]);
    }
    return sqrt(res/vec.size());
}

#endif //TP3_VECTOR_DOUBLE_H
