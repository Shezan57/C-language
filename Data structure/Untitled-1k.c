#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* Position;

void Swap(Position P) {
    if (P == NULL || P->next == NULL) {
        printf("Position P is either NULL or the last node, cannot swap.\n");
        return;
    }
    if (P == head) {
        printf("Position P is the first node and no node preceeds it.\n");
        return;
    }
    Position prev = head;
    while (prev != NULL && prev->next != P) {
        prev = prev->next;
    }
    if (prev == NULL) {
        printf("Position P is not found in the list.\n");
        return;
    }
    Position curr = P;
    Position next = P->next;
    prev->next = next;
    curr->next = next->next;
    next->next = curr;
}

int main() {
    // Create a singly linked list with 4 nodes
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*) malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = (Node*) malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = (Node*) malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = NULL;

    // Print the original list
    printf("Original list: ");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Swap the second and third nodes
    Swap(head->next);

    // Print the updated list
    printf("Updated list: ");
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}