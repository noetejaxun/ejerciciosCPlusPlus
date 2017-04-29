#include <iostream>

using namespace std;

bool esCadena(char cadena[50]){
    int i = 0;
    while (cadena[i]) { // Recorre una 
        if(!isalpha(cadena[i])) { // Si una de las letras no es una letra del alfabeto
            return false; //retornara el valor falso 
        } 
        i++;
    }
    return true;
}

int main () {
    char cadena[10];
    int i = 0;
    ingreso:
    cout << "Ingrese solo letras del abecedario: ";
    cin.getline(cadena, 10);

    if(!esCadena(cadena)) { // Si no es una cadena
        cout << "No es una cadena valida, intente nuevamente" << endl << endl;  
        goto ingreso;
    } else { // de lo contrario, si es una cadena
        cout << endl << "La cadena ingresada fue: " << cadena; }
    cin.get();
    
    return 0;
}