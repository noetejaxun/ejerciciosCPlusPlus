#include <iostream>
#include <conio.h>

using namespace std;

struct listas {
	int numero;
	listas *elemento_a;
};

listas *elemento_c, *elemento_e;

void ingresar();
void buscar();
void eliminar();
void mostrar();
void circular();

void ingresar() {
	if (elemento_c == NULL) {
		elemento_c = new(listas);
		cout << "\nIngrese un dato a la lista: ";
		cin >> elemento_c->numero;
		elemento_c->elemento_a = NULL;
		cout << "\nPrimer dato ingresado correctamente!!!";
		getch();
	} else {
		elemento_e = new(listas);
		cout << "\nIngrese un dato a la lista: ";
		cin >> elemento_e->numero;
		cout << "\nDato ingresado correctamente!!!";
		getch();
		elemento_e->elemento_a = elemento_c;
		elemento_c = elemento_e;
	}
}

void buscar() {
	int buscar_dato, encontro = 0;
	if (elemento_c == NULL) {
		cout << "\n\nNo hay datos en la lista!!!";
		getch();
	} else {
		cout << "\nIngrese dato a buscar: "; cin >> buscar_dato;
		elemento_e = elemento_c;
		while (elemento_e != NULL) {
			if (buscar_dato == elemento_e->numero) {
				cout << "Dato encontrado: " << elemento_e->numero;
				encontro = 1;
				getch();
				break;
			} else {
				elemento_e = elemento_e->elemento_a;
			}
		}
		if (encontro == 0) {
			cout << "Lo siento, dato no encontrado!!!";
			getch();
		}
	}
}

void eliminar() {
	listas *elemento_anterior;
	int buscar_dato, encontro = 0;
	if (elemento_c == NULL) {
		cout << "\n\nNo hay datos en la lista!!!";
		getch();
	} else {
		cout << "\nIngrese dato a eliminar: "; cin >> buscar_dato;
		elemento_e = elemento_c;
		elemento_anterior = elemento_e;
		while (elemento_e != NULL){
			if (buscar_dato == elemento_e->numero) {
				cout << "Dato eliminado: " << elemento_e->numero << endl;
				if (elemento_e == elemento_c) {
					elemento_c = elemento_c->elemento_a;
				} else {
					elemento_anterior->elemento_a = elemento_e->elemento_a;
				}
				delete(elemento_e);
				encontro = 1;
				getch();
				break;
			} else {
				elemento_anterior = elemento_e;
				elemento_e = elemento_e->elemento_a;
			}
		}
		if (encontro == 0) {
			cout << "Lo siento, dato no encontrado!!!";
			getch();
		}
	}
}

void mostrar() {
	if (elemento_c == NULL) {
		cout << "\n\nNo hay datos en la lista!!!";
		getch();
	} else {
		cout << "\nLos datos de la lista dinamica son: " << endl << endl;
		elemento_e = elemento_c;
		while (elemento_e != NULL) {
			cout << elemento_e->numero << "\t";
			elemento_e = elemento_e->elemento_a;
		}
		cout << "\n\nPresione ENTER para finalizar";
		getch();
	}
}

void circular() {
	if (elemento_c == NULL) {
		cout << "\n\nNo hay datos en la lista!!!";
		getch();
	} else {
		cout << "\nLos datos de la lista dinamica son: " << endl << endl;
		elemento_e = elemento_c;
		while (elemento_e != NULL) {
			if (elemento_e->elemento_a == NULL) {
				elemento_e->elemento_a = elemento_c;
			} else {
				cout << elemento_e->numero << "\t";
				elemento_e = elemento_e->elemento_a;
			}
		}
		cout << "\n\nPresione ENTER para finalizar";
		getch();
	}
}

int main() {
	int opcion = 0;
	while (opcion != 6) {
		system("cls");
		cout << "LISTAS DINAMICAS" << endl << endl;
		cout << "1.....Ingresar datos a la lista" << endl;
		cout << "2.....Buscar datos en la lista" << endl;
		cout << "3.....Eliminar datos de la lista" << endl;
		cout << "4.....Lista circular" << endl;
		cout << "5.....Mostrar datos de la lista" << endl;
		cout << endl << "6.....Salir" << endl << endl;
		cout << "Seleccione su opcion: "; cin >> opcion;
		switch (opcion) {
			case 1: {
				ingresar();
				break;
			}
			case 2: {
				buscar();
				break;
			}
			case 3: {
				eliminar();
				break;
			}
			case 4: {
				circular();
				break;
			}
			case 5: {
				mostrar();
				break;
			}
		}
	}
    return 0;
}
