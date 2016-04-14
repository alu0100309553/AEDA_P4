/*
 * FELin.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FELIN_HPP_
#define FELIN_HPP_

#include "FuncExpl.hpp"

//Función de exploración lineal
template<class T>
class FELin: public FuncExpl<T> {
public:
	FELin(FuncDist<T> *pFD_, int N);
	virtual ~FELin();
	int g(T clave, int intento);
};

//Constructor
template<class T>
FELin<T>::FELin(FuncDist<T> *pFD_, int N) :
		FuncExpl<T>::FuncExpl(pFD_, N) {
}

//Destructor
template<class T>
FELin<T>::~FELin() {
}

//Generación del salto h()+i
template<class T>
int FELin<T>::g(T clave, int intento) {
	return (FuncExpl<T>::pFD->h(clave) + intento) % FuncExpl<T>::N;
}

#endif /* FELIN_HPP_ */
