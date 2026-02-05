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

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int checkbalanced(char *w) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; i < strlen(w); i++) {
        char word = w[i];

        if (word == '(' || word == '{' || word == '[') {
            push(&s, word);
        } 
        else if (word == ')' || word == '}' || word == ']') {
            if (isEmpty(&s)) {
                return 0; 
            }
            char topChar = pop(&s);
        if ((word == ')' && topChar != '(') ||
                (word == '}' && topChar != '{') ||
                (word == ']' && topChar != '[')) {
                return 0;
        }
        }
        }
    return isEmpty(&s); 
}

int main() { 
    char w[MAX];
    printf("Enter the expression: ");
    scanf("%s", w);
    int i = checkbalanced(w);
    if (i==1) {
        printf("The expression is balanced");
    } else {
        printf("The expression is not balanced");
    }
    return 0;
}