#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode *next;
};

struct Queue{
    struct ListNode *front;
    struct ListNode *back;
};

struct Queue *createQueue(){
    struct Queue *Q;
    struct ListNode *temp;
    Q =  malloc(sizeof(struct Queue));
    if(Q){
        printf("couldn't allocate memory.");
        return NULL;
    }
    temp = malloc(sizeof(struct ListNode));
    Q->front = NULL;
    Q->back = NULL;

    return Q;
}

int isEmpty(struct Queue *Q){
    return (Q->front == NULL);
}

void EnQueue(struct Queue *Q, int data){
    struct ListNode *newNode;
    newNode = malloc(sizeof(struct ListNode));
    if(!newNode){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(Q->back){
        Q->back->next = newNode;
        Q->back = newNode;
    }
    if(Q->front == NULL){
        Q->front = Q->back;
    }
}

int DeQueue(struct Queue *Q){
    int data = 0;
    struct LisNode *temp;
    if(isEmpty(Q)){
        printf("The Queue is Empty!");
        return 0;
    }
    else{
        temp = Q->front;
        data = Q->front->data;
        Q->front = Q->front->next;
        free(temp);
    }

    return data;
}

void DeleteQueue(struct Queue *Q){
    struct ListNode *temp;
    while(Q){
        temp = Q;
        Q = Q->next;
        free(temp);
    }
    free(Q);
}


int main(){

    return 0;
}