#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define VERMELHO 1
#define VERDE 0
#define AMARELO -1
#define NUM_RUAS 4
#define NUM_CARROS 2
    
struct Sinal{
    int rua;
    int estado;
};

struct Carro{
    char nome[50];
    int rua;
};

struct Sinal sinal[5] = {{0,10},{1, 10}, {1, 10},{1, 10},{1, 10}};
int rua[5] = {32, 32, 32, 32, 32};
int ruaH[2] = {32,32};
int ruaV[4] = {32, 32, 32, 32};
int cont = 0;
int cor1 = 39;
int cor2 = 39;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* transito(void* param) {
    
    int numeroAleatorio = rand() % 2;
    
    if(numeroAleatorio == 0){
        while(1){
            if(cont == 2){
                break;
            }
            sinal[2].estado = VERDE;
            sinal[4].estado = VERDE;
            sinal[1].estado = VERMELHO;
            sinal[3].estado = VERMELHO;
            sleep(3);
            sinal[2].estado = AMARELO;
            sinal[4].estado = AMARELO;
            sinal[1].estado = VERMELHO;
            sinal[3].estado = VERMELHO;
            sleep(1);
            sinal[2].estado = VERMELHO;
            sinal[4].estado = VERMELHO;
            sinal[1].estado = VERDE;
            sinal[3].estado = VERDE;  
            sleep(3);
            sinal[2].estado = VERMELHO;
            sinal[4].estado = VERMELHO;
            sinal[1].estado = AMARELO;
            sinal[3].estado = AMARELO;
            sleep(1);
        }
    }else{
        while(1){
            if(cont == 2){
                break;
            }
            sinal[2].estado = VERMELHO;
            sinal[4].estado = VERMELHO;
            sinal[1].estado = VERDE;
            sinal[3].estado = VERDE;  
            sleep(3);
            sinal[2].estado = VERMELHO;
            sinal[4].estado = VERMELHO;
            sinal[1].estado = AMARELO;
            sinal[3].estado = AMARELO;
            sleep(1);
            sinal[2].estado = VERDE;
            sinal[4].estado = VERDE;
            sinal[1].estado = VERMELHO;
            sinal[3].estado = VERMELHO;
            sleep(3);
            sinal[2].estado = AMARELO;
            sinal[4].estado = AMARELO;
            sinal[1].estado = VERMELHO;
            sinal[3].estado = VERMELHO;
            sleep(1);
        }
    }
}

void* func(void* param) {
    struct Carro* carro = (struct Carro*)param;
    
    int verSinal = carro->rua;

    pthread_mutex_lock(&mutex);
    
    retorno:
    if(sinal[verSinal].estado == VERDE){
        if(verSinal == 1){
            cor1 = 32; cor2 = 31;
            for (int i = 0; i < 4; i++) {
                rua[1] = 32;
                ruaV[i] = 67;
                system("clear");
                printf("\n\n");
                printf("               rua 1\n");
                printf("             +      +\n");
                printf("             |   %c  |\n", rua[1]);
                printf("             +------+\n");
                printf("             |   %c  |\n", ruaV[0]);
                printf("      +--+---+\033[%dm------\033[39m+---+--+\n", cor1);
                printf("rua 4 |   %c  \033[%dm|\033[39m   %c  |  %c   |rua 2 \n", rua[4], cor2, ruaV[1], rua[2]);
                printf("      +--+---+------+---+--+\n");
                printf("             |   %c  |\n", ruaV[2]);
                printf("             +------+\n");
                printf("             |   %c  |\n", ruaV[3]);
                printf("             +      +\n");
                printf("               rua 3\n\n\n");
                ruaV[i] = 32;
                usleep(299000);
            }
            rua[3] = 67;
        }
        if(verSinal == 3){
            cor1 = 32; cor2 = 31;
            for (int i = 0; i < 4; i++) {
                ruaV[i] = 67;
                rua[3] = 32;
                system("clear");
                printf("\n\n");
                printf("               rua 1\n");
                printf("             +      +\n");
                printf("             |   %c  |\n", ruaV[3]);
                printf("             +------+\n");
                printf("             |   %c  |\n", ruaV[2]);
                printf("      +--+---+\033[%dm------\033[39m+---+--+\n", cor1);
                printf("rua 4 |   %c  \033[%dm|\033[39m   %c  |  %c   |rua 2 \n", rua[4], cor2, ruaV[1], rua[2]);
                printf("      +--+---+------+---+--+\n");
                printf("             |   %c  |\n", ruaV[0]);
                printf("             +------+\n");
                printf("             |   %c  |\n", rua[3]);
                printf("             +      +\n");
                printf("               rua 3\n\n\n");
                ruaV[i] = 32;
                usleep(299000);
            }
            rua[1] = 67;
        }
        if(verSinal == 4){
            cor1 = 31; cor2 = 32;
            for (int i = 0; i < 2; i++) {
                ruaH[i] = 67;
                rua[4] = 32;
                system("clear");
                printf("\n\n");
                printf("               rua 1\n");
                printf("             +      +\n");
                printf("             |   %c  |\n", rua[1]);
                printf("             +------+\n");
                printf("             |      |\n");
                printf("      +--+---+\033[%dm------\033[39m+---+--+\n", cor1);
                printf("rua 4 |   %c  \033[%dm|\033[39m   %c  |  %c   |rua 2 \n", rua[4], cor2, ruaH[0], ruaH[1]);
                printf("      +--+---+------+---+--+\n");
                printf("             |      |\n");
                printf("             +------+\n");
                printf("             |   %c  |\n", rua[3]);
                printf("             +      +\n");
                printf("               rua 3\n\n\n");
                ruaH[i] = 32;
                usleep(299000);
            }
            rua[2] = 67;
        }
        if(verSinal == 2){
            cor1 = 31; cor2 = 32;
            for (int i = 0; i < 2; i++) {
                ruaH[i] = 67;
                rua[2] = 32;
                system("clear");
                printf("\n\n");
                printf("               rua 1\n");
                printf("             +      +\n");
                printf("             |   %c  |\n", rua[1]);
                printf("             +------+\n");
                printf("             |      |\n");
                printf("      +--+---+\033[%dm------\033[39m+---+--+\n", cor1);
                printf("rua 4 |   %c  \033[%dm|\033[39m   %c  |  %c   |rua 2 \n", ruaH[1], cor2, ruaH[0], rua[2]);
                printf("      +--+---+------+---+--+\n");
                printf("             |      |\n");
                printf("             +------+\n");
                printf("             |   %c  |\n", rua[3]);
                printf("             +      +\n");
                printf("               rua 3\n\n\n");
                ruaH[i] = 32;
                usleep(299000);
            }
            rua[4] = 67;
        }
        
        cor1 = 39; cor2 = 39;
        
        pthread_mutex_unlock(&mutex);
        cont++;
    }else{
        goto retorno;
    }
    return NULL;
}

int main() {
    
    while(1){
        pthread_t carro1, carro2, transit;
    
        for (int i = 0; i < 5; i++) {
            rua[i] = 32;
        }
        cont = 0;
        
        int numeros1[NUM_RUAS/2] = {1, 3};
        int numeros2[NUM_RUAS/2] = {2, 4};
        
        int indice1, indice2;
    
        srand(time(NULL));
        
        int i = rand() % 2;
        int f = rand() % 2;
        
        indice1 = numeros1[i];
        indice2 = numeros2[f];
        
        struct Carro Carro1 = {"Fusca", indice1};
        struct Carro Carro2 = {"Civic", indice2};
        
        rua[indice1] = 67;
        rua[indice2] = 67;
        
        system("clear");
        printf("\n\n");
        printf("               rua 1\n");
        printf("             +      +\n");
        printf("             |   %c  |\n", rua[1]);
        printf("             +------+\n");
        printf("             |      |\n");
        printf("      +--+---+\033[%dm------\033[39m+---+--+\n", cor1);
        printf("rua 4 |  %c   \033[%dm|\033[39m   %c   |  %c   |rua 2 \n", rua[4], cor2, rua[0], rua[2]);
        printf("      +--+---+------+---+--+\n");
        printf("             |      |\n");
        printf("             +------+\n");
        printf("             |   %c  |\n", rua[3]);
        printf("             +      +\n");
        printf("               rua 3\n\n\n");
        usleep(299000);
        
        pthread_create(&carro1, NULL, func, &Carro1);
        pthread_create(&carro2, NULL, func, &Carro2);
        pthread_create(&transit, NULL, transito, NULL);
        
        pthread_join(transit, NULL);
        pthread_join(carro1, NULL);
        pthread_join(carro2, NULL);
        
    }
    exit(EXIT_SUCCESS);
}
