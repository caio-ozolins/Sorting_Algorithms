#include "main.h"
#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int array[ARRAY_LENGTH];
    int sortAlg = 0;

    // Cria um array com números aleatórios
    srand(time(NULL));
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = rand()%21;
    }

    printf("Original: ");
    printArray(array);

    printf("\nChoose a sorting algorithm: \n");
    printf("1. Insertion Sort\n2. Quicksort\n3. Selection Sort\n");
    scanf("%d", &sortAlg);
    printf("\n");

    switch (sortAlg) {
        case 1:
            insertionSort(array, ARRAY_LENGTH);
            break;
        case 2:
            quicksort(array, ARRAY_LENGTH);
            break;
        case 3:
            selectionSort(array, ARRAY_LENGTH);
            break;
        default:
            printf("Invalid input.");
            return 1;
    }

    printf("Sorted: ");
    printArray(array);

    return 0;
}

void printArray(int a[]){
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        printf("[%d] ", a[i]);
    }
    printf("\n");
}