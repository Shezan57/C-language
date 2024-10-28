#include<stdio.h>
#include<stdlib.h>

#define STACK_MAX 100

typedef struct{
    int top;
    int data[STACK_MAX];
} Stack;

int push(Stack *s , int value);
int pop(Stack *s);

int main(){
    Stack new_stack;
    int item;

    new_stack.top = 0;
    push(&new_stack,1);
    push(&new_stack,2);
    push(&new_stack,3);
    push(&new_stack,4);
    push(&new_stack,5);

    item = pop(&new_stack);
    printf("%d\n",item);

    item = pop(&new_stack);
    printf("%d\n",item);
    return 0;
}


int push(Stack *s , int value){
    if(s->top < STACK_MAX){
        s->data[s->top] = value;
        s->top = s->top + 1;
    }else{
        printf("Stack is full!!\n");
    }
}

int pop(Stack *s){
    int value;
    if(s->top == 0){
        printf("Stack is empty!!\n");
        return -1;
    }else{
        s->top = s->top - 1;
        value = s->data[s->top];
    }
    return value;
}