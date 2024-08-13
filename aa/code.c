#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack is full\n");
    } else {
        s->items[++(s->top)] = item;
    }
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

int size(Stack *s) {
    return s->top + 1;
}

int main() {
    Stack s;
    init(&s);

        push(&s, 6);
        pop(&s);
    
    pop(&s);


    return 0;
}
