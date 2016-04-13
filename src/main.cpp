#include <iostream>
#include <fstream>

using namespace std;

#include "Hash.cpp"

int main(void)
{
	int i = 10;
	int j = 13 ;
	Hash<int> miHash(5, 5);
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
