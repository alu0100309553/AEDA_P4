/*
 * DNI.cpp
 *
 *  Created on: 14 de abr. de 2016
 *      Author: rubenlabrador
 */

#include "DNI.hpp"

bool DNI::operator ==(DNI b) {
	return dniN == b.dniN;
}

bool DNI::operator ==(int b) {
	return dniN == b;
}

int DNI::operator %(int n) {
	return dniN % n;
}
void DNI::operator =(int n) {
	dniN = n;
}

DNI::DNI() :
		dniN(0) {
}

DNI::DNI(int N) :
		dniN(N) {
}

DNI::~DNI() {
}

