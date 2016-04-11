/*
 * FuncDisp.hpp
 *
 *  Created on: 11 de abr. de 2016
 *      Author: ruben
 */

#ifndef FUNCDISP_HPP_
#define FUNCDISP_HPP_

template <class T>
class FuncDisp {
public:
	int N;
	FuncDisp();
	virtual ~FuncDisp();
	int h (T clave);
	//virtual int h (T clave);
};

#endif /* FUNCDISP_HPP_ */
