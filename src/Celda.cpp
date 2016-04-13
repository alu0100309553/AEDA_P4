/*
 * Celda.cpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
 */

#include "Celda.hpp"

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
bool Celda<T>::buscar (T h){
	bool encontrado = false;
	for (int i = 0 ; i < pVector->size() ; i++){
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

