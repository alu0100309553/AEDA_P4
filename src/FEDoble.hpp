/*
 * FEDoble.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FEDOBLE_HPP_
#define FEDOBLE_HPP_
#include "FuncExpl.hpp"
template<class T>

//Función de exploración por doble dispersión
class FEDoble: public FuncExpl<T> {
public:
	FEDoble(FuncDist<T> *pFD_, int N);
	virtual ~FEDoble();
	int g(T clave, int intento);
};

//Construtor
template<class T>
FEDoble<T>::FEDoble(FuncDist<T> *pFD_, int N) :
		FuncExpl<T>::FuncExpl(pFD_, N) {

}

//Destructor
template<class T>
FEDoble<T>::~FEDoble() {
}

//Generación del salto h+g(*)*i
template<class T>
int FEDoble<T>::g(T clave, int intento) {

	return (FuncExpl<T>::pFD->h(clave) + (intento * FuncExpl<T>::pFD->h(clave)))
			% FuncExpl<T>::N;
}

#endif /* FEDOBLE_HPP_ */
