#include <iostream>
#include <cstdlib>

#include "calculadoraDeNumeros.h"
#include "calculadoraDeVectores.h"
#include "calculadoraDeMatrices.h"
#include "calculadoraDeEcuaciones.h"

using namespace std;

int main() {
    int opcion;

    do {
        cout << "=========== CALCULADORA EN C++ ===========" << endl;
        cout << "1. Operaciones básicas con números" << endl;
        cout << "2. Operaciones con vectores" << endl;
        cout << "3. Operaciones con matrices" << endl;
        cout << "4. Resolver sistema de ecuaciones" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = -1;
        }

        switch (opcion) {
            case 1:
                operacionesBasicas();
                break;
            case 2:
                operacionesVectores();
                break;
            case 3:
                operacionesMatrices();
                break;
            case 4:
                resolverSistemaEcuaciones();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

        if (opcion != 0) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("clear");
        }

    } while (opcion != 0);

    return 0;
}
