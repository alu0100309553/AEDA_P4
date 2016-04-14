/*
 * FuncDisp.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef FUNCDIST_HPP_
#define FUNCDIST_HPP_


//Clase base para las funciones de dispersión
template<class T>
class FuncDist {
public:
	int N;
	FuncDist(int N_);
	virtual ~FuncDist();
	virtual int h(T clave) = 0;  //Método completamente virtual que implementan las clases derivadas
};
//Constructor
template<class T>
FuncDist<T>::FuncDist(int N_) :
		N(N_) {
}
//Destructor
template<class T>
FuncDist<T>::~FuncDist() {
}

#endif /* FUNCDIST_HPP_ */
