#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> Matriz;

Matriz ingresarMatriz(int filas, int columnas) {
    Matriz m(filas, vector<double>(columnas));
    cout << "Ingrese los elementos de la matriz (" << filas << "x" << columnas << "):\n";
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> m[i][j];
        }
    return m;
}

void mostrarMatriz(const Matriz &m) {
    for (auto fila : m) {
        for (auto val : fila)
            cout << fixed << setprecision(2) << val << "\t";
        cout << "\n";
    }
}

Matriz suma(const Matriz &a, const Matriz &b) {
    int filas = a.size(), columnas = a[0].size();
    Matriz resultado(filas, vector<double>(columnas));
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            resultado[i][j] = a[i][j] + b[i][j];
    return resultado;
}

Matriz resta(const Matriz &a, const Matriz &b) {
    int filas = a.size(), columnas = a[0].size();
    Matriz resultado(filas, vector<double>(columnas));
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            resultado[i][j] = a[i][j] - b[i][j];
    return resultado;
}

Matriz multiplicarPorEscalar(const Matriz &m, double escalar) {
    int filas = m.size(), columnas = m[0].size();
    Matriz resultado(filas, vector<double>(columnas));
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            resultado[i][j] = m[i][j] * escalar;
    return resultado;
}

Matriz multiplicarMatrices(const Matriz &a, const Matriz &b) {
    int filas = a.size(), columnas = b[0].size(), comun = a[0].size();
    Matriz resultado(filas, vector<double>(columnas, 0));
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            for (int k = 0; k < comun; k++)
                resultado[i][j] += a[i][k] * b[k][j];
    return resultado;
}

// Cofactor para determinante NxN
Matriz obtenerMenor(const Matriz &m, int fila, int columna) {
    int n = m.size();
    Matriz menor(n - 1, vector<double>(n - 1));
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i == fila) continue;
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (j == columna) continue;
            menor[r][c++] = m[i][j];
        }
        r++;
    }
    return menor;
}

double determinante(const Matriz &m) {
    int n = m.size();
    if (n == 1) return m[0][0];
    if (n == 2) return m[0][0]*m[1][1] - m[0][1]*m[1][0];

    double det = 0;
    for (int j = 0; j < n; j++) {
        Matriz menor = obtenerMenor(m, 0, j);
        det += m[0][j] * determinante(menor) * ((j % 2 == 0) ? 1 : -1);
    }
    return det;
}

// Matriz adjunta y transpuesta
Matriz adjunta(const Matriz &m) {
    int n = m.size();
    Matriz adj(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            Matriz menor = obtenerMenor(m, i, j);
            adj[j][i] = determinante(menor) * (((i + j) % 2 == 0) ? 1 : -1); // transpuesta
        }
    return adj;
}

Matriz inversa(const Matriz &m) {
    double det = determinante(m);
    if (det == 0) {
        cout << "La matriz no tiene inversa.\n";
        return {};
    }
    Matriz adj = adjunta(m);
    int n = m.size();
    Matriz inv(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = adj[i][j] / det;
    return inv;
}

void operacionesMatrices() {
    int filas, columnas;
    cout << "Ingrese cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese cantidad de columnas: ";
    cin >> columnas;

    Matriz A = ingresarMatriz(filas, columnas);
    Matriz B = ingresarMatriz(filas, columnas);

    int opcion;
    do {
        cout << "\n--- MENU DE OPERACIONES ---\n";
        cout << "1. Suma A + B\n";
        cout << "2. Resta (A - B o B - A)\n";
        cout << "3. Multiplicacion por escalar\n";
        cout << "4. Multiplicacion de matrices (A*B o B*A)\n";
        cout << "5. Determinante de A o B\n";
        cout << "6. Inversa de A o B\n";
        cout << "7. Division de matrices (A * inv(B) o B * inv(A))\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        int orden;
        double escalar;
        Matriz resultado;

        switch (opcion) {
            case 1:
                cout << "Mostrar A + B:\n";
                resultado = suma(A, B);
                mostrarMatriz(resultado);
                break;
            case 2:
                cout << "Mostrar A - B:\n";
                resultado = resta(A, B);
                mostrarMatriz(resultado);
                cout << "\nMostrar B - A:\n";
                resultado = resta(B, A);
                mostrarMatriz(resultado);
                break;
            case 3:
                cout << "Elegir matriz (1=A, 2=B): ";
                cin >> orden;
                cout << "Escalar: ";
                cin >> escalar;
                if (orden == 1)
                    mostrarMatriz(multiplicarPorEscalar(A, escalar));
                else
                    mostrarMatriz(multiplicarPorEscalar(B, escalar));
                break;
            case 4:
                if (A[0].size() == B.size()) {
                    cout << "A * B:\n";
                    mostrarMatriz(multiplicarMatrices(A, B));
                } else {
                    cout << "A * B: dimensiones incompatibles\n";
                }
                if (B[0].size() == A.size()) {
                    cout << "B * A:\n";
                    mostrarMatriz(multiplicarMatrices(B, A));
                } else {
                    cout << "B * A: dimensiones incompatibles\n";
                }
                break;
            case 5:
                if (A.size() == A[0].size()) {
                    cout << "Determinante de A: " << determinante(A) << endl;
                } else {
                    cout << "A no es cuadrada\n";
                }
                if (B.size() == B[0].size()) {
                    cout << "Determinante de B: " << determinante(B) << endl;
                } else {
                    cout << "B no es cuadrada\n";
                }
                break;
            case 6:
                if (A.size() == A[0].size()) {
                    cout << "Inversa de A:\n";
                    resultado = inversa(A);
                    if (!resultado.empty()) mostrarMatriz(resultado);
                } else cout << "A no es cuadrada\n";

                if (B.size() == B[0].size()) {
                    cout << "Inversa de B:\n";
                    resultado = inversa(B);
                    if (!resultado.empty()) mostrarMatriz(resultado);
                } else cout << "B no es cuadrada\n";
                break;
            case 7:
                if (B.size() == B[0].size()) {
                    Matriz invB = inversa(B);
                    if (!invB.empty()) {
                        if (A[0].size() == invB.size()) {
                            cout << "A * inv(B):\n";
                            mostrarMatriz(multiplicarMatrices(A, invB));
                        } else cout << "Dimensiones incompatibles para A * inv(B)\n";
                    }
                } else cout << "B no es cuadrada\n";

                if (A.size() == A[0].size()) {
                    Matriz invA = inversa(A);
                    if (!invA.empty()) {
                        if (B[0].size() == invA.size()) {
                            cout << "B * inv(A):\n";
                            mostrarMatriz(multiplicarMatrices(B, invA));
                        } else cout << "Dimensiones incompatibles para B * inv(A)\n";
                    }
                } else cout << "A no es cuadrada\n";
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida\n";
        }
    } while (opcion != 0);


}
