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

#endif /* FEDOBLE_HPP_ */
