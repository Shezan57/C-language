#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
};

struct node *createNode(char data);
void add_left_child(struct node *tree, struct node *child);
void add_right_child(struct node *tree, struct node *child);
struct node *create_tree();
int check(struct node *N);
int evalExp(struct node *tree);
void inorder_traverse(struct node *node);

int main(){
    struct node *treeRoot = create_tree();

    int result = evalExp(treeRoot);
    printf("The result is: %d\n",result);
    return 0;

}

struct node *createNode(char data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Error!! couldn't create a new node.");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void add_left_child(struct node *tree, struct node *child){
    tree->left = child;
}

void add_right_child(struct node *tree, struct node *child){
    tree->right = child;
}

struct node *create_tree(){
                // Root

    struct node *plus = createNode('+');

            // roots left first child

    struct node *multiplication1 = createNode('*');
    add_left_child(plus, multiplication1);

            // left->left child

    struct node *three = createNode('3');
    add_left_child(multiplication1, three);

            // root left right child

    struct node *minus = createNode('-');
    add_right_child(multiplication1, minus);

            // root left right left child

    struct node *four = createNode('4');
    add_left_child(minus, four);

            // root left right right child

    struct node *one = createNode('1');
    add_right_child(minus, one);

                // right first child

    struct node *multiplication2 = createNode('*');
    add_right_child(plus, multiplication2);

            // root right left child 

    struct node *two1 = createNode('2');
    add_left_child(multiplication2, two1);

            // root right right child 
            
    struct node *two2 = createNode('2');
    add_right_child(multiplication2, two2);

    return plus;
    
}

int check(struct node *N){
    return (N->left == NULL && N->right == NULL);
}

int evalExp(struct node *tree){
    if((check(tree))){
        return tree->data -'0';
    }

    int leftSum = evalExp(tree->left);
    int rightSum = evalExp(tree->right);

    char operator = tree->data;
    if(operator == '+'){
        return leftSum + rightSum;
    }
    else if(operator == '-'){
        return leftSum - rightSum;
    }
    else if(operator == '*'){
        return leftSum * rightSum;
    }
    else if(operator == '/'){
        return leftSum / rightSum;
    }else{
        printf("Invalid!!");
        exit(1);
    }
    
}

void inorder_traverse(struct node *node){
    if(node->left != NULL){
        inorder_traverse(node->left);
    }
    printf("%d ",node->data);
    if(node->right != NULL){
        inorder_traverse(node->right);
    }
}
