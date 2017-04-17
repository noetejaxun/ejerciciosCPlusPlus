//	Name: 			Procedimientos
//	Date:			March, 25th, 2017
// 	Description:	Pertmite hacer desmostración del uso de procedimientos, ene este caso resolver suma, resta, multiplicacion y division


#include <iostream>
using namespace std;

void suma();	// Declaramos el procedimiento suma() a utilizar
void resta();	// Declaramos el procedimiento resta() a utilizar
void multiplicacion();
void division();

int main () {	// Función Principal
	int opcion;
	do {	// Estructura repetitiva
		system("cls");	// Limpiar pantalla
		cout << "Calculadora con procedimientos" << endl << endl;
		cout << "1....Suma " << endl;
		cout << "2....Resta " << endl;
		cout << "3....Multiplicacion " << endl;
		cout << "4....Division " << endl;
		cout << "5....Salir " << endl << endl;
		cout << "Seleccione  una Opcion ";
		cin >> opcion;
		switch(opcion) { // Selecciona una opcion junto con muchas 
			case 1: {
				suma();	// Invocar al  procedimiento Suma()
				break; // Finalizar case 3
			}	// Fin del case 1
			case 2: {
				resta(); // invocar al procedimiento Resta();
				break; // Finalizar case 2
			} // Fin del case 2
			case 3: {
				multiplicacion();
				break;
			}
			case 4: {
				division();
				break;
			}
		}
	} while (opcion != 5);
	return 0;

} // Fin del programa principal

void suma() {
	int cantidad1, cantidad2, resultado;
	system("cls");
	cout << "Suma de dos cantidades" << endl << endl;
	primerRegreso:
	cout << "Ingresa primera cantidad ";
	cin >> cantidad1;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Ingrese números enteros" << endl;
		goto primerRegreso;
	}
	segundoRegreso:
	cout << "Ingresa segunda cantidad ";
	cin >> cantidad2;
	resultado = cantidad1 + cantidad2;
	cout << endl << endl;
	cout << "El resultado de la suma es: " << resultado << endl;
	system("pause");
}

void resta() { // Inicio del procedimiento resta
	int cantidad1, cantidad2, resultado;
	system("cls");
	cout << "Suma de dos cantidades" << endl << endl;
	cout << "Ingresa primera cantidad ";
	cin >> cantidad1;
	cout << "Ingresa segunda cantidad ";
	cin >> cantidad2;
	resultado = cantidad1 - cantidad2;
	cout << endl << endl;
	cout << "El resultado de la resta es: " << resultado << endl;
	system("pause");
}

void multiplicacion() { // Inicio del procedimiento resta
	int cantidad1, cantidad2, resultado;
	system("cls");
	cout << "Suma de dos cantidades" << endl << endl;
	cout << "Ingresa primera cantidad ";
	cin >> cantidad1;
	cout << "Ingresa segunda cantidad ";
	cin >> cantidad2;
	resultado = cantidad1 * cantidad2;
	cout << endl << endl;
	cout << "El resultado de la multiplicacion es: " << resultado << endl;
	system("pause");
}

void division() { // Inicio del procedimiento resta
	int cantidad1, cantidad2, resultado;
	system("cls");
	cout << "Suma de dos cantidades" << endl << endl;
	cout << "Ingresa primera cantidad ";
	cin >> cantidad1;
	regreso:
	cout << "Ingresa segunda cantidad ";
	cin >> cantidad2;
	if (cantidad2 == 0)	{
		cout << "Ingrese numeros diferente de 0" << endl;
		goto regreso;
	}
	resultado = cantidad1 / cantidad2;
	cout << endl << endl;
	cout << "El resultado de la division es: " << resultado << endl;
	system("pause");
}