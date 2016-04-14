/*
 * FELin.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FELIN_HPP_
#define FELIN_HPP_

#include "FuncExpl.hpp"

template<class T>

class FELin: public FuncExpl<T> {
public:
	FELin(FuncDist<T> *pFD_, int N);
	virtual ~FELin();
	int g(T clave, int intento);
};

template<class T>
FELin<T>::FELin(FuncDist<T> *pFD_, int N) :
		FuncExpl<T>::FuncExpl(pFD_, N) {

}
template<class T>
FELin<T>::~FELin() {
}

template<class T>
int FELin<T>::g(T clave, int intento) {
	return (FuncExpl<T>::pFD->h(clave) + intento) % FuncExpl<T>::N;
}

#endif /* FELIN_HPP_ */
