/*
 * Celda.hpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
 */

#ifndef CELDA_HPP_
#define CELDA_HPP_

#include <vector>;
using namespace std;

template <class T>

class Celda {
private:
	vector<T> *pVector;
	int *claves;
public:
	Celda (int M);
	bool buscar (T &h, int &pos);
	bool insertar (const T &clave, const int pos);
	bool llena();
};



#endif /* CELDA_HPP_ */
