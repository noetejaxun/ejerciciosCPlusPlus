//	BUFFER DE ENTRADA
//	Solucionando el error, utilizando la variable de tipo CHAR

//	cin.ignore(); --> elimina el ultimo caracter ingresado, en este caso eliminaria la entrada enter que es "\n"

//	cin.getline(variable, posiciones); --> permite el ingreso de una linea de texto en pantalla, incluyendo espacios.

#include <iostream>

using namespace std;

int main () {
	int cheque;
	char nombre[30];
	cout << "Ingrese numero de cheque: ";
	cin >> cheque;
	cout << "Ingrese nombre: ";
	cin.ignore(); // eliminamos el ultimo caracter ingresado, (en este caso: "\n")
	cin.getline(nombre, 30); // pidiendo de la misma forma
	cout << "Los datos ingresados son: " << endl << endl;
	cout << "Numero de cheque: " << cheque << endl;
	cout << "Nombre: " << nombre << endl;
	//system(pause);
	return 0;
}