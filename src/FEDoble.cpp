/*
 * FEDoble.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#include "FEDoble.hpp"

template <class T>
FEDoble<T>::FEDoble(FuncDist <T> *pFD_, int N):  FuncExpl<T>::FuncExpl(pFD_, N) {

}
template <class T>
FEDoble<T>::~FEDoble() {
	// TODO Auto-generated destructor stub
}

template <class T>
int FEDoble<T>::g (T clave, int intento){
	/**
	FuncExpl<T>::para = false;

	if (intento >= FuncExpl<T>::N){
		FuncExpl<T>::para = true;
	}
	**/
	return (FuncExpl<T>::pFD->h(clave)+(intento*FuncExpl<T>::pFD->h(clave)))%FuncExpl<T>::N;
}
