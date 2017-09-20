/*: Expression tree*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct tnode  
{
 char data;
 struct tnode *left,*right;
}TNODE;
typedef struct
{
 TNODE *a[SIZE];
 int top;
}stack;

void push(stack * ,TNODE * );
TNODE * pop(stack * );
TNODE * createtree(char pf[]);
void inorder(TNODE * );
void preorder(TNODE * );
int evaluate(TNODE * );
int calculate(char ,int ,int );

int main()
{
 char postfix[50];
 TNODE *root;
 int ch,ele;
 printf("\nEnter the expression in postfix format:");
 scanf("%s",postfix);
 root=createtree(postfix);
 while(1)
 {
  printf("\nEnter \n1.For inorder traversal \n2.For preorder traversal \n3.For postorder traversal \n4.To evaluate \n5.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("\nTraversal in inorder format:");
       inorder(root);
       break;
   case 2:
       printf("\nTraversal in preorder format:");
       preorder(root);
       break;
   case 3:
       printf("\nTraversal in postorder format:");
       printf("%s",postfix);
       break;
   case 4:
       ele=evaluate(root);
       printf("The result is:%d",ele);
       break;
   case 5:
       exit(1);
  }
 }
 return 0;
}

void push(stack *s,TNODE *p)
{
 s->a[++(s->top)]=p;
}

TNODE * pop(stack *s)
{
 return (s->a[s->top--]);
}

TNODE * createtree(char pf[])
{
 stack s;
 int i;
 s.top=-1;
 for(i=0;pf[i]!='\0';i++)
 {
  TNODE *p;
  p=(TNODE *)malloc(sizeof(TNODE));
  p->data=pf[i];
  p->left=NULL;
  p->right=NULL;
  if(!isdigit(pf[i]))
  {
   p->right=pop(&s);
   p->left=pop(&s);
  }
  push(&s,p);
 }
 return(pop(&s));
}
 
void inorder(TNODE *rt)
{
 if(rt!=NULL)
 {
  if((rt->left!=NULL)&&(rt->right!=NULL))
  {
   printf("(");
  }
  inorder(rt->left);
  printf("%c",rt->data);
  inorder(rt->right);
  if((rt->left!=NULL)&&(rt->right!=NULL))
  {
   printf(")");
  }
 }
}
  
void preorder(TNODE *rt)
{
if(rt!=NULL)
 {
  
  printf("%c",rt->data);
  preorder(rt->left);
  preorder(rt->right);
 }
}

int evaluate(TNODE *rt)
{
 int n1,n2,ele;
 if((rt->left==NULL)&&(rt->right==NULL))
 {
  return (rt->data-'0');
 }
 n1=evaluate(rt->left);
 n2=evaluate(rt->right);
 ele=calculate(rt->data,n1,n2);
 return ele;
}

int calculate(char opt,int op1,int op2)
{
 int n;
 switch(opt)
 {
  case '+':
       n=(op1+op2);
       break;
  case '-':
       n=(op1-op2);
       break;
  case '/':
       n=(op1/op2);
       break;
  case '*':
       n=(op1*op2);
       break;
  }
 return n;
}

/*Output:
Enter the expression in postfix format:123*+

Enter 
1.For inorder traversal 
2.For preorder traversal 
3.For postorder traversal 
4.To evaluate 
5.Exit 
1

Traversal in inorder format:(1+(2*3))

Enter 
1.For inorder traversal 
2.For preorder traversal 
3.For postorder traversal 
4.To evaluate 
5.Exit 
2

Traversal in preorder format:+1*23

Enter 
1.For inorder traversal 
2.For preorder traversal 
3.For postorder traversal 
4.To evaluate 
5.Exit 
3

Traversal in postorder format:123*+

Enter 
1.For inorder traversal 
2.For preorder traversal 
3.For postorder traversal 
4.To evaluate 
5.Exit 
4

The result is:7

Enter 
1.For inorder traversal 
2.For preorder traversal 
3.For postorder traversal 
4.To evaluate 
5.Exit 
5*/
