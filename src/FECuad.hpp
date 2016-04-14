/*
 * FECuad.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FECUAD_HPP_
#define FECUAD_HPP_

#include "FuncExpl.hpp"
template<class T>

class FECuad: public FuncExpl<T> {
public:
	FECuad(FuncDist<T> *pFD_, int N);
	virtual ~FECuad();
	int g(T clave, int intento);
};

template<class T>
FECuad<T>::FECuad(FuncDist<T> *pFD_, int N) :
		FuncExpl<T>::FuncExpl(pFD_, N) {

}
template<class T>
FECuad<T>::~FECuad() {
}

template<class T>
int FECuad<T>::g(T clave, int intento) {

	return (FuncExpl<T>::pFD->h(clave) + (intento * intento)) % FuncExpl<T>::N;
}

#endif /* FECUAD_HPP_ */
