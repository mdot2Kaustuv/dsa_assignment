# Documentation for `prog_5.c`

## Graph Traversal Using BFS and DFS

This program demonstrates two fundamental graph traversal techniques: **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**. BFS visits vertices level by level, while DFS explores as deeply as possible along each branch before backtracking.

---

## (a) Data Structures Used

### 1. Graph – Adjacency Matrix

```c
int graph[MAX][MAX];
```

**Description:**

* A 2D array representing connections between vertices.
* `graph[i][j] = 1` indicates an edge between vertex `i` and vertex `j`.
* `graph[i][j] = 0` indicates no edge.
* Since the graph is **undirected**, the matrix is symmetric.

**Example (3 vertices: 0, 1, 2):**

Adjacency Matrix:

```
    0  1  2
0 [ 0  1  1 ]
1 [ 1  0  1 ]
2 [ 1  1  0 ]
```

---

### 2. Visited Array

```c
int visited[MAX];
```

**Description:**

* Tracks whether a vertex has been visited during traversal.
* `visited[i] = 0` → not visited
* `visited[i] = 1` → visited

**Purpose:**

* Prevents revisiting the same vertex.
* Avoids infinite loops in cyclic graphs.

---

## (b) Description of Functions

### 1. `void addedge(int graph[MAX][MAX], int i, int j)`

**Purpose:** Adds an undirected edge between two vertices.

**Working:**

* Sets `graph[i][j] = 1`
* Sets `graph[j][i] = 1`

**Time Complexity:** `O(1)`

---

### 2. `void displaygraph(int graph[MAX][MAX], int n)`

**Purpose:** Displays the adjacency matrix.

**Working:**

* Uses nested loops to print the matrix row by row.

**Time Complexity:** `O(V²)`

---

### 3. `void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n)`

**Purpose:** Performs Breadth-First Search traversal.

**Working:**

1. Initialize a queue with `front` and `rear` indices.
2. Mark the starting vertex as visited and enqueue it.
3. While the queue is not empty:

   * Dequeue a vertex and print it.
   * Visit all unvisited adjacent vertices, mark them visited, and enqueue them.

**Illustration:**

```
BFS from vertex 0:
0 → 1 → 2 → 3 → 4
```

**Time Complexity:** `O(V²)` (adjacency matrix)

**Space Complexity:** `O(V)`

---

### 4. `void dfs(int graph[MAX][MAX], int visited[MAX], int current, int n)`

**Purpose:** Performs Depth-First Search traversal.

**Working:**

1. Mark the current vertex as visited and print it.
2. For each adjacent unvisited vertex:

   * Recursively call `dfs()`.
3. Uses recursion and backtracking to explore all paths.

**Illustration:**

```
DFS from vertex 0:
0 → 1 → 3 → 4 → 2
```

**Time Complexity:** `O(V²)`

**Space Complexity:** `O(V)` (recursion stack)

---

## (c) Organization of `main()` Function

1. Initialize the adjacency matrix and visited array.
2. Define the number of vertices (`n = 5`).
3. Add edges to construct the graph.
4. Display the adjacency matrix.
5. Perform BFS starting from vertex 0.
6. Reset the visited array.
7. Perform DFS starting from vertex 0.
8. Terminate the program successfully.

---

## (d) Sample Output

```
0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 1
0 1 1 1 0

BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2
```
