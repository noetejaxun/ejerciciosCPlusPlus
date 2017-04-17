// Nombre: Procedimientos y vectores paralelos
// Permite el ingreso de datos de 5 estudiantes, calculando la nota final de cada uno, su promedio y muestra al final, el valor del promedio general.

#include <iostream>

using namespace std;

// Procedimientos
void ingresoAlumnos(int i);
void mostrarDatos(int i);
void aproboReprobo(int i);
void calculoNotas(int i);

// VARIABLES Y VECTORES GLOBALES
char nombre[5][50];
bool aprobo[5];
int carnet[5], parcialUno[5], parcialDos[5], zona[5], proyectoFinal[5], examenFinal[5], notaFinal[5], sumaNotasFinales;

void ingresoAlumnos(int i) {
	cout << "REGISTRO No. " << (i+1) << endl;
	// ENTRADAS
	cout << "Numero de Carnet: ";
	cin >> carnet[i];
	cout << "Nombre: ";
	cin.ignore();
	cin.getline(nombre[i], 50);
	cout << "Parcial No. 1: ";
	cin >> parcialUno[i];
	cout << "Parcial No. 2: ";
	cin >> parcialDos[i];
	cout << "Zona: ";
	cin >> zona[i];
	cout << "Proyecto Final: ";
	cin >> proyectoFinal[i];
	cout << "Examen Final: ";
	cin >> examenFinal[i];

	// PROCESOS
	calculoNotas(i);
	aproboReprobo(i);
	system("cls");
}

void calculoNotas(int i) {
	notaFinal[i] = parcialUno[i] + parcialDos[i] + zona[i] + proyectoFinal[i] + examenFinal[i];
	sumaNotasFinales = sumaNotasFinales + notaFinal[i];
}

void aproboReprobo (int i) {
	if (notaFinal[i] > 60) {
		aprobo[i] = true;
	} else {
		aprobo[i] = false;
	}
}

void mostrarDatos(int i) {
	cout << "Carnet: " << carnet[i] << "\t" << "Nombre: " << nombre[i] << "\t" << "Parcial 1: " << parcialUno[i] << "\t" << "Parcial 2: " << parcialDos[i] << "\t" << "Zona: " << zona[i] << "\t" << "Proy. Final: "  << proyectoFinal[i] << "\t" << "Examen Fianl: "  << examenFinal[i] << "\t" << "Nota Final: "  << notaFinal[i] << "\t";
	if (aprobo[i]) {
		cout << "Aprobo" << endl;
	} else {
		cout << "Reprobo" << endl;
	}
}

int main () {
	int opcion;
	do {
		system("cls");
		cout << "REGISTRO DE ALUMNOS" << endl << endl;
		cout << "1....Ingresar Datos " << endl;
		cout << "2....Mostrad Datos " << endl;
		cout << "3....Salir " << endl << endl;
		retrorno:
		cout << "Seleccione  una opcion ";
		cin >> opcion;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Ha introducido un valor invalido, intente nuevamente" << endl;
			goto retorno;
		}
		switch(opcion) {
			case 1: {
				system("cls");
				for (int i = 0; i < 5; ++i) {
					ingresoAlumnos(i);
				}
				break; 
			}
			case 2: {
				system("cls");
				for (int i = 0; i < 5; ++i) {
					mostrarDatos(i);
				}
				cout << endl << "Promedio General " << (sumaNotasFinales / 5.) << endl;
				cin.get();
				cin.get(); 
				break; 
			}
		}
	} while (opcion != 3);
}