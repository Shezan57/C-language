#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*start;

void create_list(int value);
void print_list();
void swap_position(struct node *start, int index);

int main(){

    create_list(1);
    create_list(2);
    create_list(3);
    create_list(4);
    create_list(5);
    create_list(6);
    create_list(7);
    create_list(8);
    create_list(9);
    create_list(10);

    print_list();
    swap_position(start,1);

    return 0;
}

void create_list(int value){
    struct node *q, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if (start == NULL){
        start = temp;
    }else{
        q = start;
        while(q->next != NULL)
            q = q->next;
        q->next = temp;
    }
}

void print_list(){
    struct node *q;
    if (start == NULL){
        printf("\nList is empty");
        return;
    }
    q = start;
    printf("\n\nList is: ");

    while(q != NULL){
        printf("%d-->", q->data);
        q = q->next;
    }
    printf("NULL\n");
}

void swap_position(struct node *start,int index){
    struct node *current = start;
    int pos = 0;
    while(current != NULL){
        if (pos == index){
            // logic here

            if (current == NULL || current->next == NULL) {
            printf("Position P is either NULL or the last node, cannot swap.\n");
            return;
            }
            if (current == start) {
                printf("Position P is the first node and no node preceeds it.\n");
                return;
            }
            struct node *prev = start;
            while (prev != NULL && prev->next != current) {
                prev = prev->next;
            }
            if (prev == NULL) {
                printf("Position P is not found in the list.\n");
                return;
            }
            struct node *temp,*curr;
            temp = (struct node *)malloc(sizeof(struct node));
            curr = (struct node *)malloc(sizeof(struct node));
            curr = current;
            temp = current->next;
            prev->next = temp;
            curr->next = temp->next;
            temp->next = curr;

        }else{
            pos++;
            current = current->next;
        }
    }
}