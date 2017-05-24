/*	Name project:	Punteros
	Date:			May, 24th, 2017
	Developer:		Luis Noe Tejaxún Quisque, Carnet: 1990-16-16820, Key: 1
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int main() {
    int edad[3];
    int *direccionEdad[3];
    for (int i = 0; i < 3; i++) {
        cout << "Ingrese la edad " << (i+1) << ": "; cin >> edad[i];
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        direccionEdad[i] = &edad[i];
        cout << "Edad " << (i+1) << ": " << *direccionEdad[i] << " Direccion: " << direccionEdad[i] << endl;
    }
    cin.get();
}