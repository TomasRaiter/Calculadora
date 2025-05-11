#include <stdio.h>
#include <stdlib.h>
    
#define MAX 10
    
void cargarMatriz(float M[MAX][MAX], int f, int c, char nombre);
void imprimirMatriz(float M[MAX][MAX], int f, int c);
void sumaMatrices2(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int f, int c);
void sumaMatrices3_ab(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int f, int c);
void sumaMatrices3_bc(float B[MAX][MAX], float D[MAX][MAX], float C[MAX][MAX], int f, int c);
void sumaMatrices3_ac(float A[MAX][MAX], float D[MAX][MAX], float C[MAX][MAX], int f, int c);
void restaMatrices2(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int f, int c);
void restaMatrices3(float A[MAX][MAX], float B[MAX][MAX], float D[MAX][MAX], float C[MAX][MAX], int f, int c, int opcion);
void multiplicarEscalar(float A[MAX][MAX], float esc, int f, int c);
void multMatrices2(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int fA, int cA, int fB, int cB);
float determinante2x2(float A[MAX][MAX]);
float determinante(int f, float A[MAX][MAX]);
void calcularAdjunto(float A[MAX][MAX], float adjunto[MAX][MAX], int f);
void calcularInversa(int f, float A[MAX][MAX], float inversa[MAX][MAX]);     
void division(float A[MAX][MAX], float B[MAX][MAX], float R[MAX][MAX], int f, int c);

void operacionesMatrices(){
    int opcion, numMat, selOp;
    int f1,c1,f2,c2,f3,c3;
    float A[MAX][MAX], B[MAX][MAX], D[MAX][MAX], R[MAX][MAX], esc, det, adjunto[MAX][MAX], inversa[MAX][MAX];
    
    do{
        printf("\nCALCULADORA (maximas dimensiones permitidas: %dx%d, hasta 3 matrices)\n", MAX, MAX);
        printf("Ingrese una opción: "); 
        printf("1. Cargar matrices\n");
        printf("2. Suma de matrices\n");
        printf("3. Resta de matrices\n");
        printf("4. Multiplicación por escalar\n");
        printf("5. Multiplicación de matrices\n");
        printf("6 Multiplicación de escalar por vector\n");
        printf("7. determinante de una matriz\n");
        printf("8. Inversa de una matriz\n");
        printf("9. División de matrices\n");
        printf("0. Salir\n");
        scanf("%d",&opcion);
    
        switch(opcion){
            case 1:
                do{ 
                    printf("¿2 o 3 matrices? "); 
                    scanf("%d",&numMat); 
                }while(numMat < 2 || numMat > 3);

                do{ 
                    printf("Ingrese las filas de la matriz A, maximo %d y minimo 1 : ",MAX);
                    scanf("%d",&f1);
                }while(f1 < 1 || f1 > MAX);
                do{ 
                    printf("Ingrese las columnas de la matriz A, maximo %d y minimo 1: ",MAX); 
                    scanf("%d",&c1);
                }while(c1 < 1 || c1 > MAX);
                cargarMatriz(A,f1,c1,'A');

                do{ 
                    printf("Ingrese las filas de la matriz B, maximo %d y minimo 1: ",MAX);
                    scanf("%d",&f2);
                }while(f2 < 1 || f2> MAX);
                do{ 
                    printf("Ingrese las columnas de la matriz B, maximo %d y minimo: ",MAX); 
                    scanf("%d",&c2);
                }while(c2 < 1 || c2 > MAX);
                cargarMatriz(B,f2,c2,'B');

                if(numMat == 3){
                    do{ 
                        printf("Ingrese las filas de la matriz C, maximo %d y minimo 1: ",MAX);
                        scanf("%d",&f3);
                    }while(f3 < 1 || f3 > MAX);
                    do{
                        printf("Ingrese las columnas de la matriz C, maximo %d y minimo 1: ",MAX); 
                        scanf("%d",&c3);
                    }while(c3 < 1 || c3 > MAX);
                    cargarMatriz(D,f3,c3,'D');
                }
            break;
    
            case 2: 
                if(numMat < 2){ 
                    printf("Primero cargá matrices.\n");
                    break; }
                if(numMat == 2){
                  if(f1 != f2 || c1 != c2){
                     printf("Dimensiones no coinciden.\n");
                     break; 
                    }
                  sumaMatrices2(A,B,R,f1,c1);
                }else {
                    do{
                        printf("Seleccione suma:\n1) A + B\n2) B + C\n3) A + C\nOpción: "); 
                        scanf("%d",&selOp);
                        if(selOp < 1 || selOp > 3)
                            printf("Opción inválida. Debe ser 1, 2 o 3.\n");
                        }while(selOp < 1 || selOp > 3);
                        if(selOp == 1){
                            if(f1 != f2 || c1 != c2){
                                printf("Las dimensiones no coinciden.\n");
                                break;
                            }
                    sumaMatrices3_ab(A,B,R,f1,c1);
                    }else if(selOp == 2){
                        if(f2 != f3 || c2 != c3){
                            printf("Las dimensiones no coinciden.\n");
                            break;
                        }
                    sumaMatrices3_bc(B,D,R,f2,c2);
                    }else{
                        if(f1 != f3 || c1 != c3){
                            printf("Las dimensiones no coinciden.\n");
                            break;
                        }
                    sumaMatrices3_ac(A,D,R,f1,c1);
                }
                printf("Resultado de la suma:\n");
                imprimirMatriz(R,f1,c1);
            break;
                }
            case 3: 
                if(numMat < 2){
                     printf("Primero cargá matrices.\n"); 
                     break; 
                }
                if(numMat == 2){
                  if(f1 != f2 || c1 != c2){
                    printf("Dimensiones no coinciden.\n");
                    break;
                }
                    restaMatrices2(A,B,R,f1,c1);
                }else {
                    if(! (f1 == f2 && f2 == f3 && c1 == c2 && c2 == c3)){
                        printf("Todas las matrices deben tener mismas dimensiones.\n");
                        break;
                    }
                    printf("Seleccione una opción:\n");
                    printf("1) Primera - Segunda\n");
                    printf("2) Primera - Tercera\n");
                    printf("3) Segunda - Primera\n");
                    printf("4) Segunda - Tercera\n");
                    printf("5) Tercera - Primera\n");
                    printf("6) Tercera - Segunda\n");
                    printf("7) Tercera - Primera - Segunda\n");
                    printf("8) Primera - Segunda - Tercera\n");
                    printf("9) Segunda - Primera - Tercera\n");
                    printf("Opción: "); scanf("%d",&selOp);
                  
                    restaMatrices3(A,B,D,R,f1,c1, selOp);
                }
                printf("Resultado de la resta:\n"); 
                imprimirMatriz(R,f1,c1);
            break;
    
            case 4: 
                if(numMat<1){
                    printf("Primero cargá matrices.\n");
                    break;
                }
                do{
                    printf("Cual de las siguientes matrices quiere multiplicar por un escalar? :\n 1(A) \n 2(B)"); 
                    if(numMat==3) 
                    printf("\n 3(C)");
                    scanf("%d",&selOp);
                }while(selOp<1 || selOp>(numMat==3?3:2));

                printf("Ingrese el escalar: ");
                scanf("%f",&esc);
                if(selOp==1)
                    multiplicarEscalar(A,esc,f1,c1);
                else if(selOp==2) 
                    multiplicarEscalar(B,esc,f2,c2);
                else 
                    multiplicarEscalar(D,esc,f3,c3);
                
            break;
    
            case 5: 
                if(numMat <2 ){
                    printf("Primero cargá matrices.\n");
                    break;
                }
                if(numMat == 2){

                    do{
                        printf("Desea multiplicar la matriz 1(A) por la matriz 2(B) o viceversa?\n");
                        scanf("%d",&selOp);
                    }while(selOp<1 || selOp>2);

                    if(selOp == 1){
                        if(c1 != f2){
                            printf("Las filas de A deben ser la misma cantidad que las columnas de B.\n");
                            break; 
                        }
                        multMatrices2(A,B,R,f1,c1,f2,c2);
                        printf("A * B =\n"); 
                        imprimirMatriz(R,f1,c2);
                        break;
                    }else{
                        if(c2 != f1){
                            printf("Las columnas de A deben ser la misma cantidad que las filas de B.\n");
                            break; 
                        }
                        multMatrices2(B,A,R,f1,c1,f2,c2);
                        printf("B * A =\n"); 
                        imprimirMatriz(R,f2,c1);
                        break;
                    }   
                }else{
                    do{
                        printf("Ingrese una opcion:\n");
                        printf("0) Multiplicar la primera (A) matriz por la segunda (B)\n");
                        printf("1) Multiplicar la primera (A) matriz por la tercera (C)\n");
                        printf("2) Multiplicar la segunda matriz (B) por la primera (A)\n");
                        printf("3) Multiplicar la segunda matriz (B) por la tercera (C)\n");
                        printf("4) Multiplicar la tercera matriz (C) por la primera (A)\n");
                        printf("5) Multiplicar la tercera matriz (C) por la segunda (B)\n");
                        printf("6) Multiplicar la primera (A) matriz por si misma\n");
                        printf("7) Multiplicar la segunda (B) matriz por si misma\n");
                        printf("8) Multiplicar la tercera (C) matriz por si misma\n");
                        printf("9) Multiplicar la primera (A) matriz por la segunda (B) y luego por la tercera (C)\n");
                        scanf("%d", &selOp);
                        if(selOp < 0 || selOp > 9){
                            printf("La operacion no es valida, por favor ingrese una de las 10 opciones\n");
                        }   
                    }while(selOp < 0 || selOp > 9);
    
                    switch (selOp)
                    {
                    case 0:
                        if(c1 != f2){
                            printf("Las filas de A deben ser la misma cantidad que las columnas de B.\n");
                            break; 
                        }
                        multMatrices2(A,B,R,f1,c1,f2,c2);
                        printf("A * B =\n");
                        imprimirMatriz(R,f1,c2);                        
                        break;
                    case 1:
                        if(c1 != f3){
                            printf("Las filas de A deben ser la misma cantidad que las columnas de C.\n");
                            break; 
                        }
                        multMatrices2(A,D,R,f2,c2,f1,c1);
                        printf("A * C =\n");
                        imprimirMatriz(R,f2,c1);
                        break;
                    
                    case 2:
                        if(c1 != f2){
                            printf("Las filas de B deben ser la misma cantidad que las columnas de A.\n");
                            break; 
                        }
                        multMatrices2(B,A,R,f2,c2,f1,c1);
                        printf("B * A =\n");
                        imprimirMatriz(R,f2,c1);
                        break;
                    case 3:
                        if(c3 != f2){
                            printf("Las filas de B deben ser la misma cantidad que las columnas de C.\n");
                            break; 
                        }
                        multMatrices2(B,D,R,f2,c2,f3,c3);
                        printf("B * C =\n");
                        imprimirMatriz(R,f2,c3);
                        break;

                    case 4:
                        if(c1 != f3){
                            printf("Las filas de C deben ser la misma cantidad que las columnas de A.\n");
                            break; 
                        }
                        multMatrices2(D,A,R,f3,c3,f1,c1);
                        printf("C * A =\n");
                        imprimirMatriz(R,f3,c1);
                        break;
                    case 5:
                        if(c2 != f3){
                            printf("Las filas de C deben ser la misma cantidad que las columnas de B.\n");
                            break; 
                        }
                        multMatrices2(D,B,R,f3,c3,f2,c2);
                        printf("C * B =\n");
                        imprimirMatriz(R,f3,c2);
                        break;
                    case 6:
                        if(c1 != f1){
                            printf("Las filas de A deben ser la misma cantidad que las columnas de A.\n");
                            break; 
                        }
                        multMatrices2(A,A,R,f1,c1,f1,c1);
                        printf("A * A =\n");
                        imprimirMatriz(R,f1,c1);
                        break;
                    case 7:
                        if(c2 != f2){
                            printf("Las filas de B deben ser la misma cantidad que las columnas de B.\n");
                            break; 
                        }
                        multMatrices2(B,B,R,f2,c2,f2,c2);
                        printf("B * B =\n");
                        imprimirMatriz(R,f2,c2);
                        break;
                    case 8:
                        if(c3 != f3){
                            printf("Las filas de C deben ser la misma cantidad que las columnas de C.\n");
                            break; 
                        }
                        multMatrices2(D,D,R,f3,c3,f3,c3);
                        printf("C * C =\n");
                        imprimirMatriz(R,f3,c3);
                        break;
                    case 9:
                        if(c1 != f2 || c2 != f3){
                            printf("Las filas de A deben ser la misma cantidad que las columnas de B y las filas de B deben ser la misma cantidad que las columnas de C.\n");
                            break; 
                        }
                        multMatrices2(A,B,R,f1,c1,f2,c2);
                        multMatrices2(R,D,R,f1,c2,f3,c3);
                        printf("A * B * C =\n");
                        imprimirMatriz(R,f1,c3);
                        break;
                    }
                }
            case 6:
                if(numMat < 1){
                    printf("Primero cargá matrices.\n");
                    break;
                }
                do{
                    printf("Cual de las siguientes matrices quiere multiplicar por un escalar? :\n 1(A) \n 2(B)"); 
                    if(numMat==3) 
                    printf("\n 3(C)");
                    scanf("%d",&selOp);
                }while(selOp<1 || selOp>(numMat==3?3:2));

                printf("Ingrese el escalar: ");
                scanf("%f",&esc);
                if(selOp==1){
                    if(f1 != 1){
                        printf("Debe ser un vector para realizar esta operación (Una sola fila).\n");
                        break;
                    }
                    multiplicarEscalar(A,esc,f1,c1);

                }
                else if(selOp==2){
                    if(f2 != 1){
                        printf("Debe ser un vector para realizar esta operación (Una sola fila).\n");
                        break;
                    }
                    multiplicarEscalar(B,esc,f2,c2);
                }
                else {
                    if(f3 != 1){
                        printf("Debe ser un vector para realizar esta operación (Una sola fila).\n");
                        break;
                    }
                    multiplicarEscalar(D,esc,f3,c3);
                }
            break;
            case 7:
              if(numMat < 2){
                printf("Ingresa matrices primero");
                break;
              }
               do{
                    printf("¿De cual matriz desea obtener su determinante \n 1.(A) \n 2.(B)?");
                    if(numMat == 3)
                        printf("\n3.(C)");
                    scanf("%d", &selOp);
                
               }while(selOp<1 || selOp>(numMat==3?3:2));
               if(selOp == 1){
                    if(f1 != c1){
                        printf("La matriz A no es cuadrada, no se puede calcular el determinante.\n");
                        break;
                    }
                    det = determinante(f1,A);
               }else if(selOp == 2){
                    if(f2 != c2){
                        printf("La matriz B no es cuadrada, no se puede calcular el determinante.\n");
                        break;
                    }
                    det = determinante(f2,B);
               }else{
                    if(f3 != c3){
                        printf("La matriz C no es cuadrada, no se puede calcular el determinante.\n");
                        break;
                    }
                    det = determinante(f3,D);
                    printf("El determinante de la matriz es: %f\n", det);    
                    break; 
                }
              case 8:
                if(numMat < 1){
                    printf("Primero cargá matrices.\n");
                    break;
                }
                do{
                    printf("Cual de las siguientes matrices quiere calcular la inversa? :\n 1(A) \n 2(B)"); 
                    if(numMat==3) 
                    printf("\n 3(C)");
                    scanf("%d",&selOp);
                }while(selOp<1 || selOp>(numMat==3?3:2));
                if(selOp==1){
                    if(f1 != c1){
                        printf("La matriz A no es cuadrada, no se puede calcular la inversa.\n");
                        break;
                    }
                    det = determinante(f1,A);
                    if(det == 0){
                        printf("La matriz A no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f1,A,inversa);
                }

                if(selOp==2){
                    if(f2 != c2){
                        printf("La matriz B no es cuadrada, no se puede calcular la inversa.\n");
                        break;
                    }
                    det = determinante(f2,B);
                    if(det == 0){
                        printf("La matriz B no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f2,B,inversa);
                }
                
                if(selOp==3){
                    if(f3 != c3){
                        printf("La matriz C no es cuadrada, no se puede calcular la inversa.\n");
                        break;
                    }
                    det = determinante(f3,D);
                    if(det == 0){
                        printf("La matriz C no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f3,D,inversa);
                }
                printf("La inversa de la matriz es:\n");
                for(int i = 0; i < f1; i++){
                    for(int j = 0; j < c1; j++){
                        printf("%f ", inversa[i][j]);
                    }
                    printf("\n");
                }
        
              break;

              case 9:
                if(numMat < 2){
                    printf("Primero cargá matrices. \n");
                    break;
                }
                do{
                    printf("Ingrese una opcion:\n");
                    printf("1) A / B\n");
                    printf("2) B / A\n");
                    if(numMat == 3){
                        printf("3) A / C\n");
                        printf("4) B / C\n");
                        printf("5) C / A\n");
                        printf("6) C / B\n");
                        printf("7) A / B / C\n");
                        printf("8) B / A / C\n");
                        printf("9) C / A / B\n");
                        /*
                        A
                        A
                        A
                        A
                        */
                    }
                }while(selOp<1 || selOp>(numMat==3?9:2));

                if(selOp == 1){
                    if(f1 != c2){
                        printf("Las dimensiones de A y B no coinciden.\n");
                        break;
                    }
                    det = determinante(f2,B);
                    if(det == 0){
                        printf("La matriz B no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f2,B,inversa);
                    division(A,inversa,R,f1,c2);
                    imprimirMatriz(R,f1,c2);
                }else if(selOp == 2){
                    if(f2 != c1){
                        printf("Las dimensiones de B y A no coinciden.\n");
                        break;
                    }
                    det = determinante(f1,A);
                    if(det == 0){
                        printf("La matriz A no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f1,A,inversa);
                    division(B,inversa,R,f2,c1);
                    imprimirMatriz(R,f2,c1);
                }else if(selOp == 3){
                    if(f1 != c3){
                        printf("Las dimensiones de A y C no coinciden.\n");
                        break;
                    }
                    det = determinante(f3,D);
                    if(det == 0){
                        printf("La matriz C no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f3,D,inversa);
                    division(A,inversa,R,f1,c3);
                    imprimirMatriz(R,f1,c3);
                }else if(selOp == 4){
                    if(f2 != c3){
                        printf("Las dimensiones de B y C no coinciden.\n");
                        break;
                    }
                    det = determinante(f3,D);
                    if(det == 0){
                        printf("La matriz C no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f3,D,inversa);
                    division(D,inversa,R,f2,c3);
                    imprimirMatriz(R,f2,c3);
                }else if(selOp == 5){
                    if(f3 != c1){
                        printf("Las dimensiones de C y A no coinciden.\n");
                        break;
                    }
                    det = determinante(f1,A);
                    if(det == 0){
                        printf("La matriz A no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f1,A,inversa);
                    division(D,inversa,R,f3,c1);
                    imprimirMatriz(R,f3,c1);
                }else if(selOp == 6){
                    if(f3 != c2){
                        printf("Las dimensiones de C y B no coinciden.\n");
                        break;
                    }
                    det = determinante(f2,B);
                    if(det == 0){
                        printf("La matriz B no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f2,B,inversa);
                    division(D,inversa,R,f3,c2);
                    imprimirMatriz(R,f3,c2);
                }else if(selOp == 7){
                    if(f1 != c2 || f1 != c3){
                        printf("Las dimensiones de A, B y C no coinciden.\n");
                        break;
                    }
                    det = determinante(f2,B);
                    if(det == 0){
                        printf("La matriz B no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f2,B,inversa);
                    division(A,inversa,R,f1,c2);
                    
                    det = determinante(f3,D);
                    if(det == 0){
                        printf("La matriz C no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f3,D,inversa);
                    division(B,inversa,R,f1,c3);
                    imprimirMatriz(R,f1,c3);
                }else if(selOp == 8){
                    if(f2 != c1 || f2 != c3){
                        printf("Las dimensiones de B, A y C no coinciden.\n");
                        break;
                    }
                    det = determinante(f1,A);
                    if(det == 0){
                        printf("La matriz A no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f1,A,inversa);
                    division(B,inversa,R,f2,c1);

                    det = determinante(f3,D);
                    if(det == 0){
                        printf("La matriz C no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f3,D,inversa);
                    division(D,inversa,R,f2,c3);
                    imprimirMatriz(R,f2,c3);
                }else{
                    if(f3 != c1 || f3 != c2){
                        printf("Las dimensiones de C, A y B no coinciden.\n");
                        break;
                    }
                    det = determinante(f1,A);
                    if(det == 0){
                        printf("La matriz A no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f1,A,inversa);
                    division(D,inversa,R,f3,c1);

                    det = determinante(f2,B);
                    if(det == 0){
                        printf("La matriz A no tiene inversa.\n");
                        break;
                    }
                    calcularInversa(f1,A,inversa);
                    division(A,inversa,R,f1,c1);
                    imprimirMatriz(R,f3,c2);
                }
               break;
              
              
              default:
              printf("Opción inválida.\n");
            }
        }while(opcion!=0);
    
    return;
        
}

        
void cargarMatriz(float M[MAX][MAX], int f, int c, char nombre) {
    printf("Ingrese los valores de la matriz ");
    for(int i = 0; i < f; i++)
        for(int j = 0; j < c; j++) {
            printf("Ingrese el valor de la matriz %c posicion [%d][%d] = ", nombre, i, j);
            scanf("%f", &M[i][j]);
        }
    return;
}
    
void imprimirMatriz(float M[MAX][MAX], int f, int c) {
    for(int i = 0; i < f; i++) 
        for(int j = 0; j < c; j++){
            printf("%8.2f ", M[i][j]);
            printf("\n");
        }
    return;
}
    
void sumaMatrices2(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int f, int c) {
    for(int i=0;i<f;i++) 
        for(int j=0;j<c;j++) 
            C[i][j] = A[i][j] + B[i][j];
    return;
}

void sumaMatrices3_ab(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int f, int c) {
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++) 
            C[i][j] = A[i][j] + B[i][j];
    return;
}

void sumaMatrices3_bc(float B[MAX][MAX], float D[MAX][MAX], float C[MAX][MAX], int f, int c) {
    for(int i=0;i<f;i++) 
        for(int j=0;j<c;j++) 
            C[i][j] = B[i][j] + D[i][j];
    return;
}

void sumaMatrices3_ac(float A[MAX][MAX], float D[MAX][MAX], float C[MAX][MAX], int f, int c) {
    for(int i=0;i<f;i++) 
        for(int j=0;j<c;j++)
            C[i][j] = A[i][j] + D[i][j];
    return;
}
    
void restaMatrices2(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int f, int c) {
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++)
            C[i][j] = A[i][j] - B[i][j];
    return;
}

void restaMatrices3(float A[MAX][MAX], float B[MAX][MAX], float D[MAX][MAX],
    float C[MAX][MAX], int f, int c, int opcion) {
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            switch(opcion) {
                case 1:
                    C[i][j] = A[i][j] - B[i][j];
                break;
                case 2: 
                    C[i][j] = A[i][j] - D[i][j]; 
                break;
                case 3: 
                    C[i][j] = B[i][j] - A[i][j]; 
                break;
                case 4:
                    C[i][j] = B[i][j] - D[i][j]; 
                break;
                case 5: 
                    C[i][j] = D[i][j] - A[i][j]; 
                break;
                case 6: 
                    C[i][j] = D[i][j] - B[i][j]; 
                break;
                case 7: 
                    C[i][j] = D[i][j] - A[i][j] - B[i][j]; 
                break;
                case 8: 
                    C[i][j] = A[i][j] - B[i][j] - D[i][j]; 
                break;
                case 9: 
                    C[i][j] = B[i][j] - A[i][j] - D[i][j]; 
                break;
            }
          }
        }
    return;
}
    
void multiplicarEscalar(float A[MAX][MAX], float esc, int f, int c) {
    for(int i=0;i<f;i++)
        for(int j=0;j<c;j++) 
            A[i][j] *= esc;
    printf("Resultado :\n");
    imprimirMatriz(A,f,c);
    return;
}
    
void multMatrices2(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX],
    int fA, int cA, int fB, int cB) {
        for(int i=0;i<fA;i++){
            for(int j=0;j<cB;j++){
                C[i][j] = 0;
                for(int k=0;k<cA;k++) 
                    C[i][j] += A[i][k]*B[k][j];
          }
        }
    return;
    }

float determinante2x2(float A[MAX][MAX]) {
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}

float determinante(int f, float A[MAX][MAX]) {
    float det = 0;
    if (f == 2) {
        det = determinante2x2(A);
        return det;
    }

    float subMatriz[MAX][MAX];

    for (int c = 0; c < f; ++c) {
        int subI = 0;
        for (int i = 1; i < f; ++i) {
            int subJ = 0;
            for (int j = 0; j < f; ++j) {
                if (j == c) continue;
                subMatriz[subI][subJ] = A[i][j];
                subJ++;
            }
            subI++;
        }

        float subDet = determinante(f - 1,subMatriz);
        float signo = (c % 2 == 0) ? 1 : -1;
        det += signo * A[0][c] * subDet;
    }

    return det;
}

void calcularAdjunto(float A[MAX][MAX], float adjunto[MAX][MAX], int f) {
    float subMatriz[MAX][MAX];
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < f; ++j) {
            int subI = 0;
            for (int z = 0; z < f; ++z) {
                if (z == i) continue;
                int subJ = 0;
                for (int k = 0; k < f; ++k) {
                    if (k == j) continue;
                    subMatriz[subI][subJ++] = A[z][k];
                }
                subI++;
            }
            float signo = ((i + j) % 2 == 0) ? 1 : -1;
            adjunto[j][i] = signo * determinante(f - 1,subMatriz);
        }
    }
    return;
}


void calcularInversa(int f, float A[MAX][MAX], float inversa[MAX][MAX]){        
    float det = determinante(f,A), adjunto[MAX][MAX];
    if(det == 0){
        printf("La matriz no tiene inversa\n");
        return;
    }
        calcularAdjunto(A,adjunto,f); 

        for(int i = 0; i < f; i++)
            for(int j = 0; j < f; j++)
                inversa[i][j] = adjunto[i][j] /det;
    return;
}

void division(float A[MAX][MAX], float B[MAX][MAX], float R[MAX][MAX], int f, int c){
    float inversaB[MAX][MAX];
    calcularInversa(f, B, inversaB);
    multMatrices2(A,inversaB,R,f,c,f,c);
    return;
}
