/*
 * FERehash.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FEREHASH_HPP_
#define FEREHASH_HPP_

#include "FuncExpl.hpp"
template <class T>

class FERehash : public FuncExpl<T> {
public:
	FERehash(FuncDist <T> *pFD_, int N);
	virtual ~FERehash();
	int g (T clave, int intento);
};

#endif /* FEREHASH_HPP_ */
