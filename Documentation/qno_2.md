\# Documentation for prog\_2.c

\## Infix to Postfix Expression Converter using Stack

This program converts mathematical expressions from infix notation  like `a+b\\\*c` to postfix notation  like `abc\\\*+` . It uses a stack to handle operator precedence correctly.



---



\## (a) Data Structures Used



This program uses the \*\*stack\*\* data structure to temporarily store operators while converting the expression. The stack follows the Last-In-First-Out (LIFO) principle, which helps maintain the correct order of operations based on operator precedence.



\### Stack Structure

```c

struct Stack {

\&nbsp;   char stack\\\[MAX];

\&nbsp;   int top;

};

```



\*\*Components:\*\*

\- `stack[MAX]`: A character array that stores operators like `+`, `-`, `\\\*`, `/`, `^`, and `(`. `MAX` is set to 100.

\- `top`: An integer that tracks the index of the top element in the stack. When `top = -1`, the stack is empty.



\*\*Why we need conversion:\*\*

\- \*\*Infix notation:\*\* `a + b \\\* c` - operator is between operands

\- \*\*Postfix notation:\*\* `a b c \\\* +` - operator comes after operands



\*\*How the stack works in this program:\*\*

\- Operands (letters) are directly added to the output.

\- Operators are pushed onto the stack based on their precedence.

\- When we find a higher precedence operator already on the stack, we pop and add it to output before pushing the new operator.

\- Parentheses control the order: `(` is pushed immediately, `)` causes popping until we find the matching `(`.



---



\## (b) Description of Functions Implemented



\### 1. `void initStack(struct Stack\\\* s)`

\*\*Purpose:\*\* Initialize the stack to make it ready for use.



\*\*Working:\*\*

\- Sets `top = -1` to indicate the stack is empty.



\*\*Time Complexity:\*\* `O(1)` - constant time.



---



\### 2. `int isEmpty(struct Stack\\\* s)`

\*\*Purpose:\*\* Check if the stack has no elements.



\*\*Working:\*\*

\- Returns `1` (true) if `top == -1`.

\- Returns `0` (false) if the stack has elements.



\*\*Time Complexity:\*\* `O(1)` - simple comparison.



---



\### 3. `int isfull(struct Stack\\\* s)`

\*\*Purpose:\*\* Check if the stack is full.



\*\*Working:\*\*

\- Returns `1` (true) if `top == MAX-1`.

\- Returns `0` (false) if there is space.



\*\*Time Complexity:\*\* `O(1)` - simple comparison.



---



\### 4. `void push(struct Stack\\\* s, char c)`

\*\*Purpose:\*\* Add an operator to the stack.



\*\*Parameters:\*\*

\- `s`: Pointer to the stack

\- `c`: Operator character to add



\*\*Working:\*\*

\- Checks if stack is not full.

\- Increases `top` by 1 and stores the character at that position.



\*\*Time Complexity:\*\* `O(1)` - constant time insertion.



---



\### 5. `char pop(struct Stack\\\* s)`

\*\*Purpose:\*\* Remove and return the top operator from the stack.



\*\*Parameters:\*\*

\- `s`: Pointer to the stack



\*\*Returns:\*\*

\- The operator at the top of the stack.

\- Returns `'\\\\0'` if the stack is empty.



\*\*Working:\*\*

\- Checks if the stack is not empty.

\- Returns the character at position `top` and decreases `top` by 1.



\*\*Time Complexity:\*\* `O(1)` - constant time removal.



---



\### 6. `int precedence(char op)`

\*\*Purpose:\*\* Determine the priority level of an operator.



\*\*Parameters:\*\*

\- `op`: The operator character



\*\*Returns:\*\*

\- `3` for `^` (exponentiation - highest priority)

\- `2` for `\\\*` and `/` (multiplication and division)

\- `1` for `+` and `-` (addition and subtraction - lowest priority)

\- `0` for other characters



\*\*Working:\*\*

\- Uses if-else statements to check the operator and return its precedence value.



\*\*Why precedence matters:\*\*

In mathematics, certain operations must be done before others. For example, in `2 + 3 \\\* 4`, we calculate `3 \\\* 4 = 12` first, then `2 + 12 = 14`. We don't calculate `2 + 3 = 5` first.



\*\*Time Complexity:\*\* `O(1)` - simple comparisons.



---



\### 7. `void infixtopostfix(char \\\*infix)`

\*\*Purpose:\*\* The main function that converts an infix expression to postfix format.



\*\*Parameters:\*\*

\- `infix`: String containing the input expression in infix notation



\*\*Working:\*\*

1\. Creates an empty stack and an empty result array.

2\. Goes through each character in the input expression using a loop:

   - \*\*If character is a letter (a-z or A-Z):\*\*

     - Adds it directly to the result (operands stay in same order).

   - \*\*If character is `(`:\*\*

     - Pushes it onto the stack (we need to process what's inside parentheses first).

   - \*\*If character is `)`:\*\*

     - Pops from stack and adds to result until we find the matching `(`.

     - Removes the `(` from the stack.

   - \*\*If character is an operator (+, -, \*, /, ^):\*\*

     - While the stack is not empty AND the top operator has equal or higher precedence:

       - Pops from the stack and adds to result.

     - Pushes the current operator onto the stack.

3\. After processing all characters:

   - Pops all remaining operators from the stack and adds them to result.

4\. Adds a null terminator `'\\\\0'` to the result string to mark the end.

5\. Prints the postfix expression.



\*\*Time Complexity:\*\* `O(n)` where `n` is the length of the expression. Each character is processed exactly once, and each push/pop takes constant time.



---



\## (c) Organization of main() Method



The `main()` function is the entry point of the program.



\*\*Working:\*\*

1\. Declares a character array `char infix\\\[MAX]` to store the user's input.

2\. Prompts the user with the message: `"Enter an infix expression: "`.

3\. Reads the user's input using `scanf("%s", infix)`.

4\. Calls `infixtopostfix(infix)` which:

   - Converts the infix expression to postfix.

   - Prints the result automatically.

5\. Returns `0` to indicate successful program completion.



---



\## (d) Sample Output



\*\*Example 1:\*\*

```

Enter an infix expression: a+b\\\*c

abc\\\*+

```

\*\*Example 2:\*\*

```

Enter an infix expression: (a+b)\\\*c

ab+c\\\*

```

\*\*Example 3:\*\*

```

Enter an infix expression: a+b-c

ab+c-

```


\*\*Example 5:\*\*

```

Enter an infix expression: a+b\\\*c-d/e

abc\\\*+de/-

```


