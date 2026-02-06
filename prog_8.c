# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void randomarray(int arr[], int size) {
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; 
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
            }
            }
            }

void insertionsort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    }


void selectionsort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}



int main(){
    int size = 10;
    int arr[size];
    randomarray(arr, size);
    printf("\n Unsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    bubblesort(arr, size);
    printf("\n Sorted array(Bubble sort): \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    randomarray(arr, size);
    printf("\nUnsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    insertionsort(arr, size);
    printf("\nSorted array(Insertion sort): \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    randomarray(arr, size);
    printf("\nUnsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    selectionsort(arr, size);
    printf("Sorted array(Selection sort): \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}




