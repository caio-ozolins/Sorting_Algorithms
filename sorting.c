#include "sorting.h"

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