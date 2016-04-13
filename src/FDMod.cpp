/*
 * FDMod.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#include "FDMod.hpp"

template <class T>
FDMod<T>::FDMod(int N_): FuncDist<T>::FuncDist(N_) {

}
template <class T>
int FDMod<T>::h(T clave) const{
	return clave % FuncDist<T>::N;
}

template <class T>
FDMod<T>::~FDMod() {
}
