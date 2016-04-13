/*
 * FDRan.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#include "FDRan.hpp"
//#include "FuncDist.hpp"
#include <random>


template <class T>
FDRan<T>::FDRan(int N_): initrandon(false), FuncDist<T>::FuncDist(N_) {

}
template <class T>
int FDRan<T>::h(T clave) const{
	//int rand(void);
	if (!initrandon){
		srand(clave);
	};
	return rand() % FuncDist<T>::N;
}

template <class T>
void FDRan<T>::setInitRandon(bool estado) {
	initrandon = estado;
}

template <class T>
FDRan<T>::~FDRan() {
}

