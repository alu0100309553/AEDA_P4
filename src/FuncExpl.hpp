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
private:
	bool para;
	int N;

public:
	FuncDist <T> *pFD;
	FuncExpl(FuncDist <T> *pFD_, int N);
	virtual ~FuncExpl();
	int g (T clave, int intento);
	bool parar(void);
};

#endif /* FUNCEXPL_HPP_ */
