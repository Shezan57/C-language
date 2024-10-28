#include<stdio.h>
#include<stdlib.h>

struct node {
        int data;
        struct node *next;
    };
    
struct node *create_linked_list(int arr[], int size){

}
int main(){
    int arr[] = {5,10,15,20,25,30,40};
    struct node *head;
    head = create_linked_list(arr,7);
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("Null\n")
    return 0;
}

struct node *create_linked_list(int arr[], int size){
    struct node *head=NULL, *temp=NULL,*current=NULL;
    int i;
    for(i=0; i<size; i++){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
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