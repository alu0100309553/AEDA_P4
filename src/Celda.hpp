/*
 * Celda.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef CELDA_HPP_
#define CELDA_HPP_

#include <vector>

using namespace std;

template<class T>

class Celda {
private:
	T *pVector;  //Vector de T dato con el que se formas las celdas de la posición
	bool llenaC; //Control de celda llena

public:
	static int tamCelda;  //Variable estática para fijar el tamaño de las celdas antes de crearlas.
	Celda();
	Celda(int M);
	bool buscar(T &h, int &contador);
	bool insertar(T &clave);
	bool llena();
};

template<class T>
int Celda<T>::tamCelda = 1;

template<class T>
//Constructor por defecto
Celda<T>::Celda() :
		pVector() {
	pVector = new T[tamCelda];
}

template<class T>
//Constructor con parámetro de tamaño de celda
Celda<T>::Celda(int M) :
		pVector() {
	pVector = new T[tamCelda];
}

template<class T>
//Método de búsqueda en la celda
bool Celda<T>::buscar(T &h, int &contador) {
	bool encontrado = false;        //variable para guardar si se ha encontrado el valor buscado
	bool encontradaVacia = false;   //variable para controlar si se encuentra una celda vacia y no es el dato dejar de recorror la celda
	int i = 0;
	while (!encontradaVacia && !encontrado && i < tamCelda) {
		if (pVector[i] == h) {
			encontrado = true;
			encontradaVacia = false;
		}else if(pVector[i] == 0){
			encontrado = false;
			encontradaVacia = true;
		}else {
			encontrado = false;
			encontradaVacia = false;
		}
		contador++;   //Contador que se pasa por referencia para los test
		i++;
	}
	return encontrado;
}

template<class T>
//Método para insertar
bool Celda<T>::insertar(T &clave) {
	bool insertado = false;
	int i = 0;
	while (!insertado && i < tamCelda) {
		if (pVector[i] == 0) {
			pVector[i] = clave;
			insertado = true;
			if (i==tamCelda-1){
				llenaC = true;
			}
		}
		i++;
	}
	if (!insertado) {
		llenaC = true;
	}
	return insertado;
}

template<class T>
//Método para consultar el estado de la celda antes de insertar
bool Celda<T>::llena() {
	return llenaC;
}

#endif /* CELDA_HPP_ */
