/*
 * FEDoble.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FEDOBLE_HPP_
#define FEDOBLE_HPP_
#include "FuncExpl.hpp"
template <class T>

class FEDoble : public FuncExpl<T> {
public:
	FEDoble(FuncDist <T> *pFD_, int N);
	virtual ~FEDoble();
	int g (T clave, int intento);
};

template <class T>
FEDoble<T>::FEDoble(FuncDist <T> *pFD_, int N):  FuncExpl<T>::FuncExpl(pFD_, N) {

}
template <class T>
FEDoble<T>::~FEDoble() {
	// TODO Auto-generated destructor stub
}

template <class T>
int FEDoble<T>::g (T clave, int intento){

	return (FuncExpl<T>::pFD->h(clave)+(intento*FuncExpl<T>::pFD->h(clave)))%FuncExpl<T>::N;
}

#endif /* FEDOBLE_HPP_ */
