/*
 * FERehash.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#include "FERehash.hpp"
#include <random>

template <class T>
FERehash<T>::FERehash(FuncDist <T> *pFD_, int N):  FuncExpl<T>::FuncExpl(pFD_, N) {

}
template <class T>
FERehash<T>::~FERehash() {
	// TODO Auto-generated destructor stub
}

template <class T>
int FERehash<T>::g (T clave, int intento){
	int aux;
	FuncExpl<T>::para = false;
	if (intento >= FuncExpl<T>::N){
		FuncExpl<T>::para = true;
	}
	srand(clave);
	for (int i = 0; i <= intento; i++){
		aux = rand();
	}
	return (FuncExpl<T>::pFD->h(clave)+ aux)%FuncExpl<T>::N;
}

