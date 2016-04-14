/*
 * Hash.hpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
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

template<class T>

class Hash {
private:
	Celda<T> *pCeldas;
	FuncDist<T> *pFD;
	FuncExpl<T> *pFE;
	int contador;
	int numPos;
	int numCeldas;
	int contadorTest;
public:
	Hash();
	Hash(int N, int M);
	Hash(int N, int M, int FD, int FE);
	bool buscar(T &k);
	bool insertar(T &k);
	bool llena();
	void resetContador() {
		contadorTest = 0;
	}
	;
	int getContador(void) {
		return contadorTest;
	}
	;
};

using namespace std;

template<class T>
Hash<T>::Hash() :
		pFD(), pFE(), pCeldas(), contador(0), numPos(10), numCeldas(10) {
	pFD = FuncDist<T>(10);
	pFE = FuncExpl<T>(pFD);
	for (int i = 0; i < 10; i++) {
		pCeldas[i] = new Celda<T>(10);
	}
}

template<class T>
Hash<T>::Hash(int N, int M) :
		pFD(), pFE(), pCeldas(), contador(0), numPos(N), numCeldas(M) {
	pFD = new FDMod<T>(N);
	pFE = new FERehash<T>(pFD, N);
	Celda<T>::tamCelda = M;
	pCeldas = new Celda<T> [N];

}

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

template<class T>
bool Hash<T>::insertar(T &k) {
	bool insertado = false;
	int intento = 0;
	int pos = pFD->h(k);
	if (!llena()) {
		while (!insertado && intento <= 5 * numPos) {
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

template<class T>
bool Hash<T>::buscar(T &k) {
	bool encontrado = false;
	int intento = 0;
	int pos = pFD->h(k);
	bool noExiste = false;
	while (!encontrado && intento <= 5 * numPos && !noExiste) {
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

template<class T>
bool Hash<T>::llena() {
	return contador >= numPos * numCeldas;
}

#endif /* HASH_HPP_ */
