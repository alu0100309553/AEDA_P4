/*
 * Hash.hpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include "Celda.hpp";
#include "FuncExpl.hpp"
#include "FuncDisp.hpp"

template <class T>

class Hash {
private:
	Celda <T> *pCeldas;
	FuncDisp <T> *pFD;
	FuncExpl <T>  *pFE;
public:
	Hash (int N, int M);
	bool buscar (const T &k);
	bool insertar (const T &k);
	bool llena ();
};

#endif /* HASH_HPP_ */
