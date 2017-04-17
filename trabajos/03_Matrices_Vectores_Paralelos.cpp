//	Name: 			Procedimientos
//	Date:			April, 6th, 2017
// 	Developer:		Luis Tejaxún
// 	Description:	Permite resolver el calculo de notas finales de 3 estudiantes y el promedio de notas finales, mostrando la nota final mayor y menor 

#include <iostream>
using namespace std;

void Ingreso_Alumnos();
void Mostrar_Datos();
void mensaje(int i);
void aproboReprobo(int i);
void mayorMenor();

int notas[3][5], notaFinal[3];
char nombres[3][50];
int f, c, sumaNotas =  0, sumaNotasFinales = 0;
int menor = 0, mayor = 0;
bool aprobo[3];

void mensaje(int i) {
    if (i == 0) {
        cout << "Primer parcial: ";
    } else if (i == 1) {
        cout << "Segundo parcial: ";
    } else if (i == 2) {
        cout << "Zona: ";
    } else if (i == 3) {
        cout << "Proyecto Final: ";
    } else if (i == 4) {
        cout << "Examen Final: ";
    }
}

void aproboReprobo (int i) {
	if (notaFinal[i] > 60) {
		aprobo[i] = true;
	} else {
		aprobo[i] = false;
	}
}

void Ingreso_Alumnos() {
    for (f = 0; f < 3 ; f++) {
        sumaNotas = 0;
        system("cls");
        cout << endl << "REGISTRO No. " << (f+1) << endl;
        cout << "Nombre: ";
        cin.ignore();
        cin.getline(nombres[f], 50);
		for (c = 0; c < 5 ; c++) {
			retorno:
            mensaje(c); // invoca a procedimiento mensaje() --> muestra un mensaje dependiendo la posicion de la columna
			cin >> notas[f][c];

			if (notas[f][c] < 0) {
				cout << "No se aceptan cantidades negativas" << endl;
				goto retorno;
			}

			if (c < 1) {
				if (notas[f][c] <= 10) {
					sumaNotas += notas[f][c];
				} else {
					cout << "Ingrese cantidades entre 0 y 10" << endl;
					notas[f][c] = 0;
					goto retorno;
				}
			} else if (c < 3) {
				if (notas[f][c] <= 20) {
					sumaNotas += notas[f][c];
				} else {
					cout << "Ingrese cantidades entre 0 y 20" << endl;
					notas[f][c] = 0;
					goto retorno;
				}
			} else if (c < 5) {
				if (notas[f][c] <= 25) {
					sumaNotas += notas[f][c];
				} else {
					cout << "Ingrese cantidades entre 0 y 25" << endl;
					notas[f][c] = 0;
					goto retorno;
				}
			}
		} // Fin ciclo anidado
        notaFinal[f] = sumaNotas; // calculo de notas por alumno
        sumaNotasFinales += notaFinal[f]; // calculo notas finales para el calculo del promedio
        aproboReprobo(f); // invoca a procedimiento aproboReprobo()
	} // Fin primer ciclo
}

void Mostrar_Datos() {
    cout << "DATOS DE CADA ESTUDIANTE" << endl << endl;
    cout << "Nombre\tPP\tSP\tZONA\tP Final\tE Final\tNota F\tAprobo/Reprobo" << endl;
    for (f = 0; f < 3 ; f++) {
		//	muestra los nombres
        cout << nombres[f] << "\t";
		//	muestra las cinco notas
		for (c = 0; c < 5 ; c++) {
			cout << notas[f][c] << "\t";
		}
		//	muestra nota final
        cout << notaFinal[f] << "\t";
		//	muestra si aprobo o reprobo
        if (aprobo[f]) {
            cout << "Aprobo" << endl;
        } else {
            cout << "Reprobo" << endl;
        }
	}
}

void mayorMenor() {
	//	Calculo nota mayor
	for(int i = 1; i < 3; i++){
        if(notaFinal[i] > notaFinal[mayor]){
			mayor = i;
        }
    }
	//	Calculo nota menor
    for(int i = 1; i < 3; i++){
        if(notaFinal[i] < notaFinal[menor]){
			menor = i;
        }
    }
	cout << "Nota mayor: " << nombres[mayor] << ", Nota: " << notaFinal[mayor] << endl;
	cout << "Nota menor: " << nombres[menor] << ", Nota: " << notaFinal[menor] << endl;
}

int main() {
    int opcion;
	do {
		system("cls");
		cout << "REGISTRO DE ALUMNOS" << endl << endl;
		cout << "1....Ingresar Datos " << endl;
		cout << "2....Mostrad Datos " << endl;
		cout << "3....Salir " << endl << endl;
		cout << "Seleccione  una opcion ";
		cin >> opcion;
		switch(opcion) {
			case 1: {
				system("cls");
                Ingreso_Alumnos(); // invoca a procedimiento Ingreso_Alumnos()
				break; 
			}
			case 2: {
				system("cls");
                Mostrar_Datos(); //	invoca a procedimiento Mostrar_Datos()
				cout << endl << "Promedio General: " << (sumaNotasFinales / 3.) << endl; //	Muestra el promedio general
				mayorMenor(); // Muestra los datos de nota mayor y menor
				cin.get();
				cin.get(); 
				break; 
			}
		}
	} while (opcion != 3);
}