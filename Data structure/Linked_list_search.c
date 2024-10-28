#include<stdio.h>
#include<stdlib.h>

struct node *linked_list(int a[], int size);
int search_linked_list(struct node *head, int value);

struct node{
    int data;
    struct node *next;
};

int main(){
    int a[] = {10,20,30,40};
    struct node *head = NULL;
    head = linked_list(a,4);

    struct node *current = head;
    printf("Index: %d\n", search_linked_list(head,30));

    return 0;
}

int search_linked_list(struct node *head, int value){
    int index = 1;
    while( head->data != NULL){
        if(head->data == value){
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
}

struct node *linked_list(int a[], int size){
    struct node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for(i=0; i<size; i++){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            current = temp;
        }else{
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}