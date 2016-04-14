/*
 * FERehash.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FEREHASH_HPP_
#define FEREHASH_HPP_

#include "FuncExpl.hpp"
#include <random>
template<class T>

//Función de exploración por ReHashing
class FERehash: public FuncExpl<T> {
public:
	FERehash(FuncDist<T> *pFD_, int N);
	virtual ~FERehash();
	int g(T clave, int intento);
};

//Constructor
template<class T>
FERehash<T>::FERehash(FuncDist<T> *pFD_, int N) :
		FuncExpl<T>::FuncExpl(pFD_, N) {

}

//Destructor
template<class T>
FERehash<T>::~FERehash() {
}

//Generación del salto h()+rand()^î
template<class T>
int FERehash<T>::g(T clave, int intento) {
	//int rand(void); //esto añadido para que funcione con cpp <11
	int aux;

	srand(clave);
	for (int i = 0; i <= intento; i++) {
		aux = rand();
	}
	return (FuncExpl<T>::pFD->h(clave) + aux) % FuncExpl<T>::N;
}

#endif /* FEREHASH_HPP_ */
