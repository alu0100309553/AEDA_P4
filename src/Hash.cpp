/*
 * Hash.cpp
 *
 *  Created on: 8/4/2016
 *      Author: alu4924
 */


#include "Hash.cpp"

using namespace std;

template <class T>
Hash<T>::Hash(int N, int M):
pFD(new FuncDisp(N)),
pFE(new FuncExpl()),
pCeldas()
{
	for (int i = 0; i<N; i++){
		pCeldas[i] = new Celda(M);
	}
}

template <class T>
bool Hash<T>::insertar(const T &k){
	bool insertado = false;
	int intento = 0;
	int pos = pFD->h(k);
	while (!insertado or !llena()){
		insertado = pCeldas[pos]->insertar(k);
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


