#include <iostream>
#include <stdlib.h> // Libreria para la funcion atoi() --> convierte tipo char a entero
using namespace std;

// Prototipo
bool esNumero(char);

// Funcion booleana que valida si una variable tipo char es un numero entero
bool esNumero(char numero[20]) {
    int i = 0; // indice de las posiciones de la variable tipo char llamada "numero" inicializada siempre en 0
    
    if (numero[0] == '-' || numero[0] == '+') { i = 1; } // Si encuentra los valores "+" o "-" al principio, los omite y continua recorriendo la variable char
    while (numero[i]) { // recorre todas las posiciones de un char
        if (!isdigit(numero[i])) { cout << "No es un numero, por favor vuelva a intentar\n"; return false; } /* Si uno de los caracteres no es un numero,
        la funcion isdigit(), comprueba si uno de los caracteres es un numero                                   muestra un mensaje y retorna un valor false */
        i++;
    }
    return true; /** Si ingresa un numero correcto, retornara el valor true **/
}

int main () {
    int numero = 0;
    char ingreseNumero[20];

	ingreso: /** etiqueta de retorno **/
	cout << "Ingrese un numero: ";
	cin.getline(ingreseNumero, 20); /** Pedimos el ingreso de un numero con una variable de tipo char **/
		if (!esNumero(ingreseNumero)) { goto ingreso; } else { numero = atoi(ingreseNumero); }  /** si no es un numero, retorna a la etiqueta ingreso, de lo contrario, si es un numero,
                                                                                                    le asigna el valor a una variable entera llamada numero convirtiendo el valor de la variable
                                                                                                    char ingreseNumero mediante la funcion atoi().**/
    cout << "El numero ingresado fue: " << numero << endl;
    return 0;
}