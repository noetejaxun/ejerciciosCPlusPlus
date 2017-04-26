// Validación de una nota

#include "stdafx.h"
#include <iostream>
using namespace std;

bool Nota_Valida(int, int); // Declaración de una función booleana que valida una nota que sea positiva y entre un rango.

bool Nota_Valida(int nota, int notaValida) { // El parametro "nota" será el que reciba la nota a evaluar y "notaValida" será la nota que validará

	if (nota < 0) { // Si la nota es menor a 0, retornara un valor falso 
		return false; //(el valor "false" nos servirá para decir que la nota no es valida)
	}
	if (nota > notaValida) { // Si la nota es mayor a la nota valida, retornara un valor falso 
		return false;
	}
	else { // de lo contrario, si la nota está en el rango de 0 y la notaValida, retornara un valor verdadero
		return true; //(el valor true nos servirá para decir que si es valida la nota)
	}
}

int main() {
	int nota;
	int notaValida = 10;

	ingreso_nota: // sentencia "ingreso_nota"
	cout << "Ingrese una nota entre 0 y " << notaValida << endl;
	cout << "Nota: ";
	cin >> nota;

	if (!Nota_Valida( nota, notaValida )) { // Si la nota no es valida, [ Si el valor retornado de la función es "false" ]
		cout << "\nLa nota no es valida." << endl;
		goto ingreso_nota; // retornará a la sentencia "ingreso_nota"
	}

	cout << endl;
	cout << "La nota valida ingresada fue: " << nota << endl;

	cin.get();
	cin.get();
    return 0;
}