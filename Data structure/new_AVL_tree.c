    #include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int height;
    struct node *left;
    struct node  *right;
};

struct node *create_node(int data);
int height_calculate(node *root);
int max(int left , int right);
struct node *right_rotate(struct node *old_parent);
struct node *left_rotate(struct node *old_parent);
int get_balance(struct node *n);
struct node insert_node(struct node *node, int data);
struct node min_value_node(struct node *node);
struct node *delete_node(struct node *root, int data);

int main(){
    return 0;
}

struct node *create_node(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int height_calculate(struct node *n ){
    if(n == NULL){
        return 0;
    }
    return n->height;
}

int max(int left, int right){
    return (left > right) ? left : right;
}

struct node *right_rotate(struct node *old_parent){
    struct node *orphan = old_parent->left->right;
    struct node *new_parent = old_parent->left;
    new_parent->right = old_parent;
    old_parent->left = orphan;
    old_parent->height = max(height_calculate(old_parent->left) ,height_calculate(old_parent->right)+1);
    new_parent->height = max(height_calculate(new_parent->left), height_calculate(new_parent->right)+1);
}

struct node *left_rotate(struct node *old_parent){
    struct node *orphan = old_parent->right->left;
    struct node *new_parent = old_parent->right;
    new_parent->left = old_parent;
    old_parent->right = orphan;
    old_parent->height = max(height_calculate(old_parent->left), height_calculate(old_parent->right)+1);
    new_parent->height = max(height_calculate(new_parent->left), height_calculate(new_parent->right)+1);
}


int get_balance(struct node *n){
    if(n == NULL){
        return 0;
    }
    return height_calculate(n->left)-height_calculate(n->right);
}

struct node insert_node(struct node *node, int data){
    if(node == NULL){
        return (create_node(data));
    }

    if(data < node->data){
        node->left = insert_node(node->left, data);
    }
    else if(data > node->data){
        node->right = insert_node(node->right, data);
    }
    else
        return node;

    node->height = 1+max(height_calculate(node->left), height_calculate(node->right));

    int balance = get_balance(node);
    if(balance > 1 && data < node->left->data){
        return right_rotate(node);
    }

    if(balance < -1 && data > node->right->data){
        return left_rotate(node);
    }
    if(balance > 1 && data > node->left->data){
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if(balance < -1 && data < node->right->data){
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

struct node *min_value_node(struct node *node){
    struct node *current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

struct node *delete_node(struct node *root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data){
        root->right = delete_node(root->right, data);
    }
    else{
        if((root->left == NULL) || (root->right == NULL)){
            struct node *temp = root->left ? root->left : root->right;
            
            
        }
    }
}