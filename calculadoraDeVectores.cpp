#include <stdio.h>
#include <stdlib.h>

void cargarVector(int *v, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Ingrese valor %d: ", i+1);
        scanf("%d", v+i);
    }
}

void mostrarVector(int *v, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", *(v+i));
    }
    printf("\n");
}

void sumaResta(int *v1, int *v2, int *resSuma, int *resResta, int n) {
    int i;
    for(i = 0; i < n; i++) {
        *(resSuma+i) = *(v1+i) + *(v2+i);
        *(resResta+i) = *(v1+i) - *(v2+i);
    }
}

void multiplicarPorEscalar(int *v, int *res, int escalar, int n) {
    int i;
    for(i = 0; i < n; i++) {
        *(res+i) = *(v+i) * escalar;
    }
}

int productoEscalar(int *v1, int *v2, int n) {
    int i, total = 0;
    for(i = 0; i < n; i++) {
        total += (*(v1+i)) * (*(v2+i));
    }
    return total;
}

void productoVectorial(int *v1, int *v2, int *res) {
    res[0] = v1[1]*v2[2] - v1[2]*v2[1];
    res[1] = v1[2]*v2[0] - v1[0]*v2[2];
    res[2] = v1[0]*v2[1] - v1[1]*v2[0];
}

void operacionesVectores() {
    system("color 0A");

    int n, escalar;
    printf("Ingrese dimension de los vectores: ");
    scanf("%d", &n);

    int v1[n], v2[n], resSuma[n], resResta[n], resEscalar[n], resVectorial[3];

    printf("Ingrese valores del primer vector:\n");
    cargarVector(v1, n);

    printf("Ingrese valores del segundo vector:\n");
    cargarVector(v2, n);

    printf("Ingrese escalar: ");
    scanf("%d", &escalar);

    sumaResta(v1, v2, resSuma, resResta, n);
    multiplicarPorEscalar(v1, resEscalar, escalar, n);
    int prodEsc = productoEscalar(v1, v2, n);

    printf("\n--- RESULTADOS ---\n");

    printf("Suma: ");
    mostrarVector(resSuma, n);

    printf("Resta: ");
    mostrarVector(resResta, n);

    printf("Escalar * Vector 1: ");
    mostrarVector(resEscalar, n);

    printf("Producto escalar: %d\n", prodEsc);

    if(n == 3) {
        productoVectorial(v1, v2, resVectorial);
        printf("Producto vectorial: ");
        mostrarVector(resVectorial, 3);
    } else {
        printf("Producto vectorial solo disponible para vectores de 3 dimensiones.\n");
    }
}
