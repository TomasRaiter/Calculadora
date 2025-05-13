#include <iostream>
#include <limits>

using namespace std;

void cargarVector(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese valor " << i + 1 << ": ";
        while (!(cin >> *(v + i)))
        {
            cout << "Entrada invalida. Ingrese un numero entero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void mostrarVector(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(v + i) << " ";
    }
    cout << endl;
}

void sumaResta(int *v1, int *v2, int *resSuma, int *resResta, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(resSuma + i) = *(v1 + i) + *(v2 + i);
        *(resResta + i) = *(v1 + i) - *(v2 + i);
    }
}

void multiplicarPorEscalar(int *v, int *res, int escalar, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(res + i) = *(v + i) * escalar;
    }
}

int productoEscalar(int *v1, int *v2, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += (*(v1 + i)) * (*(v2 + i));
    }
    return total;
}

void productoVectorial(int *v1, int *v2, int *res)
{
    res[0] = v1[1] * v2[2] - v1[2] * v2[1];
    res[1] = v1[2] * v2[0] - v1[0] * v2[2];
    res[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void operacionesVectores()
{
    int n, escalar, opcion;

    cout << "Ingrese dimension de los vectores: ";
    while (!(cin >> n))
    {
        cout << "Entrada invalida. Ingrese un numero entero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int v1[n], v2[n], resSuma[n], resResta[n], resEscalarV1[n], resEscalarV2[n], resVectorial[3];

    cout << "Ingrese valores del primer vector:\n";
    cargarVector(v1, n);

    cout << "Ingrese valores del segundo vector:\n";
    cargarVector(v2, n);

    do
    {
        cout << "\n--- MENU DE OPERACIONES ---\n";
        cout << "1. Suma y Resta de vectores\n";
        cout << "2. Multiplicacion de escalar por ambos vectores\n";
        cout << "3. Producto escalar\n";
        cout << "4. Producto vectorial (solo para vectores de 3 dimensiones)\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        while (!(cin >> opcion))
        {
            cout << "Opcion invalida. Ingrese un numero entero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion)
        {
        case 1:
            sumaResta(v1, v2, resSuma, resResta, n);
            cout << "\nSuma: ";
            mostrarVector(resSuma, n);
            cout << "Resta: ";
            mostrarVector(resResta, n);
            break;

        case 2:
            cout << "Ingrese el escalar: ";
            while (!(cin >> escalar))
            {
                cout << "Entrada invalida. Ingrese un numero entero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            multiplicarPorEscalar(v1, resEscalarV1, escalar, n);
            multiplicarPorEscalar(v2, resEscalarV2, escalar, n);
            cout << "\nEscalar * Vector 1: ";
            mostrarVector(resEscalarV1, n);
            cout << "Escalar * Vector 2: ";
            mostrarVector(resEscalarV2, n);
            break;

        case 3:
            cout << "\nProducto escalar: " << productoEscalar(v1, v2, n) << endl;
            break;

        case 4:
            if (n == 3)
            {
                productoVectorial(v1, v2, resVectorial);
                cout << "Producto vectorial: ";
                mostrarVector(resVectorial, 3);
            }
            else
            {
                cout << "Producto vectorial solo disponible para vectores de 3 dimensiones.\n";
            }
            break;

        case 5:
            break;

        default:
            cout << "Opcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 5);
}
