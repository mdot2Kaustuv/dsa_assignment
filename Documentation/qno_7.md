# Documentation for prog_7.c
## Build Min Heap and Max Heap from User Input
This program takes numbers from the user and converts them into two types of heaps: a min heap (smallest element at root) and a max heap (largest element at root). It demonstrates how the same data can be organized into different heap structures.

---

## (a) Data Structures Used

This program uses **arrays** to store user input and the two heap representations.

### Arrays
```c
int original[n];    
int minHeap[n];     
int maxHeap[n];    
```

**What is a Heap:**
A heap is a complete binary tree with special ordering properties, stored efficiently in an array.

**Min Heap Property:**
- Every parent node is smaller than or equal to its children
- The smallest element is always at the root (index 0)

**Max Heap Property:**
- Every parent node is larger than or equal to its children
- The largest element is always at the root (index 0)

**Array to Tree Relationship:**
For element at index `i`:
- Left child: `2*i + 1`
- Right child: `2*i + 2`
- Parent: `(i-1)/2`

**Example:**
```
Array: [10, 20, 15, 30, 25]

```

---

## (b) Description of Functions Implemented

### 1. `void swapNumbers(int *a, int *b)`
**Purpose:** Exchange the values of two integers.

**Parameters:**
- `a`: Pointer to first integer
- `b`: Pointer to second integer

**Working:**
- Stores the value of `*a` in a temporary variable.
- Copies the value of `*b` into `*a`.
- Copies the temporary value into `*b`.

**Time Complexity:** `O(1)` - constant time.

---

### 2. `void heapifyMin(int arr[], int n, int i)`
**Purpose:** Fix the min heap property at position `i` and all affected positions below it.

**Parameters:**
- `arr`: The array to heapify
- `n`: Size of the heap
- `i`: Index of the position to heapify

**Working:**
1. Assumes current element at index `i` is the smallest.
2. Calculates left child index: `left = 2*i + 1`
3. Calculates right child index: `right = 2*i + 2`
4. Compares with left child (if it exists):
   - If `arr[left] < arr[smallest]`, updates smallest to left
5. Compares with right child (if it exists):
   - If `arr[right] < arr[smallest]`, updates smallest to right
6. If smallest is not the current index:
   - Swaps `arr[i]` with `arr[smallest]`
   - Recursively calls `heapifyMin()` on the smallest position (to fix any violations below)

**Why recursion?** The swap might violate the heap property further down, so we need to fix it recursively.

**Time Complexity:** `O(log n)` - height of the tree.

---

### 3. `void heapifyMax(int arr[], int n, int i)`
**Purpose:** Fix the max heap property at position `i` and all affected positions below it.

**Parameters:**
- `arr`: The array to heapify
- `n`: Size of the heap
- `i`: Index of the position to heapify

**Working:**
1. Assumes current element at index `i` is the largest.
2. Calculates left child index: `left = 2*i + 1`
3. Calculates right child index: `right = 2*i + 2`
4. Compares with left child (if it exists):
   - If `arr[left] > arr[largest]`, updates largest to left
5. Compares with right child (if it exists):
   - If `arr[right] > arr[largest]`, updates largest to right
6. If largest is not the current index:
   - Swaps `arr[i]` with `arr[largest]`
   - Recursively calls `heapifyMax()` on the largest position

**Time Complexity:** `O(log n)` - height of the tree.

---

### 4. `void buildMinHeap(int arr[], int n)`
**Purpose:** Convert an unsorted array into a min heap.

**Parameters:**
- `arr`: Array to convert into min heap
- `n`: Number of elements

**Working:**
1. Starts from the last non-leaf node at index `n/2 - 1`
   - Why? Nodes after this index are leaves (no children), already valid heaps
2. Goes backwards from `n/2 - 1` to 0
3. Calls `heapifyMin()` on each position
4. By going bottom-up, ensures parent nodes are fixed after their children

**Why bottom-up?** This ensures that when we fix a parent, its children are already valid heaps.

**Time Complexity:** `O(n)` - surprisingly, this is linear time, not O(n log n).

---

### 5. `void buildMaxHeap(int arr[], int n)`
**Purpose:** Convert an unsorted array into a max heap.

**Parameters:**
- `arr`: Array to convert into max heap
- `n`: Number of elements

**Working:**
1. Starts from the last non-leaf node at index `n/2 - 1`
2. Goes backwards from `n/2 - 1` to 0
3. Calls `heapifyMax()` on each position
4. Builds the max heap from bottom to top

**Time Complexity:** `O(n)` - linear time to build a heap.

---

### 6. `void printArray(int arr[], int n)`
**Purpose:** Display all elements in the array.

**Parameters:**
- `arr`: Array to print
- `n`: Number of elements

**Working:**
- Loops through the array using index `i` from 0 to `n-1`
- Prints each element followed by a space

**Time Complexity:** `O(n)`.

---

## (c) Organization of main() Method

The `main()` function is the entry point of the program.

**Working:**
1. **Get array size:**
   - Prompts user: `"Enter number of elements: "`
   - Reads the value into variable `n` using `scanf()`

2. **Declare arrays:**
   - Declares three arrays of size `n`:
     - `original[n]` - to store user input
     - `minHeap[n]` - for min heap version
     - `maxHeap[n]` - for max heap version

3. **Get user input:**
   - Prompts user: `"Enter n elements (unsorted): "`
   - Uses a loop to read `n` integers into the `original` array

4. **Copy data to both heap arrays:**
   - Uses a loop to copy all values from `original` to both `minHeap` and `maxHeap`
   - This allows us to build both heap types from the same data

5. **Build both heaps:**
   - Calls `buildMinHeap(minHeap, n)` to convert minHeap array into min heap
   - Calls `buildMaxHeap(maxHeap, n)` to convert maxHeap array into max heap

6. **Display all three arrays:**
   - Prints `"Original Array: "` and calls `printArray(original, n)`
   - Prints `"Min Heap Array: "` and calls `printArray(minHeap, n)`
   - Prints `"Max Heap Array: "` and calls `printArray(maxHeap, n)`

7. Returns 0 to indicate successful program completion.

---

## (d) Sample Output

**Example 1:**
```
Enter number of elements: 5
Enter 5 elements (unsorted): 10 20 15 30 25

Original Array: 10 20 15 30 25 
Min Heap Array: 10 20 15 30 25 
Max Heap Array: 30 25 15 10 20 
```

**Explanation:**

**Original Array:** `10 20 15 30 25`
- Data as entered by user, no changes

**Min Heap Array:** `10 20 15 30 25`
```

Properties:
- 10 ≤ 20 and 10 ≤ 15 
- 20 ≤ 30 and 20 ≤ 25 

```

**Max Heap Array:** `30 25 15 10 20`
```


Properties:
- 30 ≥ 25 and 30 ≥ 15 
- 25 ≥ 10 and 25 ≥ 20 
- All parents ≥ their children
```

---

**Example 2:**
```
Enter number of elements: 7
Enter 7 elements (unsorted): 4 10 3 5 1 8 6

Original Array: 4 10 3 5 1 8 6 
Min Heap Array: 1 4 3 5 10 8 6 
Max Heap Array: 10 5 8 4 1 3 6 
```

**Explanation:**

**Min Heap:** `1 4 3 5 10 8 6`
- Root is 1 (smallest element in array)
- Every parent is smaller than its children

**Max Heap:** `10 5 8 4 1 3 6`
- Root is 10 (largest element in array)
- Every parent is larger than its children

