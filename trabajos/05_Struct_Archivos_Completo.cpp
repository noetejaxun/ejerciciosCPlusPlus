/*	Name project:	Struct & data, (Buscar, Modificaciones, Eliminaciones)
	Date:			April, 28th, 2017
	Developer:		Luis Noe Tejaxún Quisque, Carnet: 1990-16-16820, Key: 1
*/

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
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

// Estructura para almacenar los datos de un numero de carnet.
struct Carnet {
	int carrera;
	int year;
	int carnet;
};

// Estructura para almacenar los datos de un estudiante.
struct Datos {
	Carnet carnetEstudiante;
	char nombre[50];
	int primerParcial;
	int segundoParcial;
	int zona;
	int proyectoFinal;
	int examenFinal;
	int notaFinal;
	bool aprobo;
};
Datos estudiante;
char auxAprobo[10];

void Mostrar_Encabezado();
void Mostrar_Datos_Consola(int);

void Ingresar_Datos();
void Guardar_Datos();
void Mostrar_Datos();
void Buscar_Datos();
void Modificar_Datos();
void Eliminar_Datos();

// Ingreso de un numero de carnet (ej. 1990 16 16820).
Carnet Ingreso_Carnet() {
	cin >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
	return estudiante.carnetEstudiante;
}

// Comprobacion que nota sea positiva y en un rango.
bool notaValida(int nota, int notaValida) {
	if (nota < 0) { return false; }
	if (nota > notaValida) { return false; }
	else { return true; }
}

// Comprobación si una cadena es realmente una cadena de texto.
bool esCadena(char cadena[50]){
	int i = 0;
	while (cadena[i]) {
		if (!isalpha(cadena[i])) { return false; }
		i++;
	}
	return true;
}

// Comprobacion si un numero ingresado, es realmente un numero.
bool esNumero(char numero[20]) {
	int i = 0;
	if (numero[0] == '+' || numero[0] == '-') { i = 1; }
	while (numero[i]) {
		if (!isdigit(numero[i])) { return false; }
		i++;
	}
	return true;
}

// Comprobacion si aprobo o no un estudiante
bool aprobo(int sumaNotas) {
	if (sumaNotas > 60) { return true; }
	else { return false; }
}

// Ingreso de una nota valida
int Ingreso_Nota(char mensaje[50], int nota_valida) {
	char entrada[20];
	bool continuar = false;
	int nota;

	do {
		cout << mensaje;
		cin.getline(entrada, 20);
		if (!esNumero(entrada)) { cout << "No es un numero, vuelva a intentar nuevamente." << endl; continuar = true; continue; }
		else { nota = atoi(entrada); continuar = false; }
		if (!notaValida(nota, nota_valida)) { cout << "El rango de la nota esta entre 0 y " << nota_valida << endl; continuar = true; }
	} while (continuar == true);
	return nota;
}

// Proceso para ingreso de datos
void Ingresar_Datos() {
	system("cls");
	cout << "INGRESO DE DATOS" << endl << endl;
	cout << "Carnet: "; estudiante.carnetEstudiante = Ingreso_Carnet(); cin.ignore();
	ingrese_nombre:
	cout << "Nombre: ";  cin.getline(estudiante.nombre, 50);
	if (!esCadena(estudiante.nombre)) { cout << "No es una cadena valida, vuelve a intentar" << endl; goto ingrese_nombre; } 
	
	estudiante.primerParcial  = Ingreso_Nota("Primer parcial: ", 10);
	estudiante.segundoParcial = Ingreso_Nota("Segundo parcial: ", 20);
	estudiante.zona			  = Ingreso_Nota("Zona: ", 20);
	estudiante.proyectoFinal  = Ingreso_Nota("Proyecto final: ", 25);
	estudiante.examenFinal	  = Ingreso_Nota("Examen final: ", 25 );
	estudiante.notaFinal	  = estudiante.primerParcial + estudiante.segundoParcial + estudiante.zona + estudiante.proyectoFinal + estudiante.examenFinal;
	estudiante.aprobo		  = aprobo(estudiante.notaFinal);
	system("cls");
	Guardar_Datos();
	cout << "Registro guardado correctamente, presiona enter para continuar";
	cin.get();
}

// Proceso que almacena los datos ingresados en un archivo "datos.txt"
void Guardar_Datos() {
	ofstream escribir;
	escribir.open("datos.txt", ios::app);
	escribir << estudiante.carnetEstudiante.carrera << " " << estudiante.carnetEstudiante.year << " " << estudiante.carnetEstudiante.carnet;
	escribir << " " << estudiante.nombre;
	escribir << " " << estudiante.primerParcial;
	escribir << " " << estudiante.segundoParcial;
	escribir << " " << estudiante.zona;
	escribir << " " << estudiante.proyectoFinal;
	escribir << " " << estudiante.examenFinal;
	escribir << " " << estudiante.notaFinal;
	if (estudiante.aprobo) { escribir << " Aprobo" << endl; } 
	else { escribir << " Reprobo" << endl; }
	escribir.close();
}

// gotoxy
void gotoxy(int x, int y) {
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD posicion;
	posicion.X = x;
	posicion.Y = y;
	SetConsoleCursorPosition(consola, posicion);
}

// Proceso unicamente para mostrar un encabezado
void Mostrar_Encabezado() {
	int y = 2;
	gotoxy(1, y); cout << "Carnet";
	gotoxy(20, y); cout << "Nombre";
	gotoxy(40, y); cout << "P. 1";
	gotoxy(52, y); cout << "P. 2";
	gotoxy(64, y); cout << "Zona";
	gotoxy(76, y); cout << "Pr. Fn.";
	gotoxy(88, y); cout << "Ex. Fn";
	gotoxy(100, y); cout << "Nota Fn";
	gotoxy(112, y); cout << "Aprobo/Reprobo" << endl;
	for (int x = 1; x <= 125; x++) { gotoxy(x, y+1); cout << "-"; }
}

// Proceso para mostrar los datos en consola
void Mostrar_Datos_Consola(int y) {
	gotoxy(1, y); cout << estudiante.carnetEstudiante.carrera << "-" << estudiante.carnetEstudiante.year << "-" << estudiante.carnetEstudiante.carnet;
	gotoxy(20, y); cout << estudiante.nombre;
	gotoxy(40, y); cout << estudiante.primerParcial;
	gotoxy(52, y); cout << estudiante.segundoParcial;
	gotoxy(64, y); cout << estudiante.zona;
	gotoxy(76, y); cout << estudiante.proyectoFinal;
	gotoxy(88, y); cout << estudiante.examenFinal;
	gotoxy(100, y); cout << estudiante.notaFinal;
	gotoxy(112, y); cout << auxAprobo << endl;
}

// Proceso que muestra los datos guardados en el archivo "datos.txt"
void Mostrar_Datos() {
	int y = 4;
	system("cls");
	ifstream mostrar("datos.txt", ios::in);
	if (mostrar.good()) {
		Mostrar_Encabezado();
		while (!mostrar.eof()) {
			mostrar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
			mostrar >> estudiante.nombre >> estudiante.primerParcial >> estudiante.segundoParcial >> estudiante.zona >> estudiante.proyectoFinal >> estudiante.examenFinal;
			mostrar >> estudiante.notaFinal >> auxAprobo;
			if (!(strcmp(auxAprobo, "") == 0)) {
				Mostrar_Datos_Consola(y);
				y++;
			}
		}
		for (int x = 1; x <= 125; x++) { gotoxy(x, y); cout << "-"; }
	}
	else { cout << "El archivo no ha cargado correctamente, o no ha ingresado algun registro todavia :)"; }
	mostrar.close();
	cin.get();
}

// Proceso para buscar por medio de nombre o numero de carnet
void Buscar_Datos() {
	system("cls");
	int y, opcion;
	char buscar_nombre[50], Opcion[20];
	bool encontrado = false;

	do {
		system("cls");
		cout << "Que desea hacer?" << endl;
		cout << endl;
		cout << "1...Buscar por nombre" << endl;
		cout << "2...Buscar por carnet" << endl;
		cout << "3...Salir de la busqueda" << endl;
		escoja_opcion:
		cout << endl << "Escoja una opcion: ";
		cin.getline(Opcion, 20);
		if (!esNumero(Opcion)) { cout << "Lo que ingresaste no fue un numero, vuelve a intentar nuevamente." << endl; goto escoja_opcion; }
		else { opcion = atoi(Opcion); }

		switch (opcion) {
			case 1: { // Busqueda por nombre
				system("cls");
				cout << "Ingresa el nombre a buscar: ";
				cin.getline(buscar_nombre, 50);
				ifstream buscar("datos.txt", ios::in);
				if (buscar.good()) {
					encontrado = false; y = 4;
					while (!buscar.eof()) {
						buscar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
						buscar >> estudiante.nombre >> estudiante.primerParcial >> estudiante.segundoParcial >> estudiante.zona >> estudiante.proyectoFinal >> estudiante.examenFinal;
						buscar >> estudiante.notaFinal >> auxAprobo;
						if (strcmp(buscar_nombre, estudiante.nombre) == 0) {
							Mostrar_Encabezado();
							Mostrar_Datos_Consola(y);
							y++;
							encontrado = true;
						}
					}
					if (!encontrado) { cout << "No se encontro el dato buscado."; }
				}
				else { cout << "El archivo no ha cargado correctamente, o no ha ingresado algun registro todavia :)"; }
				cin.get();
				buscar.close();
				break;
			}
			case 2: { // Busqueda por carnet
				ifstream buscar("datos.txt", ios::in);
				int carnet_buscado, carnet_encontrado;
				Carnet busqueda_carnet;
				if (buscar.good()) {
					system("cls");
					cout << "Ingresa el numero de carnet: ";
					cin >> busqueda_carnet.carrera >> busqueda_carnet.year >> busqueda_carnet.carnet;
					carnet_buscado = busqueda_carnet.carrera + busqueda_carnet.year + busqueda_carnet.carnet;

					encontrado = false; y = 4;
					while (!buscar.eof()) {
						buscar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
						buscar >> estudiante.nombre >> estudiante.primerParcial >> estudiante.segundoParcial >> estudiante.zona >> estudiante.proyectoFinal >> estudiante.examenFinal;
						buscar >> estudiante.notaFinal >> auxAprobo;

						carnet_encontrado = estudiante.carnetEstudiante.carrera + estudiante.carnetEstudiante.year + estudiante.carnetEstudiante.carnet;
						if (carnet_buscado == carnet_encontrado) {
							Mostrar_Encabezado(); Mostrar_Datos_Consola(y); encontrado = true;
						}
					}
					if (!encontrado) { cout << "No se encontro el dato buscado."; }
				}
				else { cout << "El archivo no ha cargado correctamente, o no ha ingresado algun registro todavia :)"; }
				cin.ignore();
				cin.get();
				buscar.close();
				break;
			}
		}
	} while (opcion != 3);
}

// Proceso para modificacion de datos
void Modificar_Datos() {
	Carnet buscar_carnet;
	char Opcion[10];
	int carnet_encontrado = 0, carnet_buscado = 0, opcion = 0;
	ifstream modificar;
	ofstream temporal;
	bool encontrado = false;

	modificar.open("datos.txt", ios::in);
	temporal.open("temporal.txt", ios::app);

	if (modificar.good() && temporal.good()) {

		cout << "Ingrese el numero de carnet del alumno: ";
		buscar_carnet = Ingreso_Carnet();
		cin.ignore();
		carnet_buscado = buscar_carnet.carrera + buscar_carnet.year + buscar_carnet.carnet;
		modificar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;

		while (!modificar.eof()) {
			modificar >> estudiante.nombre >> estudiante.primerParcial >> estudiante.segundoParcial >> estudiante.zona >> estudiante.proyectoFinal >> estudiante.examenFinal;
			modificar >> estudiante.notaFinal >> auxAprobo;
			carnet_encontrado = estudiante.carnetEstudiante.carrera + estudiante.carnetEstudiante.year + estudiante.carnetEstudiante.carnet;
			if (carnet_buscado == carnet_encontrado) {
				do {
					encontrado = true;
					Mostrar_Encabezado();
					Mostrar_Datos_Consola(4);
					cout << endl << "Que desea modificar?" << endl;
					cout << endl << "1...Carnet" << endl;
					cout << "2...Nombre" << endl;
					cout << "3...Parcial 1" << endl;
					cout << "4...Parcial 2" << endl;
					cout << "5...Zona" << endl;
					cout << "6...Proyecto Final" << endl;
					cout << "7...Examen Final" << endl;
					cout << "8...Salir" << endl << endl << endl;
					escoger_opcion:
					cout << "Escoja una opcion: ";
					cin.getline(Opcion, 10);
					if (!esNumero(Opcion)) { cout << "Lo que ingresaste no fue un numero, vuelve a intentar nuevamente." << endl; goto escoger_opcion; }
					else { opcion = atoi(Opcion); }

					switch (opcion) {
						case 1: { // Modifica el carnet
							cout << endl << "Ingrese el nuevo carnet del alumno: ";
							estudiante.carnetEstudiante = Ingreso_Carnet();
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl; 
							cin.get();
							break;
						}
						case 2: { // Modifica el nombre
							ingrese_nombre:
							cout << endl << "Ingrese el nuevo nombre del alumno: ";
							cin.getline(estudiante.nombre, 50);
							if (!esCadena(estudiante.nombre)) { cout << "No es una cadena valida, vuelve a intentar" << endl; goto ingrese_nombre; }
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl;

							break;
						}
						case 3: { // Modifica el primer parcial
							estudiante.primerParcial = Ingreso_Nota("Primer parcial: ", 10);
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl;
							break;
						}
						case 4: { // Modifica el segundo parcial
							estudiante.segundoParcial = Ingreso_Nota("Segundo parcial: ", 20);
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl;
							break;
						}
						case 5: { // modifica la zona
							estudiante.zona = Ingreso_Nota("Zona: ", 20);
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl;
							break;
						}
						case 6: { // modifica el proyecto final
							estudiante.proyectoFinal = Ingreso_Nota("Proyecto final: ", 25);
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl;
							break;
						}
						case 7: { // modifica el examen final
							estudiante.examenFinal = Ingreso_Nota("Examen final: ", 25);
							cout << endl << "Registro modificado correctamente, presione enter para seguir modificando :)" << endl;
							break;
						}
						case 8: {
							cout << "No fue modificado ningun registro :)";
							break;
						}
						default: {
							cout << "La opcion elegida no es valida.";
							opcion = 8;
						}
					}
					estudiante.notaFinal = estudiante.primerParcial + estudiante.segundoParcial + estudiante.zona + estudiante.proyectoFinal + estudiante.examenFinal;
					estudiante.aprobo = aprobo(estudiante.notaFinal);
					cin.get();
					system("cls");
				} while(opcion != 8);

				// Almacena datos modificados en un archivo temporal
				temporal << estudiante.carnetEstudiante.carrera << " " << estudiante.carnetEstudiante.year << " " << estudiante.carnetEstudiante.carnet;
				temporal << " " << estudiante.nombre << " " << estudiante.primerParcial << " " << estudiante.segundoParcial << " " << estudiante.zona << " " << estudiante.proyectoFinal << " " << estudiante.examenFinal;
				temporal << " " << estudiante.notaFinal;
				if (estudiante.aprobo) { temporal << " Aprobo" << endl; }
				else { temporal << " Reprobo" << endl; }

			} else {
				// Almacena resto de datos en el mismo archivo temporal pero sin ser modificados
				temporal << estudiante.carnetEstudiante.carrera << " " << estudiante.carnetEstudiante.year << " " << estudiante.carnetEstudiante.carnet;
				temporal << " " << estudiante.nombre << " " << estudiante.primerParcial << " " << estudiante.segundoParcial << " " << estudiante.zona << " " << estudiante.proyectoFinal << " " << estudiante.examenFinal;
				temporal << " " << estudiante.notaFinal << " " << auxAprobo << endl;
			}
			modificar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
		}if (!encontrado) { cout << "No se encontro el dato buscado."; cin.get(); }
	}
	else { cout << "El archivo no ha cargado correctamente, o no ha ingresado algun registro todavia :)"; cin.get(); }

	modificar.close();
	temporal.close();
	remove("datos.txt"); // Elimina el archivo "datos.txt"
	rename("temporal.txt", "datos.txt"); // Cambia de nombre al archivo "temporal.txt" a "datos.txt"
}

// Proceso para eliminacion de registros
void Eliminar_Datos() {
	Carnet buscar_carnet;
	char Opcion[10];
	int carnet_encontrado = 0, carnet_buscado = 0, opcion = 0;
	ifstream eliminar;
	ofstream temporal;
	bool encontrado = false;

	eliminar.open("datos.txt", ios::in);
	temporal.open("temporal.txt", ios::app);

	if (eliminar.good() && temporal.good()) {

		cout << "Ingrese el numero de carnet a eliminar: ";
		buscar_carnet = Ingreso_Carnet();
		cin.ignore();
		carnet_buscado = buscar_carnet.carrera + buscar_carnet.year + buscar_carnet.carnet;

		eliminar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
		while (!eliminar.eof()) {
			eliminar >> estudiante.nombre >> estudiante.primerParcial >> estudiante.segundoParcial >> estudiante.zona >> estudiante.proyectoFinal >> estudiante.examenFinal;
			eliminar >> estudiante.notaFinal >> auxAprobo;
			carnet_encontrado = estudiante.carnetEstudiante.carrera + estudiante.carnetEstudiante.year + estudiante.carnetEstudiante.carnet;
			if (carnet_buscado == carnet_encontrado) {
				encontrado = true;
				Mostrar_Encabezado();
				Mostrar_Datos_Consola(4);
				cout << endl << "Realmente desea eliminar el registro?" << endl;
				cout << endl << "1...Si" << endl;
				cout << "2...No" << endl;
				escoger_opcion:
				cout << "Escoja una opcion: ";
				cin.getline(Opcion, 10);
				if (!esNumero(Opcion)) { cout << "Lo que ingresaste no fue un numero, vuelve a intentar nuevamente." << endl; goto escoger_opcion; }
				else { opcion = atoi(Opcion); }
				if (opcion != 1) {
					temporal << estudiante.carnetEstudiante.carrera << " " << estudiante.carnetEstudiante.year << " " << estudiante.carnetEstudiante.carnet;
					temporal << " " << estudiante.nombre << " " << estudiante.primerParcial << " " << estudiante.segundoParcial << " " << estudiante.zona << " " << estudiante.proyectoFinal << " " << estudiante.examenFinal;
					temporal << " " << estudiante.notaFinal << " " << auxAprobo << endl;
				}
				if (opcion == 1) { cout << "Registro eliminado correctamente" << endl; cin.get(); }
			}
			else {
				// Almacena resto de datos en el mismo archivo temporal pero sin ser modificados
				temporal << estudiante.carnetEstudiante.carrera << " " << estudiante.carnetEstudiante.year << " " << estudiante.carnetEstudiante.carnet;
				temporal << " " << estudiante.nombre << " " << estudiante.primerParcial << " " << estudiante.segundoParcial << " " << estudiante.zona << " " << estudiante.proyectoFinal << " " << estudiante.examenFinal;
				temporal << " " << estudiante.notaFinal << " " << auxAprobo << endl;
			}
			eliminar >> estudiante.carnetEstudiante.carrera >> estudiante.carnetEstudiante.year >> estudiante.carnetEstudiante.carnet;
		} if (!encontrado) { cout << "No se encontro el dato buscado."; cin.get(); }
	}
	else { cout << "El archivo no ha cargado correctamente, o no ha ingresado algun registro todavia :)"; cin.get(); }
	estudiante.carnetEstudiante.carrera = 0;
	estudiante.carnetEstudiante.year = 0;
	estudiante.carnetEstudiante.carnet = 0;
	eliminar.close();
	temporal.close();
	remove("datos.txt"); // Elimina el archivo "datos.txt"
	rename("temporal.txt", "datos.txt"); // Cambia de nombre al archivo "temporal.txt" a "datos.txt"
}

int main() {
	char Opcion[20];
	int  opcion;
	do {
		system("cls");
		cout << "Que desea hacer?" << endl;
		cout << endl << "1...Ingresar registro" << endl;
		cout << "2...Mostrar registros" << endl;
		cout << "3...Buscar registro" << endl;
		cout << "4...Modificar registro" << endl;
		cout << "5...Eliminar registro" << endl;
		cout << "6...Salir" << endl << endl << endl;
		escoger_opcion:
		cout << "Escoja una opcion: ";
		cin.getline(Opcion, 20);
		if (!esNumero(Opcion)) { cout << "Lo que ingresaste no fue un numero, vuelve a intentar nuevamente." << endl; goto escoger_opcion; }
		else { opcion = atoi(Opcion); }

		system("cls");
		switch (opcion) {
			case 1: {
				cout << "DATOS DEL ALUMNO" << endl << endl;
				Ingresar_Datos();
				break;
			}
			case 2: {
				Mostrar_Datos();
				break;
			}
			case 3: {
				Buscar_Datos();
				break;
			}
			case 4: {
				Modificar_Datos();
				break;
			}
			case 5: {
				Eliminar_Datos();
				break;
			}
		}
	} while (opcion != 6);
	return 0;
}