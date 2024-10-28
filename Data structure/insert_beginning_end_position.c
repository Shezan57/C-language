#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_linked_list(int a[], int size);
void insert_at_beginning(struct node *head, int data);
void insert_at_end(struct node *head, int data);
void insert_any_position(struct node *head, int position, int value);
struct node *delete_any_node(struct node *head, int data);
void print_linked_list(struct node *head);

int main(){
    int a[]={5,10,15,20,25,30,35,40,45};
    struct node *head;
    head = create_linked_list(a,9);
    print_linked_list(head);

    // insert_at_beginning(head,1);
    // insert_at_end(head,50);
    // insert_any_position(head,3,17);
    struct node *newhead = delete_any_node(head,25);
    print_linked_list(newhead);

    return 0;
}

struct node *create_linked_list(int a[], int size){
    struct node *head=NULL, *temp=NULL, *current=NULL;
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

void insert_at_beginning(struct node *head, int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;

    struct node *new_head = temp;
    struct node *current = new_head;
    new_head = temp;

    print_linked_list(new_head);
    
}

void insert_at_end(struct node *head, int data){
    struct node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
     struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    current->next = temp;
    print_linked_list(head);
}

void insert_any_position(struct node *head, int position, int value){
    struct node *temp = head;
    int count=0;
    while(temp->next != NULL){
        count++;
        if(count == position){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else{
            temp = temp->next;
        }
    }
    print_linked_list(head);
}

struct node *delete_any_node(struct node *head, int data){
    struct node *dammyHead = (struct node *)malloc(sizeof(struct node));
    dammyHead->next = head;
    struct node *temp = dammyHead;
    while(temp != NULL){
        if(temp->next->data == data){
            temp->next = temp->next->next;
            break;
        }
        else{
            temp = temp->next;
        }
    }
    return dammyHead->next;
}

void print_linked_list(struct node *head){
    struct node *current = head;
        while(current != NULL){
        printf("%d-->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
