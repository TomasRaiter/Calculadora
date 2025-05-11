#include <iostream>
#include <cmath> // Para pow y sqrt

using namespace std;

void mostrarOperaciones()
{
    cout << "\n--- OPERACIONES DISPONIBLES ---\n";
    cout << "1. Suma (+)\n";
    cout << "2. Resta (-)\n";
    cout << "3. Multiplicación (*)\n";
    cout << "4. División (/)\n";
    cout << "5. Potencia (^)\n";
    cout << "6. Raíz cuadrada (√)\n";
    cout << "7. Salir\n";
}

double pedirNumero(string mensaje, double resultadoAnterior)
{
    double num;
    string entrada;
    cout << mensaje << "(o escriba 'r' para usar el resultado anterior): ";
    cin >> entrada;

    if (entrada == "r" || entrada == "R")
    {
        return resultadoAnterior;
    }

    try
    {
        num = stod(entrada);
    }
    catch (...)
    {
        cout << "Entrada inválida. Intente de nuevo.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return pedirNumero(mensaje, resultadoAnterior);
    }

    return num;
}

void operacionesBasicas()
{
    int opcion;
    double resultadoAnterior = 0.0;
    bool hayResultadoAnterior = false;
    mostrarOperaciones();
    do
    {

        cout << "\nSeleccione una opción (1-7): ";
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida. Intente nuevamente.\n";
            continue;
        }

        double num1, num2, resultado;

        switch (opcion)
        {
        case 1:
            num1 = pedirNumero("Ingrese el primer número ", resultadoAnterior);
            num2 = pedirNumero("Ingrese el segundo número ", resultadoAnterior);
            resultado = num1 + num2;
            cout << "Resultado: " << resultado << endl;
            resultadoAnterior = resultado;
            hayResultadoAnterior = true;
            break;
        case 2:
            num1 = pedirNumero("Ingrese el primer número ", resultadoAnterior);
            num2 = pedirNumero("Ingrese el segundo número ", resultadoAnterior);
            resultado = num1 - num2;
            cout << "Resultado: " << resultado << endl;
            resultadoAnterior = resultado;
            hayResultadoAnterior = true;
            break;
        case 3:
            num1 = pedirNumero("Ingrese el primer número ", resultadoAnterior);
            num2 = pedirNumero("Ingrese el segundo número ", resultadoAnterior);
            resultado = num1 * num2;
            cout << "Resultado: " << resultado << endl;
            resultadoAnterior = resultado;
            hayResultadoAnterior = true;
            break;
        case 4:
            num1 = pedirNumero("Ingrese el dividendo ", resultadoAnterior);
            do
            {
                num2 = pedirNumero("Ingrese el divisor (no puede ser 0) ", resultadoAnterior);
            } while (num2 == 0);
            resultado = num1 / num2;
            cout << "Resultado: " << resultado << endl;
            resultadoAnterior = resultado;
            hayResultadoAnterior = true;
            break;
        case 5:
            num1 = pedirNumero("Ingrese la base ", resultadoAnterior);
            num2 = pedirNumero("Ingrese el exponente ", resultadoAnterior);
            resultado = pow(num1, num2);
            cout << "Resultado: " << resultado << endl;
            resultadoAnterior = resultado;
            hayResultadoAnterior = true;
            break;
        case 6:
            num1 = pedirNumero("Ingrese el número ", resultadoAnterior);
            if (num1 < 0)
                cout << "Error: No se puede calcular raíz cuadrada de un número negativo.\n";
            else
            {
                resultado = sqrt(num1);
                cout << "Resultado: " << resultado << endl;
                resultadoAnterior = resultado;
                hayResultadoAnterior = true;
            }
            break;
        case 7:
            cout << "Saliendo de la calculadora.\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }

    } while (opcion != 7);
}
