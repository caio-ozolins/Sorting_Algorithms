#ifndef SORTING_ALGORITHMS_SORTING_H
#define SORTING_ALGORITHMS_SORTING_H

void insertionSort(int array[], int lengthArray);
void quicksort(int array[], int lengthArray);
void quicksortRecursion(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int* x, int* y);
void selectionSort(int array[], int lengthArray);
void bubbleSort(int array[], int lengthArray);

#endif //SORTING_ALGORITHMS_SORTING_H
