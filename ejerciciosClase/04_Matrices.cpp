// Demostracin de creacion de una matriz

#include <iostream>

using namespace std;

int main() {
	// Declaracion de una matriz (tipo nombre[filas][columnas])
	int notas[3][5];

	int f, c;
	// Recorrer una matriz (Ingresando valores a las filas y columnas)
	cout << "Ingrese 15 notas finales:" << endl;
	for (f = 0; f < 3 ; f++) { // ciclo para el control de las filas
		for (c = 0; c < 5 ; c++) { // ciclo para el control de las columnas
			cin >> notas[f][c];
		}
	}

	// Mostrar los valores de una matriz en forma tabular
	cout << "Las notas ingresadas fueron:" << endl;
	for (f = 0; f < 3 ; f++) {
		for (c = 0; c < 5 ; c++) {
			cout << notas[f][c] << "\t";
		}
		cout << endl;
	}
}