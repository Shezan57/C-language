#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
    int data;
    Node *left;
    Node *right;
}; 

Node *create_node(int value);
void add_left_child(Node *node,Node *child);
void add_right_child(Node *node, Node *child);
Node *create_tree();
void pre_order_travarsal(Node *node);
void post_order_traverse(Node *node);
void inorder_traverse(Node *node);
Node *bst_insert(Node *root, Node *node);
int height_calculator(Node *root);
int max(int left_height, int right_height);


int main(){
    
    Node *root = create_tree();

    // printf("%d\n",root->data);

    printf("Pre-Order traverse\n");
    pre_order_travarsal(root);
    printf("\nPost-Order traverse\n");
    post_order_traverse(root);
    printf("\nIn-Order traverse\n");
    inorder_traverse(root);

    printf("\n");
    int value = height_calculator(root);
    printf("Height of this tree is: %d\n", value);

    return 0;
}

Node *create_node(int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error! couldn't create a new node.");
        exit(1);
    } 
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
};

void add_left_child(Node *node,Node *child){
    node->left = child;
}

void add_right_child(Node *node, Node *child){
    node->right = child;
}

Node *create_tree(){
    // Root node

    Node *two = create_node(2);
    // first child

    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two , seven);
    add_right_child(two , nine);
    // child of 7

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven, one);
    add_right_child(seven, six);

    // child of 9
    Node *eight = create_node(8);
    add_right_child(nine, eight);

    // child of six
    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six,five);
    add_right_child(six,ten);

    // child of eight
    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight, three);
    add_right_child(eight,four);

    return two;

}
// preorder travarse to print data head to leaf
void pre_order_travarsal(Node *node){
    printf("%d ", node->data);
    if(node->left != NULL){
        pre_order_travarsal(node->left);
    }
    if (node->right != NULL)
    {
        pre_order_travarsal(node->right);
    }
}

// Postorder traverse to print data leaf to head
void post_order_traverse(Node *node){
    if(node->left != NULL){
        post_order_traverse(node->left);
    }
    if(node->right != NULL){
        post_order_traverse(node->right);
    }
    printf("%d ",node->data);
} 

// In-Order Traverse to print left root right
void inorder_traverse(Node *node){
    if(node->left != NULL){
        inorder_traverse(node->left);
    }
    printf("%d ",node->data);
    if(node->right != NULL){
        inorder_traverse(node->right);
    }
}

// Insert Node

Node *bst_insert(Node *root, Node *node){
    Node *parent_node, *current_node;
    if(root == NULL){
        root = node;
        return root;
    }
    
    parent_node = NULL;
    current_node = root;
    while(current_node != NULL){
        parent_node = current_node;
        if(node->data < current_node->data){
            current_node = current_node->left;
        }
        else{
            current_node = current_node->right;
        }
    }
    if(current_node < parent_node->data){
        add_left_child(parent_node, node);
    }
    else{
        add_right_child(parent_node, node);
    }
    return root;
}

// Max function

int max(int left_height, int right_height){
    if(left_height > right_height){
        return left_height;
    }else{
        return right_height;
    }
}

// Height calculator

int height_calculator(Node *root){
    if(root == NULL){
        return 0;
    }
    int left_height = height_calculator(root->left);
    int right_height = height_calculator(root->right);
    return max(left_height,right_height)+1;
}