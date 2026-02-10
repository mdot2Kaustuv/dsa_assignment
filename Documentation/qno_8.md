# Documentation for prog_8.c
## Comparison of Sorting Algorithms
This program demonstrates and compares four different sorting algorithms: Bubble Sort, Insertion Sort, Selection Sort, and Merge Sort. It sorts random arrays using each method and counts the total number of comparisons and swaps to show their efficiency.

---

## (a) Data Structures Used

This program uses **arrays** and **global counters** to store data and track performance.

### Arrays
```c
int arr[size];
```
A regular integer array to store numbers that need to be sorted.

### Global Counters
```c
int c;  
int s;  
```

**Why global counters:**
- `c` tracks how many times we compare two elements across all sorting algorithms
- `s` tracks how many times we swap or shift elements
- These help us understand which algorithm is more efficient
- Fewer comparisons and swaps = faster algorithm

---

## (b) Description of Functions Implemented

### 1. `void randomarray(int arr[], int size)`
**Purpose:** Fill the array with random numbers for testing.

**Parameters:**
- `arr`: Array to fill
- `size`: Number of elements to generate

**Working:**
- Uses a loop to generate `size` random numbers
- Each number is generated using `rand() % 1000`, giving values from 0 to 999

**Time Complexity:** `O(n)` where n is the size.

---

### 2. `void swap(int* a, int* b)`
**Purpose:** Exchange two numbers and increment the swap counter.

**Parameters:**
- `a`: Pointer to first integer
- `b`: Pointer to second integer

**Working:**
- Uses a temporary variable to swap the values
- Increments the global swap counter `s`

**Time Complexity:** `O(1)` - constant time.

---

### 3. `void bubblesort(int arr[], int size)`
**Purpose:** Sort the array using Bubble Sort algorithm.

**Parameters:**
- `arr`: Array to sort
- `size`: Number of elements

**Working:**
1. Uses two nested loops
2. Outer loop runs `size-1` times (one less than array size)
3. Inner loop compares adjacent elements:
   - Runs from 0 to `size-i-1` (shrinks each iteration because largest elements "bubble" to end)
4. If current element is greater than next element:
   - Swaps them using `swap()` function
5. After each pass, the largest unsorted element is in its correct position

**How it works:**
```
Example: [5, 2, 8, 1]

Pass 1:
Compare 5,2 → Swap → [2, 5, 8, 1]
Compare 5,8 → No swap → [2, 5, 8, 1]
Compare 8,1 → Swap → [2, 5, 1, 8]  (8 is now in correct position)

Pass 2:
Compare 2,5 → No swap
Compare 5,1 → Swap → [2, 1, 5, 8]  (5 is now in correct position)

Pass 3:
Compare 2,1 → Swap → [1, 2, 5, 8]  (sorted!)
```

**Time Complexity:** `O(n²)` - very slow for large arrays

**Characteristics:**
- Simple to understand
- Many swaps
- Inefficient for large datasets

---

### 4. `void insertionsort(int arr[], int n)`
**Purpose:** Sort the array using Insertion Sort algorithm.

**Parameters:**
- `arr`: Array to sort
- `n`: Number of elements

**Working:**
1. Starts from second element (index 1)
2. For each element (key):
   - Compares it with elements before it (going right to left)
   - Shifts larger elements one position to the right
   - Increments comparison counter `c` for each comparison
   - Increments shift counter `s` for each shift
3. Inserts the key at its correct position
4. Repeats for all elements

**How it works:**
```
Example: [5, 2, 8, 1]

Step 1: key = 2
Compare with 5 → Shift 5 right
Insert 2 → [2, 5, 8, 1]

Step 2: key = 8
Compare with 5 → Already in place
Result → [2, 5, 8, 1]

Step 3: key = 1
Compare with 8 → Shift 8 right
Compare with 5 → Shift 5 right
Compare with 2 → Shift 2 right
Insert 1 → [1, 2, 5, 8]
```

**Time Complexity:** `O(n²)` - but faster than bubble sort in practice

**Characteristics:**
- Good for small arrays
- Good for nearly sorted arrays
- Shifts instead of swaps

---

### 5. `void selectionsort(int arr[], int size)`
**Purpose:** Sort the array using Selection Sort algorithm.

**Parameters:**
- `arr`: Array to sort
- `size`: Number of elements

**Working:**
1. Uses two nested loops
2. Outer loop runs `size-1` times
3. For each position `i`:
   - Assumes element at `i` is minimum
   - Inner loop finds the actual minimum in remaining unsorted elements
   - Increments comparison counter `c` for each comparison
   - If minimum is found at a different position, swaps with position `i`
4. After each iteration, one more element is in correct position

**How it works:**
```
Example: [5, 2, 8, 1]

Pass 1:
Find minimum in [5,2,8,1] → 1
Swap with position 0 → [1, 2, 8, 5]

Pass 2:
Find minimum in [2,8,5] → 2
Already in position → [1, 2, 8, 5]

Pass 3:
Find minimum in [8,5] → 5
Swap with position 2 → [1, 2, 5, 8]
```

**Time Complexity:** `O(n²)`

**Characteristics:**
- Makes minimum number of swaps
- Always does same number of comparisons
- Good when swaps are expensive

---

### 6. `void merge(int arr[], int l, int m, int r)`
**Purpose:** Merge two sorted halves of an array into one sorted array.

**Parameters:**
- `arr`: The array containing both halves
- `l`: Left index (start of first half)
- `m`: Middle index (end of first half)
- `r`: Right index (end of second half)

**Working:**
1. Calculates sizes of left and right halves
2. Creates two temporary arrays `L[]` and `R[]`
3. Copies data from `arr` into temporary arrays
4. Merges the two temporary arrays back into `arr`:
   - Compares elements from both arrays (increments `c`)
   - Places smaller element into `arr` (increments `s`)
   - Continues until one array is empty
5. Copies any remaining elements from either array (increments `s` for each)

**Time Complexity:** `O(n)` where n is the total number of elements being merged.

---

### 7. `void mergesort(int arr[], int l, int r)`
**Purpose:** Sort the array using Merge Sort algorithm (divide and conquer).

**Parameters:**
- `arr`: Array to sort
- `l`: Left index (start of portion to sort)
- `r`: Right index (end of portion to sort)

**Working:**
1. **Base case:** If `l < r` (more than one element):
2. Calculates middle index: `m = l + (r-l)/2`
3. **Divide:** Recursively sorts left half: `mergesort(arr, l, m)`
4. **Divide:** Recursively sorts right half: `mergesort(arr, m+1, r)`
5. **Conquer:** Merges the two sorted halves: `merge(arr, l, m, r)`


**Time Complexity:** `O(n log n)` - very efficient!

**Characteristics:**
- Fastest of the four algorithms for large arrays
- Stable sort (maintains relative order of equal elements)
- Requires extra space for temporary arrays
- Predictable performance

---

## (c) Organization of main() Method

The `main()` function is the entry point of the program.

**Working:**
1. **Initialize:**
   - Sets `size = 10` for arrays of 10 elements
   - Declares `int arr[size]`

2. **Test Bubble Sort:**
   - Calls `randomarray(arr, size)` to generate random numbers
   - Prints "Unsorted array: " and displays the array
   - Calls `bubblesort(arr, size)` to sort
   - Prints "Sorted array(Bubble sort): " and displays the result

3. **Test Insertion Sort:**
   - Generates new random array
   - Prints unsorted array
   - Calls `insertionsort(arr, size)` to sort
   - Prints sorted result

4. **Test Selection Sort:**
   - Generates new random array
   - Prints unsorted array
   - Calls `selectionsort(arr, size)` to sort
   - Prints sorted result

5. **Test Merge Sort:**
   - Generates new random array
   - Prints unsorted array
   - Calls `mergesort(arr, 0, size-1)` to sort
   - Prints sorted result

6. **Display statistics:**
   - Prints total number of comparisons: `printf("Total comparison: %d\n", c)`
   - Prints total number of swaps: `printf("Total swap: %d\n", s)`


---

## (d) Sample Output

```
Unsorted array: 
383 886 777 915 793 335 386 492 649 421 
Sorted array(Bubble sort): 
335 383 386 421 492 649 777 793 886 915 

Unsorted array: 
649 421 362 27 690 59 763 926 540 426 
Sorted array(Insertion sort): 
27 59 362 421 426 540 649 690 763 926 

Unsorted array: 
172 736 211 368 567 429 782 530 862 123 
Sorted array(Selection sort): 
123 172 211 368 429 530 567 736 782 862 

Unsorted array: 
67 135 929 802 22 58 69 167 393 456 
Sorted array(Merge sort): 
22 58 67 69 135 167 393 456 802 929 

Total comparison: 89
Total swap: 119
```


**Algorithm Comparison:**

| Algorithm | Time Complexity | Space | Stability | Best For |
|-----------|----------------|-------|-----------|----------|
| Bubble Sort | O(n²) | O(1) | Stable | Teaching, very small arrays |
| Insertion Sort | O(n²) | O(1) | Stable | Small or nearly sorted arrays |
| Selection Sort | O(n²) | O(1) | Unstable | Minimizing swaps |
| Merge Sort | O(n log n) | O(n) | Stable | Large arrays, guaranteed performance |


