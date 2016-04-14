/*
 * DNI.hpp
 *
 *  Created on: 14 de abr. de 2016
 *      Author: rubenlabrador
 */

#ifndef DNI_HPP_
#define DNI_HPP_

class DNI {
public:
	int dniN;
	DNI();
	DNI(int N);
	virtual ~DNI();
	operator int(){
		return dniN;
	}
	bool operator == (DNI b);
	bool operator == (int b);
	int operator % (int n );
};
#endif /* DNI_HPP_ */
