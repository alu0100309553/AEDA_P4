/*
 * FuncDisp.hpp
 *
 *  Created on: 11 de abr. de 2016
 *      Author: ruben
 */

#ifndef FUNCDIST_HPP_
#define FUNCDIST_HPP_

template <class T>
class FuncDist {
public:
	int N;
	FuncDist(int N_);
	virtual ~FuncDist();
	virtual int h (T clave) = 0;
	//virtual int h (T clave);
};

#endif /* FUNCDIST_HPP_ */