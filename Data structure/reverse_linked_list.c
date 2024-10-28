#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node create_liked_list(int a[],int size);
void reverse_linked_list(struct node *head);
int main(){
    int a[] = {5,10,15};
    struct node *head = NULL;
    head = create_liked_list(a,3);
    struct node *newHead = head;
    while(head != NULL){
        printf("%d -> ",head->data);
    }
    printf("NULL\n");
    reverse_linked_list(*newHead);
    return 0;
}

struct node create_liked_list(int a[],int size){
struct node *head = NULL, *temp = NULL,*current = NULL;
int i;
    for(i = 0; i < size; i++){
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

void reverse_linked_list(struct node *head){

}