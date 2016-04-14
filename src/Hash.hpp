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
#include "FDRan.cpp"
#include "FDMod.cpp"
#include "FELin.cpp"
#include "FECuad.cpp"
#include "FEDoble.cpp"
#include "FERehash.cpp"

template <class T>

class Hash {
private:
	Celda <T>  *pCeldas;
	FuncDist <T> *pFD;
	FuncExpl <T>  *pFE;
	int contador;
	int numPos;
	int numCeldas;
public:
	Hash ();
	Hash (int N, int M);
	Hash (int N, int M, int FD, int FE);
	bool buscar (T &k);
	bool insertar (T &k);
	bool llena ();
};

#endif /* HASH_HPP_ */
