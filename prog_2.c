#include <stdio.h> 
#include <string.h>

#define MAX 100

// stack strucutre 
struct Stack {
    char stack[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s){
    return s->top == -1;
}

int isfull(struct Stack* s) {
    return s->top == MAX - 1;
}

void push(struct Stack* s, char c) {
    if (s->top < MAX - 1) {
        s->stack[++(s->top)] = c;
    }
}

char pop(struct Stack* s) {
    if (s->top >= 0) {
        return s->stack[(s->top)--];
    }
    return '\0'; 
}



int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    else {
        return 0;
    }
    }


void infixtopostfix(char *infix){
    struct Stack s;
    initStack(&s);
    char result[1000];
    int j = 0;

    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result[j++] = c;
        }
        else if (c == '(') {
            push(&s, c);
        }
        else if (c == ')') {
            while (!isEmpty(&s) && s.stack[s.top] != '(') {
                result[j++] = pop(&s);
            }
            pop(&s); 
        }
        else {
            while (!isEmpty(&s) && precedence(s.stack[s.top]) >= precedence(c)||precedence(s.stack[s.top]) == precedence(c) ) {
                result[j++] = pop(&s);
            }
            push(&s, c);
        }
        }

    while (!isEmpty(&s)) {
        result[j++] = pop(&s);
    }

    result[j] = '\0'; //fix garbage output 
    printf("%s\n", result);
    }


int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixtopostfix(infix);
    return 0;
}



