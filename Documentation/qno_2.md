# Documentation for `prog_2.c`

## Infix to Postfix Expression Converter Using Stack

This program converts mathematical expressions from **infix notation** (e.g., `a+b*c`) to **postfix notation** (e.g., `abc*+`). It uses a **stack** to correctly handle operator precedence and parentheses during conversion.

---

## (a) Data Structures Used

This program uses a **stack** data structure that follows the **Last-In-First-Out (LIFO)** principle. The stack temporarily stores operators and parentheses during the conversion process.

### Stack Structure

```c
struct Stack {
    char stack[MAX];
    int top;
};
```

**Components:**

* `stack[MAX]`: Character array that stores operators (`+`, `-`, `*`, `/`, `^`) and parentheses.
* `top`: Index of the top element in the stack. `top = -1` indicates an empty stack.

**Why conversion is needed:**

* **Infix notation:** `a + b * c` → operator is between operands
* **Postfix notation:** `a b c * +` → operator appears after operands

**Role of stack in conversion:**

* Operands are directly added to the output.
* Operators are pushed onto the stack based on precedence.
* Higher or equal precedence operators already in the stack are popped first.
* Parentheses control evaluation order: `(` is pushed, `)` triggers popping until `(` is found.

---

## (b) Description of Functions Implemented

### 1. `void initStack(struct Stack *s)`

**Purpose:** Initializes the stack.

**Working:**

* Sets `top = -1`.

**Time Complexity:** `O(1)`

---

### 2. `int isEmpty(struct Stack *s)`

**Purpose:** Checks whether the stack is empty.

**Working:**

* Returns `1` if `top == -1`.
* Returns `0` otherwise.

**Time Complexity:** `O(1)`

---

### 3. `int isFull(struct Stack *s)`

**Purpose:** Checks whether the stack is full.

**Working:**

* Returns `1` if `top == MAX - 1`.
* Returns `0` otherwise.

**Time Complexity:** `O(1)`

---

### 4. `void push(struct Stack *s, char c)`

**Purpose:** Pushes an operator onto the stack.

**Working:**

* Increments `top` and stores the character if stack is not full.

**Time Complexity:** `O(1)`

---

### 5. `char pop(struct Stack *s)`

**Purpose:** Pops and returns the top element from the stack.

**Returns:**

* Top operator if stack is not empty.
* `'\0'` if the stack is empty.

**Working:**

* Returns `stack[top]` and decrements `top`.

**Time Complexity:** `O(1)`

---

### 6. `int precedence(char op)`

**Purpose:** Determines operator precedence.

**Precedence Rules:**

* `^` → 3 (highest)
* `*`, `/` → 2
* `+`, `-` → 1
* Others → 0

**Importance:**
Ensures correct evaluation order (e.g., `*` before `+`).

**Time Complexity:** `O(1)`

---

### 7. `void infixtopostfix(char *infix)`

**Purpose:** Converts an infix expression to postfix notation.

**Working:**

1. Initializes stack and result array.
2. Scans the infix expression character by character:

   * Operand → add directly to output.
   * `(` → push to stack.
   * `)` → pop from stack until `(` is found.
   * Operator → pop operators of higher or equal precedence, then push current operator.
3. Pops remaining operators from the stack.
4. Appends null terminator and prints postfix expression.

**Time Complexity:** `O(n)` where `n` is the length of the expression.

---

## (c) Organization of `main()` Function

1. Declares `char infix[MAX]`.
2. Prompts user for infix expression.
3. Reads input using `scanf`.
4. Calls `infixtopostfix(infix)`.
5. Terminates program successfully.

---

## (d) Sample Output

**Example 1:**

```
Enter an infix expression: a+b*c
abc*+
```

**Example 2:**

```
Enter an infix expression: (a+b)*c
ab+c*
```

**Example 3:**

```
Enter an infix expression: a+b-c
ab+c-
```

**Example 4:**

```
Enter an infix expression: a+b*c-d/e
abc*+de/-
```
