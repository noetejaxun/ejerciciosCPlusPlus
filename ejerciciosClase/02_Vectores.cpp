// Demostracion de vectores

#include <iostream>

using namespace std;

int main() {
	// Declaracion de vectores (tipo nombre[Cantidad_Elementos])
	char nombres[5][40];
	int edades[5];

	// Recorrer uno o varios vectores (Ingreso de valores)
	for (int f = 0 ; f < 5 ; f++) {
		cout << "Ingrese nombre: ";
		cin.getline(nombres[f], 40);

		cout << "Ingrese edad: ";
		cin >> edades[f];
		cin.get();
	}
	cout << endl << endl;
	cout << "Personas mayores de edad.";
	cout << "\n";

	// Mostrar valores de un arreglo (Mostrando solo los mayores de edad)
	for (int i = 0; i < 5 ; ++i) {
		if (edades[i] >= 18) {
			cout << nombres[i] << " " << edades[i];
			cout << "\n";
		}
	}
	cin.get();
	return 0;
}