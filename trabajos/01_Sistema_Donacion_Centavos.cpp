/*	Date:			March, 9th. 2017
	Developer:		Noe Tejaxun
	Description:	Permite el ingreso de datos de un cheque, Numero de cheque, fecha dd/mm/yy, nombre,
					monto del cheque, y a traves del monto, resta los centavos de cada cheque cobrado
					y muestra en pantalla el total de cheques recaudados, el total de la suma de
					los montos, el total de centavos. (Sistema desarrollado en Ubuntu, el parametro 
					"clear" que estan dentro de system(), para windows debe reemplazar por "cls").
*/

//#include "stdafx.h" // descomentar si esta en Vicual c++
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	//DECLARACION DE VARIABLES
	int numeroCheque = 0, montoEntero = 0, chequesRecaudados = 0, montoTotalSinCentavos = 0, cambiarCheque = 0;
	double monto  = 0, montoTotal = 0, centavosTotales = 0, centavos = 0;
	char date[50], nombre[100];
	bool salir = true;

	while(salir) { // TODO EL CODIGO DENTRO DE WHILE, SE REPETIRA HASTA QUE LA VARIABLE salir == false

		//VALIDACIONES DE ENTRADA
		ingreseNumeroCheque:
		cout << "Numero de Cheque: ";
		cin >> numeroCheque;
		if (cin.fail()) { // Comprueba si la entrata tiene un error
			system("clear"); // En windows, reemplazar "clear" por "cls".
			cout << "Error: No es un numero, intente nuevamente." << endl; // muestra mensaje si es que existe un error
			cin.clear(); // limpia la entrada en caso de error
			cin.ignore(); // ignora los posibles errores.
			goto ingreseNumeroCheque; // regresa a ingreseNumeroCheque:
		} else if (numeroCheque < 0) {
			cout << "Ingrese numeros positivos" << endl; // condicion en caso de numeros negativos
			goto ingreseNumeroCheque; // en caso de negativos, regresa a ingreseNumeroCheque:
		}

		cout << "Fecha: ";
		cin.ignore(); // Buffer de entrada, investigar sobre el tema.
		cin.getline(date, 50); // forma de capturar una linea de texto en c++

		cout << "Nombre: ";
		cin.ignore();
		cin.getline(nombre, 100);

		ingreseMonto:
		cout << "Monto del cheque: ";
		cin >> monto;
		if (cin.fail()) {
			cout << "Error: No es un numero, intente nuevamente." << endl;
			cin.clear();
			cin.ignore();
			goto ingreseMonto;
		} else if (monto < 0) {
			cout << "Ingrese cantidades positivas" << endl;
			goto ingreseMonto;
		}

		// CALCULO DE CANTIDADES
		montoTotal = montoTotal + monto;
		montoEntero = monto;
		centavos = monto - montoEntero;
		montoTotalSinCentavos = montoTotalSinCentavos + montoEntero;
		centavosTotales = centavosTotales + centavos;
		chequesRecaudados++;

		// OPCION SALIR
		deseaSalir:
		cout << "\nCambiar nuevo Cheque?" << endl << "0. Si" << endl << "1. No" << endl;
		cin.ignore();
		cin >> cambiarCheque;
		if (cin.fail()) {
			cout << "Error: caracter no valido" << endl;
			cin.clear();
			cin.ignore();
			goto deseaSalir;
		}
		if (cambiarCheque == 1) {
			salir = false;
		} else if(cambiarCheque == 0) {
			salir = true;
		} else {
			cout << "Error: opcion no valida" << endl;
			goto deseaSalir;
		}
		system("clear"); // En windows, reemplazar "clear" por "cls".
	}
	
	// IMPRIME EN PANTALLA
	cout << "Cantidad de cheques pagados: \t\t" << chequesRecaudados << endl;
	cout << "Total de montos de cheques: \t\t" << montoTotal <<endl;
	cout << "Total centavos recaudados: \t\t" << centavosTotales << endl;
	cout << "Total de dinero pagado a los clientes: \t" << montoTotalSinCentavos << endl;
	cin.get();
	cin.get();
	return 0;
}