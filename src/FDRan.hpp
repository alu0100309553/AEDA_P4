/*
 * FDRan.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FDRAN_HPP_
#define FDRAN_HPP_

#include "FuncDist.hpp"
#include <random>

//Función de dispersión por número aleatorio
template<class T>
class FDRan: public FuncDist<T> {
public:
	FDRan(int N_);
	virtual ~FDRan();
	int h(T clave);
};

//Constructor
template<class T>
FDRan<T>::FDRan(int N_) :
		FuncDist<T>::FuncDist(N_) {

}

//Cálculo del valor de la posición
template<class T>
int FDRan<T>::h(T clave) {
	//int rand(void);   //esto añadido para que funcione con cpp <11
	srand(clave);
	return rand() % FuncDist<T>::N;
}

//Destructor
template<class T>
FDRan<T>::~FDRan() {
}

#endif /* FDRAN_HPP_ */
