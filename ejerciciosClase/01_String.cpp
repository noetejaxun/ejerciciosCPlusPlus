//	BUFFER DE ENTRADA
//	Solucionando con una variable tipo STRING
//	"\n" simboliza un salto de linea, o sea, cuando presionamos enter.

#include <iostream>
#include <string> // Agregando libreria string

using namespace std;

int main () {
	int cheque;
	string nombre; // cambiamos el tipo de variable de char a string
	cout << "Ingrese numero de cheque: ";
	cin >> cheque;
	cout << "Ingrese nombre: ";
	cin.ignore(); // eliminamos el ultimo caracter ingresado, (en este caso: "\n")
	getline(cin, nombre); // pedimos la entrada de texto

	cout << "Los datos ingresados son: " << endl << endl;
	cout << "Numero de cheque: " << cheque << endl;
	cout << "Nombre: " << nombre << endl;
	//system(pause);
	return 0;
}