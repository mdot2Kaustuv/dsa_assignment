# include <stdio.h>
# include <stdlib.h>
# include <time.h>


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

void  bubblesort(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])  {
                count++;
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
        else {
        swap(&arr[i], &arr[min_index]);

        }    
    }
    }
    }

void merge(int arr[], int l, int m, int r){
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 int L[n1], R[n2];

 for (i = 0; i < n1; i++){
    L[i] = arr[l + i];
    }

for (j = 0; j < n2; j++){
    R[j] = arr[m + 1 + j];
    }

i=0;
j=0;
k=l;
while (i < n1 && j < n2){
    if (L[i] <= R[j]){
        arr[k] = L[i];
        i++;
    }
    else{
        arr[k] = R[j];
        j++;
    }
    k++;
}
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);      
        mergesort(arr, m + 1, r); 
        merge(arr, l, m, r);       
    }
}


int main(){
    int size = 10;
    int arr[size];
    randomarray(arr, size);
    printf("\nUnsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    bubblesort(arr, size);
    printf("\nSorted array(Bubble sort): \n");
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
    printf("\nSorted array(Selection sort): \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    randomarray(arr, size);
    printf("\nUnsorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    mergesort(arr, 0, size - 1);
    printf("\nSorted array(Merge sort): \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}




