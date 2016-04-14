/*
 * FDRan.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FDRAN_HPP_
#define FDRAN_HPP_


#include "FuncDist.hpp"
#include <random>

template <class T>
class FDRan : public FuncDist<T> {
public:
	FDRan(int N_);
	virtual ~FDRan();
	int h(T clave);
};



template <class T>
FDRan<T>::FDRan(int N_): FuncDist<T>::FuncDist(N_) {

}
template <class T>
int FDRan<T>::h(T clave){
	//int rand(void);   //esto añadido para que funcione con cpp <11
	srand(clave);
	return rand() % FuncDist<T>::N;
}


template <class T>
FDRan<T>::~FDRan() {
}

#endif /* FDRAN_HPP_ */
