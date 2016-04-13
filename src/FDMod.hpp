/*
 * FDMod.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FDMOD_HPP_
#define FDMOD_HPP_

#include "FuncDist.hpp"

template <class T>
class FDMod : public FuncDist<T> {
//private:
	//bool initrandon;
public:
	FDMod(int N_);
	virtual ~FDMod();
	int h(T clave) const;
	//void setInitRandon(bool estado);
};

#endif /* FDMOD_HPP_ */
