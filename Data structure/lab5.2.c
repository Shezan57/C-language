#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct stack {
    int top;
    int capacity;
    int *array;
};

struct stack *createStack();
void push(struct stack *S, int x);
int pop(struct stack *S);
int is_empty(struct stack *top_n);
void *create_node(int value);
void *tree_make();
void add_left_child(struct node *node, struct node *child);
void add_right_child(struct node *node, struct node *child);
void preorder_traverse(struct node *root);
int isFullStack(struct stack *S);

int main(){

    struct node *temp = tree_make();
    preorder_traverse(temp);
    return 0;
}

struct stack *createStack(){
    struct stack *S = malloc(sizeof(struct stack));
    if(!S)
        return NULL;
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if(!S->array)
        return NULL;
    return S;
}
void *create_node(int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left_child(struct node *node, struct node *child){
    node->left = child;
}

void add_right_child(struct node *node, struct node *child){
    node->right = child;
}

void *tree_make(){

            // Root node
    struct node *fifty = create_node(50);

    struct node *forty = create_node(40);
    add_left_child(fifty,forty);

    struct node *forty_five = create_node(45);
    add_right_child(forty, forty_five);

    struct node *thirty = create_node(30);
    add_left_child(forty,thirty);

    struct node *sixty = create_node(60);
    add_right_child(fifty, sixty);

    struct node *fifty_five = create_node(55);
    add_left_child(sixty,fifty_five);

    struct node *seventy = create_node(70);
    add_right_child(sixty,seventy);

    return fifty;
}

// void DoubleStack(struct stack *S){
//     S->capacity * = 2;
//     S->array = realloc(S->array,S->capacity * sizeof(int));
// }


int isFullStack(struct stack *S){
    return (S->top == S->capacity-1);
}
void push(struct stack *S, int x){
    if(isFullstack(S))
        printf("stack is full!");
    
    S->array[++S->top] = x;
}
int top(struct stack *S){
    if (is_empty(S))
    {
        return 0;
    }
    return S->array[S->top];
    
}
int pop(struct stack *S){
    if(is_empty(S))
        return 0;
    return S->array[S->top--];
}

int is_empty(struct stack *S){
    return S->top == -1; 
       
}

void DeleteStack(struct stack *S){
    if(S){
        if(S->array)
            free(S->array);
        free(S);
    }
}

void preorder_traverse(struct node *root){
    
    struct stack *S = createStack();
    while(1){
        while(root){
            printf("%d",root->data);
            push(S,root->data);
            root = root->left;
        }
        if(is_empty(S)){
            break;
            root = pop(S);
            root = root->right;
        }
        DeleteStack(S);
    }

}