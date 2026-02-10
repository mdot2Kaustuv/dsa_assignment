# Documentation for prog_1.c
## Balanced Parentheses Checker using Stack
This program checks if brackets in a mathematical expression are balanced and in the correct order. It works with expressions like `a+(b*{c-d})` and takes three types of brackets: `()`, `{}`, and `[]`.

---

## (a) Data Structures Used

This program uses the **stack** data structure to check whether the brackets in the expression are balanced and in correct order. Stack follows the Last-In-First-Out (LIFO) principle, which makes it perfect for matching opening and closing brackets.

### Stack Structure
```c
struct Stack {
    char stack[MAX];
    int top;
};
```

**Components:**
- `stack[MAX]`: A character array that stores the brackets. `MAX` is set to 100, so the stack can hold up to 100 characters.
- `top`: An integer that keeps eye where the top element is in the stack. When `top = -1`, the stack is empty.

**How the stack works in this program:**
- The program reads the expression character by character.
- When it finds an opening bracket (`(`, `{`, `[`), it pushes it onto the stack.
- When it finds a closing bracket (`)`, `}`, `]`), it pops from the stack and checks if the popped opening bracket matches the closing bracket.
- At the end, if the stack is empty, all brackets are balanced. If the stack still has elements, there are unmatched opening brackets.

---

## (b) Description of Functions Implemented

### 1. `void initStack(struct Stack* s)`
**Purpose:** Initialize the stack to make it ready for use.

**Working:**
- Sets `top = -1` to show that the stack is empty.

**Time Complexity:** `O(1)` - takes constant time.

---

### 2. `int isEmpty(struct Stack* s)`
**Purpose:** Check if the stack has no elements.

**Working:**
- Returns `1` (true) if `top == -1`, meaning the stack is empty.
- Returns `0` (false) if the stack has elements.

**Time Complexity:** `O(1)` - simple comparison.

---

### 3. `int isfull(struct Stack* s)`
**Purpose:** Check if the stack is completely full.

**Working:**
- Returns `1` (true) if `top == MAX-1`, meaning the stack is full.
- Returns `0` (false) if there is still space.

**Time Complexity:** `O(1)` - simple comparison.

---

### 4. `void push(struct Stack* s, char c)`
**Purpose:** Add an opening bracket to the top of the stack.

**Parameters:**
- `s`: Pointer to the stack
- `c`: The opening bracket character to add

**Working:**
- Checks if the stack is full using `isfull()`.
- If not full, it increases `top` by 1 and stores the character at that position.

**Time Complexity:** `O(1)` - constant time insertion.

---

### 5. `char pop(struct Stack* s)`
**Purpose:** Remove and return the top bracket from the stack.

**Parameters:**
- `s`: Pointer to the stack

**Returns:**
- The character at the top of the stack.
- Returns `'\0'` (null character) if the stack is empty.

**Working:**
- Checks if the stack is empty using `isEmpty()`.
- If not empty, it returns the character at position `top` and decreases `top` by 1.

**Time Complexity:** `O(1)` - constant time removal.

---

### 6. `int checkbalanced(char *w)`
**Purpose:** This is the main function that checks if all brackets in the expression are balanced.

**Parameters:**
- `w`: String containing the mathematical expression to check

**Returns:**
- `1` if the brackets are balanced
- `0` if the brackets are not balanced

**Working:**
- Creates an empty stack.
- Goes through each character in the expression using a loop:
  - If it finds an opening bracket (`(`, `{`, `[`), it pushes it onto the stack.
  - If it finds a closing bracket (`)`, `}`, `]`):
    - First checks if the stack is empty. If empty, returns `0` (unbalanced).
    - Pops from the stack.
    - Checks if the popped bracket matches the closing bracket:
      - `)` should match with `(`
      - `}` should match with `{`
      - `]` should match with `[`
    - If they don't match, returns `0` (unbalanced).
- After checking all characters:
  - If the stack is empty, returns `1` (balanced).
  - If the stack still has elements, returns `0` (unbalanced - there are unmatched opening brackets).

**Time Complexity:** `O(n)` where `n` is the length of the expression. Each character is processed exactly once, and each push/pop operation takes constant time.

---

## (c) Organization of main() Method

The `main()` function is the entry point of the program.

**Working:**
1. Declares an array of strings `char *w[MAX]` to store test expressions.
2. Creates three test expressions:
   - Expression 1: `"a + (b - c) * (d"` (has unmatched opening bracket)
   - Expression 2: `"m+ [a - b * (c + d * {m)]"` (brackets in wrong order)
   - Expression 3: `"a + (b - c),"` (all brackets balanced)
3. Sets `max = 3` to indicate the number of test expressions.
4. Uses a `for` loop to go through each expression:
   - Prints the expression.
   - Calls `checkbalanced()` to check if brackets are balanced.
   - Prints "balanced" if the function returns `1`, or "not balanced" if it returns `0`.
5. Returns `0` to indicate  program completion.

---

## (d) Sample Output

```
The expression: a + (b - c) * (d
The expression is not balanced

The expression: m+ [a - b * (c + d * {m)]
The expression is not balanced

The expression: a + (b - c),
The expression is balanced
```

**Explanation:**

**Expression 1:** `a + (b - c) * (d`
- Opens with one `(` at the start
- Opens another `(` before `d`
- Missing two closing `)` brackets
- Result: Not balanced

**Expression 2:** `m+ [a - b * (c + d * {m)]`
- Opens `[`, then `(`, then `{`
- Closes with `]` but should close `{` first
- Brackets closed in wrong order
- Result: Not balanced

**Expression 3:** `a + (b - c),`
- Opens `(`
- Closes `)`
- All brackets match correctly
- Result: Balanced