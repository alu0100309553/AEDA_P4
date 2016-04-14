/*
 * FMod.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FDMOD_HPP_
#define FDMOD_HPP_

#include "FuncDist.hpp"

//Función de dispersión por módulo
template<class T>
class FDMod: public FuncDist<T> {
public:
	FDMod(int N_);
	virtual ~FDMod();
	int h(T clave);
};

//Constructor
template<class T>
FDMod<T>::FDMod(int N_) :
		FuncDist<T>::FuncDist(N_) {

}

//Cálculo del valor de la posición
template<class T>
int FDMod<T>::h(T clave) {
	return clave % FuncDist<T>::N;
}


//Destructor
template<class T>
FDMod<T>::~FDMod() {
}

#endif /* FDMOD_HPP_ */
