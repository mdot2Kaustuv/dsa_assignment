#include <stdio.h>

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swapNumbers(&arr[i], &arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swapNumbers(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildMinHeap(int arr[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMin(arr, n, i);
    }
}

void buildMaxHeap(int arr[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapifyMax(arr, n, i);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int original[n];
    int minHeap[n];
    int maxHeap[n];

    printf("Enter %d elements (unsorted): ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &original[i]);
    }

    for (i = 0; i < n; i++)
    {
        minHeap[i] = original[i];
        maxHeap[i] = original[i];
    }

    buildMinHeap(minHeap, n);
    buildMaxHeap(maxHeap, n);

    printf("\nOriginal Array: ");
    printArray(original, n);

    printf("Min Heap Array: ");
    printArray(minHeap, n);

    printf("Max Heap Array: ");
    printArray(maxHeap, n);

    return 0;
}