/*
 * FECuad.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FECUAD_HPP_
#define FECUAD_HPP_

#include "FuncExpl.hpp"
template <class T>

class FECuad : public FuncExpl<T> {
public:
	FECuad(FuncDist <T> *pFD_, int N);
	virtual ~FECuad();
	int g (T clave, int intento);
};

#endif /* FECUAD_HPP_ */
