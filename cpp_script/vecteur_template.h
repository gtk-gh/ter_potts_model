/*
*
*  Created by caterina calgaro on 08/09/2020.
*  Copyright 2020 INRIA LILLE NORD EUROPE. All rights reserved.
*
*/

#if !defined (__IOSTREAM_H)
#include <iostream>
#endif
#if !defined (__FSTREAM_H)
#include <fstream>
#endif
#if !defined (__ASSERT_H)
#include <assert.h>
#endif
#if !defined(__CMATH_H)
#include <cmath>
#endif
#if !defined (__VECTOR_H)
#include <vector>
#endif

using namespace std;

template <class T>
istream& operator >> (istream&, vector<T> &);

template <class T>
ostream& operator << (ostream&, const vector<T> &);

template <class T>
void lire_vect(string, vector<T> &);

template <class T>
void ecrire_vect(string, vector<T> &);

template <class T>
vector<T> operator + (const vector<T>&, const vector<T>&);

template <class T>
vector<T> operator - (const vector<T>&, const vector<T>&);

template <class T>
double operator * (const vector<T>&, const vector<T>&);

template <class T>
vector<T> operator * (const vector<T>&, const T&);

template <class T>
T norme_inf(const vector<T> &);

template <class T>
T norme_1(const vector<T> &);

template <class T>
double norme_2(const vector<T> &);

template <class T>
double norme_l2(const vector<T> &);

