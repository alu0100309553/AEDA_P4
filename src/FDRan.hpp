/*
 * FDRan.hpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: ruben
 */

#ifndef FDRAN_HPP_
#define FDRAN_HPP_


#include "FuncDist.hpp"

template <class T>
class FDRan : public FuncDist<T> {
private:
	bool initrandon;
public:
	FDRan(int N_);
	virtual ~FDRan();
	int h(T clave) const;
	void setInitRandon(bool estado);
};

#endif /* FDRAN_HPP_ */
