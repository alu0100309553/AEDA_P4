/*
 * FDMod.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FDMOD_HPP_
#define FDMOD_HPP_

#include "FuncDist.hpp"

template<class T>
class FDMod: public FuncDist<T> {
public:
	FDMod(int N_);
	virtual ~FDMod();
	int h(T clave);
};

template<class T>
FDMod<T>::FDMod(int N_) :
		FuncDist<T>::FuncDist(N_) {

}
template<class T>
int FDMod<T>::h(T clave) {
	return clave % FuncDist<T>::N;
}

template<class T>
FDMod<T>::~FDMod() {
}

#endif /* FDMOD_HPP_ */
