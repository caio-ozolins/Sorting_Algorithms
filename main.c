#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int array[ARRAY_LENGTH];

    // Cria um array com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = rand()%10;
    }

    printf("Lista Original: ");
    printArray(array);

    return 0;
}

void printArray(int a[]){
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        printf("[%d] ", a[i]);
    }
}