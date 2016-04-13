/*
 * FECuad.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#include "FECuad.hpp"

template <class T>
FECuad<T>::FECuad(FuncDist <T> *pFD_, int N):  FuncExpl<T>::FuncExpl(pFD_, N) {

}
template <class T>
FECuad<T>::~FECuad() {
	// TODO Auto-generated destructor stub
}

template <class T>
int FECuad<T>::g (T clave, int intento){
	FuncExpl<T>::para = false;
	if (intento >= FuncExpl<T>::N){
		FuncExpl<T>::para = true;
	}
	return (FuncExpl<T>::pFD->h(clave)+(intento*intento))%FuncExpl<T>::N;
}

