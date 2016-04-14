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
};

bool operator == (DNI a, DNI b){
	return a.dniN == b.dniN;
}

bool operator == (DNI a, int b){
	return a.dniN == b;
}

int operator % (DNI a, int n ){
	return a.dniN % n;
}

DNI::DNI(): dniN(0) {

	// TODO Auto-generated constructor stub

}

DNI::DNI(int N): dniN(N) {

	// TODO Auto-generated constructor stub

}

DNI::~DNI() {
	// TODO Auto-generated destructor stub
}

#endif /* DNI_HPP_ */
