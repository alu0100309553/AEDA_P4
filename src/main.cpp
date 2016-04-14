/*
 * Main.cpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#include <iostream>
#include <fstream>
#include <random>
#include "Hash.hpp"
#include "DNI.hpp"

using namespace std;

int main(void) {
	DNI *vector;      		//Puntero a vector de DNI
	int nceldas = 5;		//Número de celdas de la tabla
	int npos = 10;			//Número de posiciones de la tabla
	int fd = 1;				//Función de dispersión
	int fe = 1;				//Función de exploración
	double fdeCarga;		//Factor de carga
	int nPrueba = 10;		//Número de pruebas
	int tamVector;			//Tamaño del vector de dni de prueba
	int maximoBus = 0;		//Variables para el test de búsqueda
	int minimoBus = 1000000000;
	int mediaBusAcum = 0;
	float mediaBusF;
	int maximoInsert = 0;	//Variables para el test de inserción
	int minimoInsert = 1000000000;
	int mediaInsertAcum = 0;
	float mediaInsertF = 0;
	string fDisp;
	string fExpl;

	//Petición de los parámetros del test
	cout << "*****DEFINICION DEL PROBLEMA*****" << endl;
	cout << "**Número de posiciones de la tabla:" << endl;
	cin >> npos;
	cout << "**Número de celdas en cada posicion:" << endl;
	cin >> nceldas;
	cout << "**Indique el tipo de funcion de dispersion:" << endl;
	cout << "  - 1 Módulo." << endl;
	cout << "  - 2 Pseudo Aleatorio." << endl;
	cout << "  (Módulo en otro caso)" << endl;
	cin >> fd;
	cout << "**Indique el tipo de funcion de exploración:" << endl;
	cout << "  - 1 Lineal." << endl;
	cout << "  - 2 Cuadrática." << endl;
	cout << "  - 3 Dispersion Doble." << endl;
	cout << "  - 4 Re-Hashing." << endl;
	cout << "  (Lineal en otro caso)" << endl;
	cin >> fe;
	cout << "**Indique el factor de carga para la prueba:" << endl;
	cin >> fdeCarga;
	cout << "**Indique el numero de pruebas a realizar:" << endl;
	cin >> nPrueba;

	//Generar vector aleatorio de DNI para el test indicado
	tamVector = fdeCarga * nceldas * npos;
	vector = new DNI[2 * tamVector];
	vector = new DNI[tamVector];

	//Asignación de valores de DNI de manera aleatoria
	for (int i = 0; i < 2 * tamVector; i++) {
		int aux = (rand() % 50000000) + 30000000;
		vector[i] = aux;
	}

	//Creación de la tabla con los parámetros indicados
	Hash<DNI> miHash(npos, nceldas, fd, fe);

	//Insersión de la mitad de los DNI generados en la tabla
	for (int i = 0; i < tamVector; i++) {
		miHash.insertar(vector[i]);
	}

	//Conversión del tipo de Función de exploración a string
	switch (fe) {
	case 1:
		fExpl = "Lineal";
		break;
	case 2:
		fExpl = "Cuadrática";
		break;
	case 3:
		fExpl = "Doble";
		break;
	case 4:
		fExpl = "Re-Hashing";
		break;
	default:
		fExpl = "Lineal";
	}

	//Conversión del tipo de Función de dispersión a string
	switch (fd) {
	case 1:
		fDisp = "Módulo";
		break;
	case 2:
		fDisp = "Aleatoria";
		break;
	default:
		fDisp = "Módulo";
	}

	//Presentación de parámetros de la prueba
	cout << "Celdas   Bloques   Exploracion   Dispersion   Carga   Prueba"<< endl;
	cout << nceldas << "        " << npos << "       " << fExpl << "       "<< fDisp << "       " << fdeCarga << "      " << nPrueba << endl;

	//Prueba de búsqueda
	for (int i = 0; i < nPrueba; i++) {
		int posVector = rand() % tamVector;
		miHash.resetContador();
		miHash.buscar(vector[posVector]);
		int aux = miHash.getContador();
		if (aux < minimoBus) {
			minimoBus = aux;
		};
		if (aux > maximoBus) {
			maximoBus = aux;
		};
		mediaBusAcum += aux;
	}
	mediaBusF = (float)mediaBusAcum / (float)nPrueba;

	//Prueba de insersion
	for (int i = 0; i < nPrueba; i++) {
		int posVector = (rand() % tamVector) + tamVector;
		miHash.resetContador();
		miHash.buscar(vector[posVector]);
		int aux = miHash.getContador();
		if (aux < minimoInsert) {
			minimoInsert = aux;
		};
		if (aux > maximoInsert) {
			maximoInsert = aux;
		};
		mediaInsertAcum += aux;
	}
	mediaInsertF = (float)mediaInsertAcum / (float)nPrueba;

	//Presentación de resultados de la prueba
	cout << "             Número de comparaciones  "<< endl;
	cout << "           Mínimo    Medio     Máximo "<< endl;
	cout << "Búsqueda   " << minimoBus << "         " << mediaBusF << "         "<< maximoBus << endl;
	cout << "Inserción  " << minimoInsert << "         " << mediaInsertF<< "         " << maximoInsert << endl;

	return 0;

}
