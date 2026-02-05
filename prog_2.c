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

int main(){
    return 0;
}