//	Name: 			struct
//	Date:			April, 8th, 2017

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	// Declaracion de una estructura de datos (Declaracion de un registro)
	struct ALUMNOS {
		int carnet;
		char nombre_alumno[30];
		int nota;
		float estatura;
	};

	// creacion de un vector llamado estudiante, con el tipo de datos struct ALUMNOS (Hacer uso de un registro)
	ALUMNOS estudiante[3];

	int i;
	cout << "Por favor, ingrese los datos que se le solicitan:" << endl << endl;
	for (i = 0; i < 3; i++) {
		cout << "Carnet: ";
		cin >> estudiante[i].carnet; // Asignamos valor a el No. de Carnet de la estructura de datos estudiante. (Hacemos referencia a la variable carnet)
		cout << "Nombre: ";
		cin.ignore();
		cin.getline(estudiante[i].nombre_alumno, 30); // Asignamos valor a el Nmbre de la estructura de datos estudiante. (Hacemos referencia a la variable nombre_alumno)
		cout << "Nota: ";
		cin >> estudiante[i].nota; // Asignamos valor a la nota de la estructura de datos estudiante. (Hacemos referencia a la variable nota)
		cout << "Estatura: ";
		cin >> estudiante[i].estatura; // Asignamos valor a la estatura de la estructura de datos estudiante. (Hacemos referencia a la variable estatura)
		cout << endl << endl;
	}

	cout << "\n\n********** LISTADO DE ALUMNOS ********\n\n";
	cout << "Carnet\tNombre\tNota\tEstatura";
	for (i = 0; i < 3; i++) {
		cout << "\n";
		cout << estudiante[i].carnet;
		cout << "\t";
		cout << estudiante[i].nombre_alumno;
		cout << "\t";
		cout << estudiante[i].nota;
		cout << "\t";
		cout << estudiante[i].estatura << endl << endl;
	}
	cin.get();
	cin.get();
    return 0;
}