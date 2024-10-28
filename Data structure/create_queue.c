#include<stdio.h>>
#include<stdlib.h>

#define MAX_Q_SIZE 5

typedef struct {
    int data[MAX_Q_SIZE];
    int head,tail;
} Queue;

void Enqueue(Queue *q, int value);
int Dequeue(Queue *q);

int main(){
    Queue new_queue;
    int item;
    new_queue.head = 0;
    new_queue.tail = 0;

    Enqueue(&new_queue,10);
    printf("Tail=%d\n",new_queue.tail);

    Enqueue(&new_queue,20);
    printf("Tail=%d\n",new_queue.tail);

    printf("Beginning head=%d\n",new_queue.head);
    item = Dequeue(&new_queue);
    printf("Item=%d, Head=%d\n",item, new_queue.head);
    item = Dequeue(&new_queue);
    printf("Item=%d, Head=%d\n",item, new_queue.head);
    item = Dequeue(&new_queue);
    printf("Item=%d, Head=%d\n",item, new_queue.head);

    return 0;
}

void Enqueue(Queue *q, int value){
    if((q->tail + 1) % (MAX_Q_SIZE + 1) == q->head){
        printf("Queue is full!!\n");
        return -1;
    }
    q->data[q->tail] = value;
    q->tail = (q->tail + 1) % (MAX_Q_SIZE + 1);

}

int Dequeue(Queue *q){
    int item;
    if(q->head == q->tail){
        printf("Queue is Empty!!\n");
        return -1;
    }
    item = q->data[q->head];
    q->head = (q->head + 1) % (MAX_Q_SIZE + 1);
    return item;
}
