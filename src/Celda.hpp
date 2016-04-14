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
	T *pVector;
	//static int tamCelda = 0;
	bool llenaC;
	//int *claves;
public:
	static int tamCelda;
	Celda ();
	Celda (int M);
	bool buscar (T &h);
	bool insertar (T &clave);
	bool llena();
};


template <class T>
int Celda<T>::tamCelda=1;

template <class T>

Celda<T>::Celda (): pVector(){
			pVector = new T [tamCelda];
}


template <class T>
Celda<T>::Celda (int M): pVector(){
			pVector = new T [tamCelda];
}

template <class T>
bool Celda<T>::buscar (T &h){
	bool encontrado = false;
	for (int i = 0 ; i < tamCelda ; i++){
		if (pVector[i] == h){
			encontrado = true;
		}

	}
	return encontrado;
}

template <class T>
bool Celda<T>::insertar (T &clave){
	bool insertado = false;
	int i = 0;
	while (!insertado && i < tamCelda){
		if (pVector[i] == 0){
			pVector[i] = clave;
			insertado = true;
		}
		i++;
	}
	if (!insertado){
		llenaC = true;
	}
	return insertado;
}

template <class T>
bool Celda<T>::llena(){
	return llenaC;
}


#endif /* CELDA_HPP_ */
