

#include <iostream>
#include <fstream>
#include "Hash.cpp"
#include "DNI.hpp"

using namespace std;


int main(void)
{
	DNI i(30123456);
	DNI j(30123458);

	Hash<DNI> miHash(5, 5);
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
