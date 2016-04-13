/*
 * FELin.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FELIN_HPP_
#define FELIN_HPP_

#include "FuncExpl.hpp"

template <class T>

class FELin : public FuncExpl<T> {
public:
	FELin(FuncDist <T> *pFD_, int N);
	virtual ~FELin();
	int g (T clave, int intento);
};

#endif /* FELIN_HPP_ */
