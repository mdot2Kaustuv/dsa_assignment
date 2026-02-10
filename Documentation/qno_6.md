# Documentation for prog_6.c
## Heap Sort using Min Heap and Max Heap
This program sorts an array of random numbers using two different heap methods: Min Heap Sort (produces descending order) and Max Heap Sort (produces ascending order). A heap is a special tree structure stored in an array.

---

## (a) Data Structures Used

This program uses **arrays** to store numbers and implement the heap data structure.

### Arrays
```c
int arr[size];       
int minarr[size];   
int maxarr[size];    
```

**What is a Heap:**
A heap is a complete binary tree with a special property, stored in an array:
- **Min Heap:** Every parent node is smaller than or equal to its children (smallest element at root)
- **Max Heap:** Every parent node is larger than or equal to its children (largest element at root)

**Array to Tree Mapping:**
For an element at index `i`:
- Left child is at index: `2*i + 1`
- Right child is at index: `2*i + 2`
- Parent is at index: `(i-1)/2`

**Example of Max Heap:**
```
Array: [50, 30, 20, 15, 10]


```

**Example of Min Heap:**
```
Array: [10, 15, 20, 30, 50]


```

---

## (b) Description of Functions Implemented

### 1. `void randomarray(int arr[], int size)`
**Purpose:** Fill the array with random numbers for testing.

**Parameters:**
- `arr`: The array to fill
- `size`: Number of elements to generate

**Working:**
- Uses a loop to generate `size` random numbers.
- Each number is generated using `rand() % 1000`, giving values from 0 to 999.

**Time Complexity:** `O(n)` where `n` is the size.

---

### 2. `void swap(int* a, int* b)`
**Purpose:** Exchange the values of two integers.

**Parameters:**
- `a`: Pointer to first integer
- `b`: Pointer to second integer

**Working:**
- Uses a temporary variable to store one value.
- Swaps the values through the pointers.

**Time Complexity:** `O(1)` - constant time.

---

### 3. `void makeminheap(int arr[], int n, int i)`
**Purpose:** Maintain the min heap property for the subtree rooted at index `i`.

**Parameters:**
- `arr`: The array
- `n`: Size of the heap
- `i`: Root index of the subtree to heapify

**Working:**
1. Assumes current element is the smallest.
2. Calculates left child index: `2*i + 1`
3. Calculates right child index: `2*i + 2`
4. Compares with left child - if left child is smaller, updates smallest.
5. Compares with right child - if right child is smaller, updates smallest.
6. If smallest is not the current element:
   - Swaps current with smallest.
   - Recursively calls `makeminheap()` on the affected subtree.

**Time Complexity:** `O(log n)` - height of the tree.

---

### 4. `void makemaxheap(int arr[], int n, int i)`
**Purpose:** Maintain the max heap property for the subtree rooted at index `i`.

**Parameters:**
- `arr`: The array
- `n`: Size of the heap
- `i`: Root index of the subtree to heapify

**Working:**
1. Assumes current element is the largest.
2. Calculates left child index: `2*i + 1`
3. Calculates right child index: `2*i + 2`
4. Compares with left child - if left child is larger, updates largest.
5. Compares with right child - if right child is larger, updates largest.
6. If largest is not the current element:
   - Swaps current with largest.
   - Recursively calls `makemaxheap()` on the affected subtree.

**Time Complexity:** `O(log n)` - height of the tree.

---

### 5. `void minheapsort(int arr[], int n)`
**Purpose:** Sort the array in descending order (largest to smallest) using min heap.

**Parameters:**
- `arr`: Array to sort
- `n`: Number of elements

**Working:**
1. **Build Min Heap Phase:**
   - Starts from the last non-leaf node: `n/2 - 1`
   - Goes backwards to index 0
   - Calls `makeminheap()` on each node
   - Result: Smallest element is at the root (index 0)

2. **Sorting Phase:**
   - Runs a loop from `i = n-1` down to `i = 1`:
     - Swaps root (minimum) with element at index `i` (moves min to end)
     - Reduces heap size by 1
     - Calls `makeminheap()` on root to restore heap property
   - After all iterations, array is sorted in descending order

**Why descending?** Because we keep moving the smallest element to the end.

**Time Complexity:** `O(n log n)` - building heap takes O(n), and extracting n elements takes O(n log n).

---

### 6. `void maxheapsort(int arr[], int n)`
**Purpose:** Sort the array in ascending order (smallest to largest) using max heap.

**Parameters:**
- `arr`: Array to sort
- `n`: Number of elements

**Working:**
1. **Build Max Heap Phase:**
   - Starts from the last non-leaf node: `n/2 - 1`
   - Goes backwards to index 0
   - Calls `makemaxheap()` on each node
   - Result: Largest element is at the root (index 0)

2. **Sorting Phase:**
   - Runs a loop from `i = n-1` down to `i = 1`:
     - Swaps root (maximum) with element at index `i` (moves max to end)
     - Reduces heap size by 1
     - Calls `makemaxheap()` on root to restore heap property
   - After all iterations, array is sorted in ascending order

**Why ascending?** Because we keep moving the largest element to the end.

**Time Complexity:** `O(n log n)` - very efficient sorting algorithm.

---

### 7. `void printarray(int arr[], int size)`
**Purpose:** Display all elements in the array.

**Parameters:**
- `arr`: Array to print
- `size`: Number of elements

**Working:**
- Loops through the array and prints each element followed by a space.

**Time Complexity:** `O(n)`.

---

## (c) Organization of main() Method

The `main()` function is the entry point of the program.

**Working:**
1. **Initialize:**
   - Sets `size = 10` for arrays of 10 elements.
   - Declares three arrays: `minarr`, `maxarr`, and `arr`.

2. **Generate random data:**
   - Calls `randomarray(arr, size)` to fill the array with random numbers.

3. **Display original array:**
   - Prints message: `"Original array: "`
   - Calls `printarray(arr, size)` to show the unsorted numbers.

4. **Copy to both arrays:**
   - Uses a loop to copy all values from `arr` to both `minarr` and `maxarr`.
   - This allows us to sort the same data using two different methods.

5. **Sort using min heap:**
   - Calls `minheapsort(minarr, size)`.
   - Prints message: `"Min Heap Sorted array: "`
   - Calls `printarray(minarr, size)` to show the result (descending order).

6. **Sort using max heap:**
   - Calls `maxheapsort(maxarr, size)`.
   - Prints message: `"Max Heap Sorted array: "`
   - Calls `printarray(maxarr, size)` to show the result (ascending order).

7. Returns 0 to indicate successful program completion.

---

## (d) Sample Output

```
Original array: 
383 886 777 915 793 335 386 492 649 421 

Min Heap Sorted array: 
915 886 793 777 649 492 421 386 383 335 

Max Heap Sorted array: 
335 383 386 421 492 649 777 793 886 915 
```

**Explanation:**

**Original Array:**
```
383 886 777 915 793 335 386 492 649 421
```
Random numbers in no particular order.

**Min Heap Sorted (Descending Order):**
```
915 886 793 777 649 492 421 386 383 335
```
Sorted from largest to smallest. The min heap repeatedly extracts the smallest element and places it at the end, resulting in descending order.

**Max Heap Sorted (Ascending Order):**
```
335 383 386 421 492 649 777 793 886 915
```
Sorted from smallest to largest. The max heap repeatedly extracts the largest element and places it at the end, resulting in ascending order.

