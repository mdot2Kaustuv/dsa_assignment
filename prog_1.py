class Stack:
    def __init__(self):
        self.stack = []

    def push(self, element):
        self.stack.append(element)

    def pop(self):
        if self.isEmpty():
            return "Stack is empty"
        return self.stack.pop()

    def peek(self):
        return self.stack[-1]

    def isEmpty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)


stack = Stack()
words = input("Enter the expression: ")

for c in words:
    if c == "(" or c == "[" or c == "{":
        stack.push(c)

    elif c == ")" or c == "]" or c == "}":
        if stack.isEmpty():
            print("Expression is not balanced")

        top = stack.peek()

        if ((c == ")" and top == "(") or
            (c == "]" and top == "[") or
            (c == "}" and top == "{")):
            stack.pop()


if stack.isEmpty():
    print("Expression is balanced")
else:
    print("Expression is not balanced")
