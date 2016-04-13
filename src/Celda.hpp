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
	T *pVector = 0;
	//static int tamCelda = 0;
	bool llenaC = false;
	//int *claves;
public:
	static int tamCelda;
	Celda ();
	Celda (int M);
	bool buscar (T h);
	bool insertar (T &clave);
	bool llena();
};



#endif /* CELDA_HPP_ */
