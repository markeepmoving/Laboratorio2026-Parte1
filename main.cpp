#include <iostream>
#include "funciones.h"

int main() {


    printf("Bienvenido al Juego de SIMON ver. 1.0.\n");
    printf("Ingrese su nombre (fin=fin del juego): ");

    char nombre[15];

    scanf("%s", nombre);

    bool Fin=false;
    Fin=verificarNombre(nombre);

    if (!Fin) {
        printf("\n Ingrese nivel del Juego (p, i, a): ");
        char nivel;
        scanf(" %c", &nivel);

        while (nivel!='p'&& nivel!='P'&& nivel!='i'&& nivel!='I'&& nivel!='a'&& nivel!='A') {

            printf("\n Nivel de juego no es valido, vuelva a intentarlo: ");
            scanf(" %c", &nivel);
        }

        printf(" \n Pulse <enter> para comenzar el juego.");
        getchar();
        getchar();


        jugar(nombre, nivel);
    }

    if (Fin) {
        printf("\n Finalizando juego...");

    }

}

bool verificarNombre(char nombre[]) {

    if (nombre[0]=='f' || nombre[0]=='F' && nombre[1]=='i' || nombre[1]=='I' && nombre[2]=='n' || nombre[2]=='N'  && nombre[3]=='\0') {
        return true;
    }
    return false;
}
