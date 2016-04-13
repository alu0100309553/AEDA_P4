/*
 * Hash.hpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include "Celda.hpp"
#include "FuncDist.cpp"
#include "FuncExpl.cpp"

template <class T>

class Hash {
private:
	Celda <T>  *pCeldas;
	FuncDist <T> *pFD;
	FuncExpl <T>  *pFE;
public:
	Hash ();
	Hash (int N, int M);
	bool buscar (const T &k);
	bool insertar (T &k);
	bool llena ();
};

#endif /* HASH_HPP_ */
