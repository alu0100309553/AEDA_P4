/*
 * Hash.hpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#ifndef HASH_HPP_
#define HASH_HPP_

#include "Celda.hpp"
#include "FuncDist.hpp"
#include "FuncExpl.hpp"
#include "FDRan.hpp"
#include "FDMod.hpp"
#include "FELin.hpp"
#include "FECuad.hpp"
#include "FEDoble.hpp"
#include "FERehash.hpp"

using namespace std;
//Clase que implementa la tabla hash
template<class T>
class Hash {
private:
	Celda<T> *pCeldas; //Puntero al vector de celdas o posiciones
	FuncDist<T> *pFD;  //Puntero a la función de dispersion
	FuncExpl<T> *pFE;  //Puntero a la función de exploración
	int contador;	   //Contador para controlar si la tabla está llena
	int numPos;		   //Número de posiciones de la tabla
	int numCeldas;     //Número de celdas de la tabla
	int contadorTest;  //Contador para los test
public:
	Hash();
	Hash(int N, int M);
	Hash(int N, int M, int FD, int FE);
	bool buscar(T &k);
	bool insertar(T &k);
	bool llena();
	void resetContador() {contadorTest = 0;}; //Método para resetear el contador de test
	int getContador(void) {return contadorTest;}; //Método para consultar en contador de test
};

//Constructor por defecto
template<class T>
Hash<T>::Hash() :
		pFD(), pFE(), pCeldas(), contador(0), numPos(10), numCeldas(10) {
	pFD = FDMod<T>(10);
	pFE = FELin<T>(pFD);
	for (int i = 0; i < 10; i++) {
		pCeldas[i] = new Celda<T>(10);
	}
}


//Constructor indicando tamaño de la tabla
template<class T>
Hash<T>::Hash(int N, int M) :
		pFD(), pFE(), pCeldas(), contador(0), numPos(N), numCeldas(M) {
	pFD = new FDMod<T>(N);
	pFE = new FELin<T>(pFD, N);
	Celda<T>::tamCelda = M;
	pCeldas = new Celda<T> [N];

}

//Constructor con parámetros de tamaño y de tipo de función de dispersión y de exploración
template<class T>
Hash<T>::Hash(int N, int M, int fd, int fe) :
		pFD(), pFE(), pCeldas(), contador(0), numPos(N), numCeldas(M) {
	switch (fd) {
	case 1:
		pFD = new FDMod<T>(N);
		break;
	case 2:
		pFD = new FDRan<T>(N);
		break;
	default:
		pFD = new FDMod<T>(N);
	}

	switch (fe) {
	case 1:
		pFE = new FELin<T>(pFD, N);
		break;
	case 2:
		pFE = new FECuad<T>(pFD, N);
		break;
	case 3:
		pFE = new FEDoble<T>(pFD, N);
		break;
	case 4:
		pFE = new FERehash<T>(pFD, N);
		break;
	default:
		pFE = new FELin<T>(pFD, N);
	}

	Celda<T>::tamCelda = M;
	pCeldas = new Celda<T> [N];

}

//Método para insertar en la tabla
template<class T>
bool Hash<T>::insertar(T &k) {
	bool insertado = false;
	int intento = 0;
	int pos = pFD->h(k);
	if (!llena()) {
		while (!insertado && intento <= 5 * numPos) {  //Se ha establecido un bucle de 5 veces el tamaño de la tabla para encontrar una celda vacía
			if (!pCeldas[pos].llena()) {
				insertado = pCeldas[pos].insertar(k);
			}
			if (!insertado) {
				intento++;
				pos = pFE->g(k, intento);
			}
		}
		if (insertado) {
			contador++;
		}
	} else {
		insertado = false;
	}
	return insertado;
}

//Metodo para buscar en la tabla
template<class T>
bool Hash<T>::buscar(T &k) {
	bool encontrado = false;
	int intento = 0;
	int pos = pFD->h(k);
	bool noExiste = false;
	while (!encontrado && intento <= 5 * numPos && !noExiste) {  //Se ha establecido un número de iteraciones de 5 veces el tamaño de la tabla para encontrar el valor o determinar que no está
		bool aux = pCeldas[pos].buscar(k, contadorTest);
		if (aux) {
			encontrado = true;
			noExiste = false;
		} else if (!aux && !pCeldas[pos].llena()) {
			encontrado = false;
			noExiste = true;
		} else {
			encontrado = false;
			noExiste = false;
		}
		if (!encontrado && !noExiste) {
			intento++;
			pos = pFE->g(k, intento);
		}
	}
	return encontrado;
}

//Método para consultar el estado de la tabla
template<class T>
bool Hash<T>::llena() {
	return contador >= numPos * numCeldas;
}

#endif /* HASH_HPP_ */
