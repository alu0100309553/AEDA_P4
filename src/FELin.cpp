/*
 * FELin.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#include "FELin.hpp"

template <class T>
FELin<T>::FELin(FuncDist <T> *pFD_, int N):  FuncExpl<T>::FuncExpl(pFD_, N) {

}
template <class T>
FELin<T>::~FELin() {
	// TODO Auto-generated destructor stub
}

template <class T>
int FELin<T>::g (T clave, int intento){
	FuncExpl<T>::para = false;
	if (intento >= FuncExpl<T>::N){
		FuncExpl<T>::para = true;
	}
	return (FuncExpl<T>::pFD->h(clave)+intento)%FuncExpl<T>::N;
}


