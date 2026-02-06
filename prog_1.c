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

int isEmpty(struct Stack* s);
int isfull(struct Stack* s);

void push(struct Stack* s, char c) {
    if ( !isfull(s) ) {
        s->stack[++(s->top)] = c;
    }
}

char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->stack[(s->top)--];
    }
    return '\0'; 
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isfull(struct Stack* s) {
    return s->top == MAX - 1;
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
   char *w[MAX] = {
     "a + (b - c) * (d",
        "m+ [a - b * (c + d * {m)]",
        "a + (b - c),"
    };
    int max = 3;
    for (int i = 0; i < max; i++) {
        printf("The expression: %s\n", w[i]);
        if (checkbalanced(w[i])) {
            printf("The expression is balanced");
        } else {
            printf("The expression is not balanced");
        }
        printf("\n");
    }
    return 0;
}