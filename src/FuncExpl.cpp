/*
 * FuncExpl.cpp
 *
 *  Created on: 11 de abr. de 2016
 *      Author: ruben
 */

#include "FuncExpl.hpp"

template <class T>
FuncExpl<T>::FuncExpl(FuncDist <T> *pFD_): pFD(pFD_){
}

template <class T>
FuncExpl<T>::~FuncExpl() {
}

template <class T>
int FuncExpl<T>::g (T clave, int intento){
	return pFD->h(clave)+intento;
}

