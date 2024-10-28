#include<stdio.h>
#include<stdlib.h>

struct tree_node{
    char value;
    struct tree_node *left;
    struct tree_node *right;

};
typedef struct tree_node* Tree;
 Tree new_tree_node(char value){
    Tree node = (Tree)malloc(sizeof(node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
 }

 int is_external(Tree node){
    return (node->left == NULL && node->right == NULL);
 }

int eval_exp(Tree node){
    if(is_external(node)){
        return node->value - '0';
    }

    int left_sum = eval_exp(node->left);
int right_sum = eval_exp(node->right);
char op = node->value;
switch(op){
    case '+':
        return left_sum + right_sum;
    case '-':
        return left_sum - right_sum;
    case '/':
        return left_sum / right_sum;
    case '*':
        return left_sum * right_sum;
    default:
        printf("Invalid operator: %c \n",op);
        exit(1);
    } 
}

int main(){
    Tree root = new_tree_node('*');
    root->left = new_tree_node('5');
    root->left->right = new_tree_node('3');
    root->right = new_tree_node('-');
    root->right->left = new_tree_node('6');
    root->right->right = new_tree_node('2');

    int result = eval_exp(root);
    printf("Result: %d\n", result);
    return 0;
}

   
