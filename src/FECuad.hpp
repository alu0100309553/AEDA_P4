/*
 * FECuad.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FECUAD_HPP_
#define FECUAD_HPP_

#include "FuncExpl.hpp"
template<class T>

//Función de exploración cuadrática
class FECuad: public FuncExpl<T> {
public:
	FECuad(FuncDist<T> *pFD_, int N);
	virtual ~FECuad();
	int g(T clave, int intento);
};

//Constructor
template<class T>
FECuad<T>::FECuad(FuncDist<T> *pFD_, int N) :
		FuncExpl<T>::FuncExpl(pFD_, N) {

}

//Destructor
template<class T>
FECuad<T>::~FECuad() {
}

//Generación del salto h+i^2
template<class T>
int FECuad<T>::g(T clave, int intento) {

	return (FuncExpl<T>::pFD->h(clave) + (intento * intento)) % FuncExpl<T>::N;
}

#endif /* FECUAD_HPP_ */
