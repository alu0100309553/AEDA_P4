/*
 * FuncExpl.hpp
 *
 *  Created on: 11 de abr. de 2016
 *      Author: ruben
 */

#ifndef FUNCEXPL_HPP_
#define FUNCEXPL_HPP_

#include "FuncDist.hpp"

template <class T>
class FuncExpl {

public:
	int N;
	//bool para;
	FuncDist <T> *pFD;
	FuncExpl(FuncDist <T> *pFD_, int N);
	virtual ~FuncExpl();
	virtual int g (T clave, int intento) = 0;
	//bool parar(void);
};

template <class T>
FuncExpl<T>::FuncExpl(FuncDist <T> *pFD_, int N_): pFD(pFD_), N(N_){
}

template <class T>
FuncExpl<T>::~FuncExpl() {
}
#endif /* FUNCEXPL_HPP_ */
