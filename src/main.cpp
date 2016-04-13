#include <iostream>
#include <fstream>

using namespace std;

#include "Hash.cpp"

int main(void)
{
	int i = 10;
	int j = 13 ;
	Hash<int> miHash(10, 20);
	if (miHash.insertar(j)){
		cout << "Lo inserto"<< endl;
	} else{
		cout << "no lo hizo"<< endl;
	}
	return 0;

}
