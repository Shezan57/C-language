#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_full(Stack* s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack* s, int x) {
    if (is_full(s)) {
        printf("Error: stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->data[s->top] = x;
}

int pop(Stack* s) {
    if (is_empty(s)) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    int x = s->data[s->top];
    s->top--;
    return x;
}

int evaluate_postfix(char* postfix) {
    Stack s;
    init(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(&s, c - '0');  // convert char to int
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop(&s);
            int a = pop(&s);
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char postfix[] = "23*5+";
    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);  // should be 11
    return 0;
}