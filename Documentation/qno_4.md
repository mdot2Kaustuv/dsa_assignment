# Documentation for prog_4.c
## Doubly Linked List - Insert and Delete Operations
This program demonstrates insertion and deletion operations in a doubly linked list. Unlike a singly linked list that can only move forward, a doubly linked list can move both forward and backward because each node has pointers to both the next and previous nodes.

---

## (a) Data Structures Used

This program uses a **doubly linked list** as the main data structure. In a doubly linked list, each node has connections in both directions, making it easier to navigate and perform operations.

### Node Structure
```c
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
```

**Components:**
- `data`: An integer that stores the value in the node.
- `next`: A pointer that points to the next node in the forward direction.
- `prev`: A pointer that points to the previous node in the backward direction.

**What is a Doubly Linked List:**
- Each node is connected to both the next node and the previous node.
- We can traverse the list in both directions (forward and backward).
- The first node's `prev` points to `NULL`, and the last node's `next` points to `NULL`.

**Visual representation:**
```
NULL ← [10|next] ↔ [20|next] ↔ [30|next] ↔ [40|next] → NULL
       prev              prev         prev         prev
```

**Advantages over singly linked list:**
- Can traverse in both directions
- Easier to delete a node (we can access the previous node directly)
- Can insert before a node easily

**Disadvantages:**
- Uses more memory (extra pointer in each node)
- More pointers to update during insertion/deletion

---

## (b) Description of Functions Implemented

### 1. `struct Node* createNode(int data)`
**Purpose:** Create a new node with the given data value.

**Parameters:**
- `data`: The integer value to store in the node

**Returns:**
- Pointer to the newly created node

**Working:**
1. Uses `malloc()` to allocate memory for a new node.
2. Sets the `data` field to the given value.
3. Sets both `next` and `prev` to `NULL` (no connections yet).
4. Returns the pointer to the new node.

**Time Complexity:** `O(1)` - constant time to create a node.

---

### 2. `void printlist(struct Node *node)`
**Purpose:** Print all values in the list from start to end.

**Parameters:**
- `node`: Pointer to the first node

**Working:**
1. Starts from the given node.
2. Loops while `node` is not `NULL`:
   - Prints the `data` value.
   - Moves to the next node: `node = node->next`.

**Time Complexity:** `O(n)` where `n` is the number of nodes.

---

### 3. `void addnodeafter(int data, struct Node* prev_node)`
**Purpose:** Insert a new node with the given data after a specified node.

**Parameters:**
- `data`: Value for the new node
- `prev_node`: The node after which we want to insert

**Working:**
1. **Safety check:** If `prev_node` is `NULL`, prints an error message and returns.
2. Creates a new node with the given data.
3. **Links the new node:**
   - Sets `newNode->next = prev_node->next` (new node points to what prev_node was pointing to).
   - Sets `prev_node->next = newNode` (prev_node now points to new node).
   - Sets `newNode->prev = prev_node` (new node points back to prev_node).
   - If there's a node after the new node: Sets `newNode->next->prev = newNode` (that node points back to new node).

**Visual example:**
```
Before insertion:
10 ↔ 20 ↔ 30

Insert 25 after 20:

Step 1: newNode->next = 30
        10 ↔ 20    25 → 30

Step 2: 20->next = 25
        10 ↔ 20 → 25 → 30

Step 3: 25->prev = 20
        10 ↔ 20 ↔ 25 → 30

Step 4: 30->prev = 25
        10 ↔ 20 ↔ 25 ↔ 30
```

**Time Complexity:** `O(1)` - constant time insertion (if we already have the pointer to prev_node).

---

### 4. `struct Node* deletenode(struct Node* head, int data)`
**Purpose:** Delete the first node that contains the specified data value.

**Parameters:**
- `head`: Pointer to the first node
- `data`: Value to search for and delete

**Returns:**
- Pointer to the head (may change if we delete the first node)

**Working:**
1. **Search for the node:**
   - Starts from `head` and loops through the list.
   - Compares each node's data with the target data.
   - Stops when found or reaches the end.

2. **If node not found:**
   - Returns the original `head` unchanged.

3. **If deleting the head node:**
   - Moves `head` to the next node: `head = head->next`.
   - If the new head exists: Sets `head->prev = NULL`.
   - Frees the memory of the old head.
   - Returns the new head.

4. **If deleting a middle or end node:**
   - Links the previous node to the next node: `temp->next = deletednode->next`.
   - If there's a node after: Links it back: `deletednode->next->prev = temp`.
   - Frees the memory of the deleted node.
   - Returns the head.

**Visual example (deleting 20):**
```
Before:
10 ↔ 20 ↔ 30 ↔ 40

Steps:
1. Find node with data = 20
2. Link 10's next to 30: 10 → 30
3. Link 30's prev to 10: 10 ← 30
4. Free node 20

After:
10 ↔ 30 ↔ 40
```

**Time Complexity:** `O(n)` where `n` is the number of nodes. We may need to search through the entire list.

---

## (c) Organization of main() Method

The `main()` function is the entry point of the program.

**Working:**
1. **Create the initial list:**
   - Creates four nodes with values `10`, `20`, `30`, and `50`.
   - Links them together manually:
     - `head->next = second`, `second->prev = head`
     - `second->next = third`, `third->prev = second`
     - `third->next = fourth`, `fourth->prev = third`
   - Result: `10 ↔ 20 ↔ 30 ↔ 50`

2. **Print original list:**
   - Prints message: `"Original linked list: "`
   - Calls `printlist(head)` to show: `10 20 30 50`

3. **Insert operation:**
   - Prints message: `"Linked list after insertion: "`
   - Calls `addnodeafter(40, third)` to insert `40` after the third node (which contains `30`).
   - Calls `printlist(head)` to show: `10 20 30 40 50`

4. **Delete operation:**
   - Prints message: `"Linked list after deletion: "`
   - Calls `deletenode(head, 20)` to delete the node containing `20`.
   - Updates `head` with the returned value (in case the first node was deleted).
   - Calls `printlist(head)` to show: `10 30 40 50`

5. Returns `0` to indicate successful program completion.

---

## (d) Sample Output

```
Original linked list: 10 
 20 
 30 
 50 
 Linked list after insertion: 10 
 20 
 30 
 40 
 50 
 Linked list after deletion: 10 
 30 
 40 
 50 
```

**Explanation:**

**Original list:** `10 ↔ 20 ↔ 30 ↔ 50`
- Started with four nodes

**After insertion:** `10 ↔ 20 ↔ 30 ↔ 40 ↔ 50`
- Inserted 40 after node 30
- Now the list is in complete sequence

**After deletion:** `10 ↔ 30 ↔ 40 ↔ 50`
- Deleted the node containing 20
- The remaining nodes are still properly linked
- Node 10 now directly connects to node 30
