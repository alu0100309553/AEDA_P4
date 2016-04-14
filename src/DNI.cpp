/*
 * DNI.cpp
 *
 *  Created on: 14 de abr. de 2016
 *      Author: rubenlabrador
 */

#include "DNI.hpp"



bool DNI::operator == (DNI b){
	return dniN == b.dniN;
}

bool DNI::operator == (int b){
	return dniN == b;
}

int DNI::operator % (int n ){
	return dniN % n;
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

