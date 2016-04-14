/*
 * FERehash.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FEREHASH_HPP_
#define FEREHASH_HPP_

#include "FuncExpl.hpp"
#include <random>
template <class T>

class FERehash : public FuncExpl<T> {
public:
	FERehash(FuncDist <T> *pFD_, int N);
	virtual ~FERehash();
	int g (T clave, int intento);
};



template <class T>
FERehash<T>::FERehash(FuncDist <T> *pFD_, int N):  FuncExpl<T>::FuncExpl(pFD_, N) {

}
template <class T>
FERehash<T>::~FERehash() {
	// TODO Auto-generated destructor stub
}

template <class T>
int FERehash<T>::g (T clave, int intento){
	//int rand(void); //esto añadido para que funcione con cpp <11
	int aux;

	srand(clave);
	for (int i = 0; i <= intento; i++){
		aux = rand();
	}
	return (FuncExpl<T>::pFD->h(clave)+ aux)%FuncExpl<T>::N;
}

#endif /* FEREHASH_HPP_ */
