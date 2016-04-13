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
pCeldas()
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
pCeldas()
{
	pFD = new FuncDist<T>(N);
	pFE = new FuncExpl<T>(pFD);
	Celda<T>::tamCelda = M;
	pCeldas = new Celda<T>[N];

}

template <class T>
bool Hash<T>::insertar( T &k){
	bool insertado = false;
	int intento = 0;
	int pos = pFD->h(k);
	while (!insertado && !pCeldas[pos].llena()){
		insertado = pCeldas[pos].insertar(k);
		if (!insertado){
			pos = pFE->g(k,intento);
			intento++;
		}
	}
	return insertado;
}

template <class T>
bool Hash<T>::buscar(const T &k){
	bool encontrado = false;
	int intento = 0;
	int pos = pFD->h(k);
	while (!encontrado or !pFE->parar()){    //revisar condicion de parada
		encontrado = pCeldas[pos]->buscar(k);
		if (!encontrado){
			pos = pFE->g(k,intento);
			intento++;
		}
	}
	return encontrado;
}

template <class T>
bool Hash<T>::llena(){
	return false;
}


