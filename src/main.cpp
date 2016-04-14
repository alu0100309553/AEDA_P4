

#include <iostream>
#include <fstream>
#include "Hash.hpp"
#include "DNI.hpp"

using namespace std;


int main(void)
{
	DNI *vector;
	int nceldas = 10;
	int npos = 5;
	int fd = 1;
	int fe = 1;
	double fdeCarga;
	int nPrueba = 10;
	cout << "*****DEFINICION DEL PROBLEMA*****"<< endl;
	cout << "**Número de posiciones de la tabla:"<< endl;
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
	int tamVector = 2 * fdeCarga * nceldas * npos;
	for (int i = 0 ; i < tamVector ; i++){


	}

	DNI i(30123456);
	DNI j(30123457);

	Hash<DNI> miHash(5, 5, 1, 1);
	if (miHash.insertar(j)){
		cout << "Lo inserto"<< endl;
	} else{
		cout << "no lo hizo"<< endl;
	}

	if (miHash.insertar(j)){
			cout << "Lo inserto de nuevo"<< endl;
		} else{
			cout << "no lo hizo"<< endl;
		}

	if (miHash.buscar(j)){
			cout << "Lo encontró"<< endl;
		} else{
			cout << "no lo encontro"<< endl;
		}

	if (miHash.buscar(i)){
				cout << "Lo encontró"<< endl;
			} else{
				cout << "no lo encontro"<< endl;
			}



	return 0;

}
