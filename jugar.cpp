#define NIVEL_P 6
#define NIVEL_I 8
#define NIVEL_A 10

#define TIEMPO_COLOR_P 1.5
#define TIEMPO_COLOR_I 1.3
#define TIEMPO_COLOR_A 1

#define ACIERTO_NIVEL_P 1
#define ACIERTO_NIVEL_I 3
#define ACIERTO_NIVEL_A 5
#include "funciones.h"
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void jugar(char nombre[], char nivel) {

    int largo, tiempo, acierto;
    verificarNivel(nivel,largo, tiempo, acierto);


    char secuenciaRandom[largo];
    inicializarSecuencia(secuenciaRandom, largo);

    printf("%s\n", secuenciaRandom);

    bool perdio=false;
    char secuenciaUsuario[largo];

    // Itera segun el largo pidiendo intentos
    for (int i=0 ; i<largo && !perdio; i++) {

        mostrarBorrar(secuenciaRandom, i, tiempo);

        printf("Ingrese su intento: ");
        scanf(" %c", &secuenciaUsuario[i]);

        for (int j=0 ; j<=i ; j++) {

            if (secuenciaRandom[j]!=secuenciaUsuario[j]) {
                perdio=true;
            }
            printf("%s", secuenciaUsuario);
        }

    }


}

void verificarNivel(char nivel, int &largo, int &tiempo, int &acierto) {

    switch (nivel) {
        case 'p':
        case 'P':
            largo=NIVEL_P;
            tiempo=TIEMPO_COLOR_P*1000;
            acierto=ACIERTO_NIVEL_P;
            break;
        case 'i':
        case 'I':
            largo=NIVEL_I;
            tiempo=TIEMPO_COLOR_I*1000;
            acierto=ACIERTO_NIVEL_I;
            break;
        case 'a':
        case 'A':
            largo=NIVEL_A;
            tiempo=TIEMPO_COLOR_A*1000;
            acierto=ACIERTO_NIVEL_A;
            break;
    }
}

void inicializarSecuencia(char secuencia[], int largo) {

    // inicializar la semilla para que los numeros sean realmente aleatorios
    srand(time(0));

    char colores[]={'R', 'A', 'V', 'N'};
    int totalLetras=4;

    //Definir valores aleatorios
    for (int i=0; i< largo; i++) {
        int indiceAleatorio = rand() % totalLetras;

        secuencia[i]=colores[indiceAleatorio];

    }
    // Terminar el array
    secuencia[largo]='\0';

}

void mostrarBorrar(char secuenciaRandom[], int i, int tiempo) {

    for (int j = 0; j <= i; j++) {
        // 1. Mostrar el carácter
        printf("%c", secuenciaRandom[j]);
        fflush(stdout);
        std::this_thread::sleep_for(std::chrono::milliseconds(tiempo));

        // 2. Borrar el carácter: retroceder, espacio, retroceder
        printf("\b \b");
    }
}


