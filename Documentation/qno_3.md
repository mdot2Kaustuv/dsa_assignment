# Documentation for prog_3.c
## Reverse a Singly Linked List
This program reverses a singly linked list by changing the direction of all the links. For example, if the original list is `1 → 2 → 3 → 4`, the reversed list will be `4 → 3 → 2 → 1`.

---

## (a) Data Structures Used

This program uses a **singly linked list** as the main data structure. A linked list is a collection of nodes where each node contains data and a pointer to the next node.

### Node Structure
```c

struct Node {

&nbsp;   int data;

&nbsp;   struct Node\* next;

};

```

**Components:**
- `data`: An integer that stores the value in the node.
- `next`: A pointer that points to the next node in the list. If it points to `NULL`, it means this is the last node.

**What is a Singly Linked List:**
- A linked list is like a chain where each element (node) is connected to the next one.
- Unlike arrays where elements are stored next to each other in memory, linked list nodes can be anywhere in memory.
- We access elements by following the links from one node to the next.

**Visual representation:**
```

Before reversal:

head → \[1|next] → \[2|next] → \[3|next] → \[4|NULL]



After reversal:

head → \[4|next] → \[3|next] → \[2|next] → \[1|NULL]

```

---

## (b) Description of Functions Implemented

### 1. `struct Node\* createNode(int new\_data)`
**Purpose:** Create a new node with the given data value.

**Parameters:**
- `new\_data`: The integer value to store in the new node

**Returns:**
- Pointer to the newly created node

**Working:**
1. Uses `malloc()` to allocate memory for a new node.
2. Sets the `data` field to `new\_data`.
3. Sets the `next` pointer to `NULL` (no next node yet).
4. Returns the pointer to the new node.

**Time Complexity:** `O(1)` - constant time to create a node.

---

### 2. `struct Node\* reverse(struct Node \*head)`
**Purpose:** Reverse the entire linked list by changing the direction of all links.

**Parameters:**
- `head`: Pointer to the first node of the original list

**Returns:**
- Pointer to the new head (which was the last node before reversing)

**Working:**
1. Uses three pointers to reverse the links:
   - `prev`: Points to the previous node (starts as `NULL`)
   - `current`: Points to the current node being processed (starts at `head`)
   - `next`: Temporarily stores the next node (so we don't lose the rest of the list)
2. Loops through the list until `current` becomes `NULL`:
   - Saves the next node: `next = current->next`
   - Reverses the current link: `current->next = prev` (makes current point backward)
   - Moves `prev` forward: `prev = current`
   - Moves `current` forward: `current = next`
3. Returns `prev`, which now points to the new head (the old last node).

**Visual step-by-step:**
```

Original: 1 → 2 → 3 → 4 → NULL



Iteration 1:

&nbsp; prev=NULL, current=1, next=2

&nbsp; Reverse: 1 → NULL

&nbsp; Result: NULL ← 1    2 → 3 → 4 → NULL



Iteration 2:

&nbsp; prev=1, current=2, next=3

&nbsp; Reverse: 2 → 1

&nbsp; Result: NULL ← 1 ← 2    3 → 4 → NULL



Iteration 3:

&nbsp; prev=2, current=3, next=4

&nbsp; Reverse: 3 → 2

&nbsp; Result: NULL ← 1 ← 2 ← 3    4 → NULL



Iteration 4:

&nbsp; prev=3, current=4, next=NULL

&nbsp; Reverse: 4 → 3

&nbsp; Result: NULL ← 1 ← 2 ← 3 ← 4



Final: Return prev (which points to 4)

```

**Time Complexity:** `O(n)` where `n` is the number of nodes. We visit each node exactly once.

**Space Complexity:** `O(1)` - we only use three pointers, no extra space for nodes.

---

### 3. `void printlist(struct Node \*node)`
**Purpose:** Print all the values in the linked list from start to end.

**Parameters:**
- `node`: Pointer to the first node of the list

**Working:**
1. Starts from the given node.
2. Loops while `node` is not `NULL`:
   - Prints the `data` value of the current node.
   - Moves to the next node: `node = node->next`.
3. Stops when it reaches the end of the list (`NULL`).

**Time Complexity:** `O(n)` where `n` is the number of nodes. We visit each node once to print it.

---

## (c)  main() Method

The `main()` function is the entry point of the program.

**Working:**
1. **Create the linked list:**
   - Creates the first node with value `1` and assigns it to `head`.
   - Creates the second node with value `2` and links it: `head->next = createNode(2)`.
   - Creates the third node with value `3` and links it: `head->next->next = createNode(3)`.
   - Creates the fourth node with value `4` and links it: `head->next->next->next = createNode(4)`.
   - Result: `1 → 2 → 3 → 4 → NULL`

2. **Reverse the list:**
   - Calls `reverse(head)` which reverses all the links.
   - Updates `head` to point to the new first node (which was `4`).
   - Result: `4 → 3 → 2 → 1 → NULL`

3. **Print the reversed list:**
   - Calls `printlist(head)` to display all values in the reversed list.

4. Returns `0` to indicate successful program completion.

---

## (d) Sample Output

```

&nbsp;4 

&nbsp;3 

&nbsp;2 

&nbsp;1 

```

**Explanation:**

**Original list:** `1 → 2 → 3 → 4`

**After reversal:** `4 → 3 → 2 → 1`
