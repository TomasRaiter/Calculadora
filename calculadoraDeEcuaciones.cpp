#include <iostream>
#include <vector>
using namespace std;

void resolverSistema2x2() {
    double a1, b1, c1, a2, b2, c2;
    double x, y;

    // Pedimos los coeficientes y los términos independientes
    cout << "Sistema de ecuaciones 2x2:" << endl;
    cout << "a1x + b1y = c1" << endl;
    cout << "a2x + b2y = c2" << endl;
    
    cout << "a1: ";
    cin >> a1;
    cout << "b1: ";
    cin >> b1;
    cout << "c1: ";
    cin >> c1;

    cout << "a2: ";
    cin >> a2;
    cout << "b2: ";
    cin >> b2;
    cout << "c2: ";
    cin >> c2;

    // Eliminación de Gauss 
    double det = a1 * b2 - a2 * b1;
    if (det == 0) {
        cout << "El sistema no tiene solución única." << endl;
        return;
    }

    x = (c1 * b2 - c2 * b1) / det;
    y = (a1 * c2 - a2 * c1) / det;

    cout << "La solución del sistema es: " << endl;
    cout << "x = " << x << ", y = " << y << endl;
}

void resolverSistema3x3() {
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double a3, b3, c3, d3;
    double x, y, z;

    // Pedimos los coeficientes y los términos independientes
    cout << "Sistema de ecuaciones 3x3:" << endl;
    cout << "a1x + b1y + c1z = d1" << endl;
    cout << "a2x + b2y + c2z = d2" << endl;
    cout << "a3x + b3y + c3z = d3" << endl;
    
    cout << "a1: ";
    cin >> a1;
    cout << "b1: ";
    cin >> b1;
    cout << "c1: ";
    cin >> c1;
    cout << "d1: ";
    cin >> d1;

    cout << "a2: ";
    cin >> a2;
    cout << "b2: ";
    cin >> b2;
    cout << "c2: ";
    cin >> c2;
    cout << "d2: ";
    cin >> d2;

    cout << "a3: ";
    cin >> a3;
    cout << "b3: ";
    cin >> b3;
    cout << "c3: ";
    cin >> c3;
    cout << "d3: ";
    cin >> d3;

    // Eliminación de Gauss 
    double det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    
    if (det == 0) {
        cout << "El sistema no tiene solución única." << endl;
        return;
    }

    x = (d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2)) / det;
    y = (a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2)) / det;
    z = (a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2)) / det;

    cout << "La solución del sistema es: " << endl;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
}

// Menu
void resolverSistemaEcuaciones() {
    int opcion;
    cout << "Seleccione el tipo de sistema de ecuaciones:" << endl;
    cout << "1. Sistema 2x2" << endl;
    cout << "2. Sistema 3x3" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;

    if (opcion == 1) {
        resolverSistema2x2();
    } else if (opcion == 2) {
        resolverSistema3x3();
    } else {
        cout << "Opción inválida. Por favor, elija 1 o 2." << endl;
    }
}
