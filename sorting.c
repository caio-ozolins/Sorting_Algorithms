#include "sorting.h"

#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int lengthArray){
    for (int i = 1; i < lengthArray; ++i) { // O primeiro elemento já é considerado ordenado
        int aux = array[i]; // Variavel auxiliar recebe o valor do elemento
        int j = i - 1; // Define j como o indice a esquerda do elemnto atual
        while (j >= 0 && array[j] > aux){ // Move os elementos para direita caso sejam maiores que aux, para depois que chegar no primeiro elemento
            array[j + 1] = array[j]; // Move o elemento pra direita
            j--;
        }
        array[j + 1] = aux; // Coloca aux no local correto
    }
}
void quicksort(int array[], int lengthArray){ // Função criada por comodidade (só é necessário passar o array e tamanho do array)
    srand(time(NULL));
    quicksortRecursion(array, 0, lengthArray - 1);
}
void quicksortRecursion(int array[], int low, int high){
    if (low < high){
        int pivotIndex = partition(array, low, high); // Particiona o array e retorna a posição do pivo
        quicksortRecursion(array, low, pivotIndex - 1); // Faz o quicksort a esquerda do pivo
        quicksortRecursion(array, pivotIndex + 1, high); // Faz o quicksort à direita do pivo
    }
}
int partition(int array[], int low, int high){
    int pivotIndex = low + (rand() % (high - low)); // Escolhe um elemento aleatório (entre low e high) para ser o pivo

    if (pivotIndex != high)
        swap(&array[pivotIndex], &array[high]); // Troca o pivo de lugar com o último elemento da partição atual

    int pivotValue = array[high];

    int i = low; // Variavel criada para guardar a posição que começa os valores maiores que o pivo
    for (int j = low; j < high; ++j) {
        if (array[j] <= pivotValue) { // Coloca os valores menores ou iguais ao pivo a esquerda
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]); // Como sabemos que a variavel i é o começo dos números maiores que o pivo trocamos ela de lugar com o pivo

    return i; // agora i contém a posição do pivo
}
void swap(int* x, int* y){ // Troca dois valores de lugar
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int array[], int lengthArray){
    for (int i = 0; i < lengthArray - 1; ++i) { // No final o último elemento é ordenado automaticamente
        int lowestIndex = i; // Assume que i é o menor elemento da seção não ordenada
        for (int j = i + 1; j < lengthArray; ++j) {
            if (array[j] < array[lowestIndex])
                lowestIndex = j; // Muda a variavel caso encontre um valor menor que o atual
        }
        if (lowestIndex != i) // Troca os valores de lugar se necessário
            swap(&array[i], &array[lowestIndex]);
    }
}
void bubbleSort(int array[], int lengthArray){
    int hasSwapped;
    int i = 0;
    do {
        hasSwapped = 0;
        for (int j = 0; j < lengthArray - 1 - i; ++j) { // -1, pois não existe um elemento à direita do último para comparação, -i, pois no final de cada passada o último número sempre vai estar ordenado
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j + 1]);
                hasSwapped = 1; // avisa que ouve uma troca
            }
        }
        i++;
    } while (hasSwapped); // Para o algoritmo caso o array já esteja ordenado
}