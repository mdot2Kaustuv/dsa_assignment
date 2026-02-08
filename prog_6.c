#include <stdio.h>
#include <stdlib.h>
#define MAX 100



void randomarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; 
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

void makeminheap(int arr[], int n, int i) {
    int smallest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest]) {
       smallest = right;
    }
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        makeminheap(arr, n, smallest);
    }
    }

void makemaxheap(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) {
       largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
      largest = right;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        makemaxheap(arr, n, largest);
    }

}

void minheapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
       makeminheap(arr, n, i);
    }
     for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);      // move min to end
        makeminheap(arr, i, 0);      // heapify reduced heap
    }
}


void maxheapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
       makemaxheap(arr, n, i);
    } 
        for (int i = n - 1; i > 0; i--) {
            swap(&arr[0], &arr[i]);      
            makemaxheap(arr, i, 0);      

    }
    }

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
       printf("%d ", arr[i]);
    }
       printf("\n");
    }

int main() {
    int size = 10;
    int minarr[size];
    int maxarr[size];
    int arr[size];
    randomarray(arr, size);
    printf("Original array: \n");
    printarray(arr, size);
    for (int i = 0; i < size; i++) {
        minarr[i] = arr[i];
        maxarr[i] = arr[i];
    }
    minheapsort(minarr, size);
    printf("\nMin Heap Sorted array: \n");
    printarray(minarr, size);
    maxheapsort(maxarr, size);
    printf("\nMax Heap Sorted array: \n");
    printarray(maxarr, size);
    return 0;
}
