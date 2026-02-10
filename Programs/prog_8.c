# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int c , s ;


void randomarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; 
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
     s  ++;
}

void  bubblesort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])  {

                swap(&arr[j], &arr[j + 1]);
            }
        }
            }
        }

void insertionsort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            c++;
            arr[j + 1] = arr[j];
            j--;
            s++;
        }
        arr[j + 1] = key;
    }
    }


void selectionsort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
  
        
        for (int j = i + 1; j < size; j++) {
            c++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
        swap(&arr[i], &arr[min_index]);

        }    
    }
    }

void merge(int arr[], int l, int m, int r){
 int i, j, k;
 int a = m - l + 1;
 int b = r - m;
 int L[a], R[b];

 for (i = 0; i < a; i++){
    L[i] = arr[l + i];
    }

for (j = 0; j < b; j++){
    R[j] = arr[m + 1 + j];
    }

i=0;
j=0;
k=l;
while (i < a && j < b){
     c++ ;
    if (L[i] <= R[j]){
        arr[k] = L[i];
        i++;
       
    }
    else{
        arr[k] = R[j];
        j++;
    }
    s++ ;
    k++;
}
while (i < a){
    arr[k] = L[i];
    i++;
    k++;
    s++;
    }

while (j < b){
    arr[k] = R[j];
    j++;
    k++;
    s++;
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
 
    printf("\nTotal comparison: %d\n", c);
    printf("Total swap: %d\n", s);
}




