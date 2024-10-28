#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *creat_linked_list(int a[],int size);
void swap_linked_list();

int main(){
    int a[] = {5,10,15,90,67,98,34,78};
    struct node *head;
    head = creat_linked_list(a,8);
    while (head != NULL)
    {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL\n");
    return 0;
}

struct node *creat_linked_list(int a[], int size){
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