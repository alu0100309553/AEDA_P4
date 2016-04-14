/*
 * FuncExpl.cpp
 *
 *  Created on: 11 de abr. de 2016
 *      Author: ruben
 */

#include "FuncExpl.hpp"

template <class T>
FuncExpl<T>::FuncExpl(FuncDist <T> *pFD_, int N_): pFD(pFD_), N(N_){
}

template <class T>
FuncExpl<T>::~FuncExpl() {
}
/**
template <class T>
int FuncExpl<T>::g (T clave, int intento){
	para = false;
	if (intento >= N){
		para = true;
	}
	return (pFD->h(clave)+intento)%N;
}

template <class T>
bool FuncExpl<T>::parar (void){
	return para;
}
**/
