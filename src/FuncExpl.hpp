/*
 * FuncExpl.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FUNCEXPL_HPP_
#define FUNCEXPL_HPP_

#include "FuncDist.hpp"
//Clase base de las funciones de exploración
template<class T>
class FuncExpl {
public:
	int N;
	FuncDist<T> *pFD;
	FuncExpl(FuncDist<T> *pFD_, int N);
	virtual ~FuncExpl();
	virtual int g(T clave, int intento) = 0; //Método completamente virtual que desarrollan las clases derivadas
};

//Constructor
template<class T>
FuncExpl<T>::FuncExpl(FuncDist<T> *pFD_, int N_) :
		pFD(pFD_), N(N_) {
}

//Destructor
template<class T>
FuncExpl<T>::~FuncExpl() {
}
#endif /* FUNCEXPL_HPP_ */
