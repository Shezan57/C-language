#include<stdio.h>
#include<stdlib.h>
#define bool int
 
struct tNode {
   int data;
   struct tNode* left;
   struct tNode* right;
};
 
struct sNode {
  struct tNode *t;
  struct sNode *next;
};
 
void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);
 
void preorder(struct tNode *root){
  printf("preorder traverse elements are:\n");
    struct sNode *s = NULL;
    push(&s,root);
    struct tNode *current = root;
    
    while (!isEmpty(s))
    {
      current = s->t;
      printf("%d-->",current->data);
      pop(&s);
      if(current->right != NULL){
        push(&s,current->right);
      }
      if (current->left != NULL)
      {
        push(&s,current->left);
      }
      
    }
    printf("NULL\n");
}

void push(struct sNode** top_ref, struct tNode *t)
{
  struct sNode* new_tNode = (struct sNode*) malloc(sizeof(struct sNode));
            
 
  if(new_tNode == NULL)
  {
     printf("Stack Overflow \n");
     exit(0);
  }           
  new_tNode->t  = t;
  new_tNode->next = (*top_ref);  
  (*top_ref)    = new_tNode;
}
 
bool isEmpty(struct sNode *top)
{
   return (top == NULL)? 1 : 0;
}  
 
struct tNode *pop(struct sNode** top_ref)
{
  struct tNode *res;
  struct sNode *top;

  if(isEmpty(*top_ref))
  {
     printf("Stack Underflow \n");
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->t;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)malloc(sizeof(struct tNode));
                       
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}
 
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5);

  preorder(root);

  return 0;
}