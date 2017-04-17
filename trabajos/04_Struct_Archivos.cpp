//	Name: 			Procedimientos
//	Date:			April, 15th, 2017
// 	Developer:		Luis Noe Tejaxún Quisque, Carnet: 1990-16-16820, Clave: 1
// 	Description:	Struct & data 

/*
	MODELO DE INGRESO DE REGISTRO DE DATOS:

	Carnet: 1990 16 16820	("El carnet debe tener tres numeros, separados por un espacio")
	Nombre : Noe
	Parcial 1 : 10			("La nota del parcial 1 esta entre el rango de 0 y 10")
	Parcial 2 : 20			("La nota del parcial 2 esta entre el rango de 0 y 20")
	Zona : 20				("La nota de la zona esta entre el rango de 0 y 20")
	Proyecto Final : 25		("La nota del proyecto final esta entre el rango de 0 y 25")
	Examen Final : 25		("La nota del examen final esta entre el rango de 0 y 25")
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

//																  Carrera Año Carnet
// Estructura de datos para el ingreso numero de carnet (Ejemplo: 1990    16  16820)
// En el ingreso del carnet se escriben los tres numeros, separados por un espacio (Ejemplo: 1990 16 16820, equivale a 1990-16-16820)
struct Datos_Carnet {
	int carrera;
	int year;
	int carnet;
};

// Estructura para datos de un estudiante
struct Datos {
	Datos_Carnet Carnet_Estudiante;
	char nombre[50];
	int parcial1;
	int parcial2;
	int zona;
	int proyectoFinal;
	int examenFinal;
	int notaFinal;
};

// Declaracion de un estudiante por medio del struct datos
Datos estudiante;
// Declaracion de un carnet de estudiante por medio del struct datosCarnet
Datos_Carnet Carnet_Estudiante;

// Procedimientos y funciones
void Ingreso_Datos();
void Mostrar_Datos();
bool aprobo(int);
bool validarNota(int, int);
Datos_Carnet Leer_Carnet();

// Funcion que valida las notas
bool validarNota(int nota, int notaValida) {
	if (nota < 0) {
		cout << "No se aceptan numeros negativos" << endl;
		return false;
	}
	if (nota > notaValida) {
		cout << "La nota ingresada esta fuera de rango, ingrese notas entre 0 y " << notaValida << endl;
		return false;
	} else {
		return true;
	}
}

// Funcion que valida si aprobo o reprobo un estudiante segun su nota
bool aprobo(int i) {
	if (i > 60) {
		return true;
	} else {
		return false;
	}
}

// funcion tipo datosCarnet, que lee el ingreso de un numero de carnet
Datos_Carnet Leer_Carnet() {
	cin >> Carnet_Estudiante.carrera >> Carnet_Estudiante.year >> Carnet_Estudiante.carnet;
	return Carnet_Estudiante;
}

// proceso de ingreso de datos
void Ingreso_Datos() {
	ofstream salida; // declaracion de un objeto ofstream llamado salida, para ell ingreso de datos en un archivo .txt
	salida.open("datos.txt", ios::app); // apertura de archivo llamado datos.txt, con el modo de apertura ios::app --> (donde las operaciones se realizan al final del archivo)
	
	// Pedimos al usuario el nombre
	cout << "Carnet: ";
	Carnet_Estudiante = Leer_Carnet(); // Asignamos los 3 valores enteros del numero de carnet del struc datosCarnet, separados por un espacio. (Ejemplo: 1990 16 16820)
	cout << "Nombre: ";
	cin.ignore();
	cin.getline(estudiante.nombre, 50);

	parcialUno:
	cout << "Parcial 1: ";
	cin >> estudiante.parcial1;
		if (!validarNota(estudiante.parcial1, 10)) { goto parcialUno; }
	parcialDos:
	cout << "Parcial 2: ";
	cin >> estudiante.parcial2;
		if (!validarNota(estudiante.parcial2, 20)) { goto parcialDos; }
	zone:
	cout << "Zona: ";
	cin >> estudiante.zona;
		if (!validarNota(estudiante.zona, 20)) { goto zone; }
	Proyecto_Final:
	cout << "Proyecto Final: ";
	cin >> estudiante.proyectoFinal;
		if (!validarNota(estudiante.proyectoFinal, 25)) { goto Proyecto_Final; }
	Examen_Final:
	cout << "Examen Final: ";
	cin >> estudiante.examenFinal;
		if (!validarNota(estudiante.examenFinal, 25)) { goto Examen_Final; }

	estudiante.notaFinal = (estudiante.parcial1 + estudiante.parcial2 + estudiante.zona + estudiante.proyectoFinal + estudiante.examenFinal);

	// Guardamos todos los datos obtenidos en el archivo datos.txt
	salida << Carnet_Estudiante.carrera << "-" << Carnet_Estudiante.year << "-" << Carnet_Estudiante.carnet;
	salida << "\t" << estudiante.nombre;
	salida << "\t\t" << estudiante.parcial1;
	salida << "\t" << estudiante.parcial2;
	salida << "\t" << estudiante.zona;
	salida << "\t" << estudiante.proyectoFinal;
	salida << "\t" << estudiante.examenFinal;
	salida << "\t" << estudiante.notaFinal;
	if (aprobo(estudiante.notaFinal)) {
		salida << "\t\tAprobo" << endl;
	} else {
		salida << "\t\tReprobo" << endl;
	}

	salida.close(); // Cerramos el archivo
	system("cls");
	cout << "Registro guardado con exito." << endl;
	cin.get();
	cin.get();
	system("cls");
}

void Mostrar_Datos() {
	ifstream entrada; // Creamos un objeto tipo ifstream llamado entrada, para la lectura de los datos del archivo
	entrada.open("datos.txt"); // abrimos el archivo datos.txt

	if (entrada.good()) { // Si el archivo carga correctamente
		char linea[255];
		cout << "DATOS GENERALES" << endl << endl;
		cout << "Carnet:\t\tNombre:\t\tP. 1\tP. 2\tZona\tPr.F.\tEx.F.\tNota F.\t\tAprobo/Reprobo" << endl;
		// Recorremos e imprimimos todas las lineas dell archivo "datos.txt"
		while (!entrada.eof()) {
			entrada.getline(linea, 255);
			cout << linea << endl;
		}
		entrada.close();
	} else { // Si el archivo no carga correctamente
		cout << "No ha ingresado algun registro todavia :)" << endl;
	}
	cin.get();
	cin.get();
	system("cls");
}

int main() {
	int opcion;
	do {
		system("cls");
		cout << "Que desea hacer?" << endl;
		cout << "1...Ingresar Datos" << endl;
		cout << "2...Mostrar Datos" << endl;
		cout << "3...Salir" << endl << endl;
		cout << "Escoja una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
			case 1: {
				cout << "DATOS DEL ALUMNO" << endl << endl;
				Ingreso_Datos();
				break;
			}
			case 2: {
				Mostrar_Datos();
				break;
			}
		}
	} while (opcion != 3);
	return 0;
}