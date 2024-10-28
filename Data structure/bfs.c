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
    Q = malloc(sizeof(struct Queue));
    if(Q){
        printf("Couldn't Allocate Memory!!");
        return NULL;
    }
    temp = malloc(sizeof(struct ListNode));
    Q->front = Q->back = NULL;
    return Q;
}

int isEmpty(struct Queue *Q){
    return (Q->front == NULL);
}

void Enqueue(struct Queue *Q, int data){
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

int Dequeue(struct Queue *Q){
    int data = 0;
    struct ListNode *temp;
    if(isEmpty(Q)){
        printf("The Queue is Empty!!");
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

BfsTraverse(int graph, int numNode){
    struct Queue *Q = createQueue();
    int * visited = (int *)malloc(numNode * sizeof(int));
    // int j=1;
    int i;
    for(i=0; i<numNode; i++){
        visited[i] = 0;
    }

    // printf("%d ",j);
    // visited[j] = 1;
    // Enqueue(Q,j);
    while(!isEmpty(Q)){
        int node = Dequeue(Q);
        for(int k = 0; k < numNode; k++){
            if(graph[node][k] == 1 && visited[k] == 0){
                printf("%d ", k);
                visited[k] = 1;
                Enqueue(Q,k);
            }
        }
    }

    return 0;
}

int main(){

    int graph[6][6] = {{0, 1, 1, 0, 1, 0},
                      {1, 0, 1, 0, 0, 1},
                      {1, 1, 0, 1, 0, 0},
                      {0, 0, 1, 0, 1, 1},
                      {1, 0, 0, 1, 0, 0},
                      {0, 1, 0, 1, 0, 0}
                      };

    BfsTraverse(graph,6);
    return 0;
}