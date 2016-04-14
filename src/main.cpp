
#include <iostream>
#include <fstream>
#include <random>
#include "Hash.hpp"
#include "DNI.hpp"

using namespace std;

int main(void) {
	DNI *vector;
	int nceldas = 10;
	int npos = 5;
	int fd = 1;
	int fe = 1;
	double fdeCarga;
	int nPrueba = 10;
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

//Generar vector aleatorio de dni
	int tamVector = fdeCarga * nceldas * npos;
	vector = new DNI[2 * tamVector];

	vector = new DNI[tamVector];
	for (int i = 0; i < 2 * tamVector; i++) {

		int aux = (rand() % 50000000) + 30000000;
		vector[i] = aux;
	}
	Hash<DNI> miHash(npos, nceldas, fd, fe);

	for (int i = 0; i < tamVector; i++) {
		miHash.insertar(vector[i]);
	}
	string fDisp;
	string fExpl;
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

	cout << "Celdas   Bloques   Exploracion   Dispersion   Carga   Prueba"
			<< endl;
	cout << nceldas << "        " << npos << "       " << fExpl << "         "
			<< fDisp << "       " << fdeCarga << "      " << nPrueba << endl;

	//prueba de búsqueda
	int maximoBus = 0;
	int minimoBus = 1000000000;
	int mediaBus = 0;

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
		mediaBus += aux;
	}
	float mediaBusF = (float)mediaBus / (float)nPrueba;

	//prueba de insersion

	int maximoInsert = 0;
	int minimoInsert = 1000000000;
	int mediaInsert = 0;

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
		mediaInsert += aux;
	}
	float mediaInsertF = (float)mediaInsert / (float)nPrueba;

	cout << "             Número de comparaciones  "<< endl;
	cout << "           Mínimo    Medio     Máximo "<< endl;
	cout << "Búsqueda   " << minimoBus << "         " << mediaBusF << "         "
			<< maximoBus << endl;
	cout << "Inserción  " << minimoInsert << "         " << mediaInsertF
			<< "         " << maximoInsert << endl;

	return 0;

}
