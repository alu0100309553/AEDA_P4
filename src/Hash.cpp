/*
 * Hash.cpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
 */


#include "Hash.hpp"
#include "Celda.cpp"

using namespace std;

template <class T>
Hash<T>::Hash():
pFD(),
pFE(),
pCeldas(),
contador(0),
numPos(10),
numCeldas(10)
{
	pFD = FuncDist<T>(10);
	pFE = FuncExpl<T>(pFD);
	for (int i = 0; i<10; i++){
		pCeldas[i] = new Celda<T>(10);
	}
}

template <class T>
Hash<T>::Hash(int N, int M):
pFD(),
pFE(),
pCeldas(),
contador(0),
numPos(N),
numCeldas(M)
{
	pFD = new FDMod<T>(N);
	pFE = new FuncExpl<T>(pFD, N);
	Celda<T>::tamCelda = M;
	pCeldas = new Celda<T>[N];

}

template <class T>
bool Hash<T>::insertar( T &k){
	bool insertado = false;
	int intento = 0;
	int pos = pFD->h(k);
	if(!buscar(k) && !llena()){
		while (!insertado && !pCeldas[pos].llena()){
			insertado = pCeldas[pos].insertar(k);
			if (!insertado){
				pos = pFE->g(k,intento);
				intento++;
			}
		}
		if (insertado){
			contador++;
		}
	}
	else if(!llena()){
		insertado = true;   //porque ya existia en la tabla, no se inserta de nuevo
	}else{
		insertado = false;
	}
	return insertado;
}

template <class T>
bool Hash<T>::buscar(T &k){
	bool encontrado = false;
	int intento = 0;
	int pos = pFD->h(k);
	bool noExiste = false;
	while (!encontrado && !pFE->parar() && !noExiste){    //revisar condicion de parada
		if (pCeldas[pos].buscar(k)){
			encontrado = true;
			noExiste = false;
		} else if (!pCeldas[pos].buscar(k) && !pCeldas[pos].llena()){
			encontrado = false;
			noExiste = true;
		} else {
			encontrado = false;
			noExiste = false;
		}
		if (!encontrado && !noExiste){
			intento++;
			pos = pFE->g(k,intento);
		}
	}
	return encontrado;
}

template <class T>
bool Hash<T>::llena(){
	return contador >= numPos*numCeldas;
}


