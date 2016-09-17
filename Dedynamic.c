/*Shirley Dsouza
  SE 6745 Batch:A
  Program :Dynamic implementation of Dequeue*/

#include<stdio.h>
#include<stdlib.h> 
#define SIZE 10

typedef struct NODE
{
 int data;
 struct NODE *prev,*next;
}node;
typedef struct 
{
 node *right,*left;
}DQD;

void addleft(DQD * ,int );
void addright(DQD * ,int );
int deleteleft(DQD * );
int deleteleft(DQD * );
void display(DQD );

int main()
{
 DQD d;
 int ele,ch;
 d.right=d.left=NULL;
 while(1)
 {
  printf("\nEnter \n1.To add a element to left \n2.To add a element to right \n3.To delete a element from left \n4.To delete a element from right \n5.To display \n6.Exit \n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
       printf("Enter element to be added to left:");
       scanf("%d",&ele);
       addleft(&d,ele);
       break;
   case 2:
       printf("Enter element to be added to right:");
       scanf("%d",&ele);
       addright(&d,ele);
       break;
   case 3:
       ele=deleteleft(&d);
       printf("The element deleted from left:%d \n",ele);
       break;
   case 4:
       ele=deleteright(&d);
       printf("The element deleted from right:%d \n",ele);
       break;
   case 5:
       printf("The elements of Dequeue are:\n");
       display(d);
       break;
   case 6:
       exit(1);
  }
 }
 return 0;
}

void addleft(DQD *p,int x)
{
 node *q;
 q=(node* )malloc(sizeof(node));
 q->data=x;
 q->next=q->prev=NULL;
 if((p->left==NULL)&&(p->right==NULL))
 {
  p->left=p->right=q;
 }
 else
 {
  q->next=p->left;
  p->left->prev=q;
  p->left=q;
 }
}

void addright(DQD *p,int x)
{
 node *q;
 q=(node* )malloc(sizeof(node));
 q->data=x;
 q->next=q->prev=NULL;
 if((p->left==NULL)&&(p->right==NULL))
 {
  p->left=p->right=q;
 }
 else
 {
  q->prev=p->right;
  p->right->next=q;
  p->right=q;
 }
}

int deleteleft(DQD *p)
{
 int x;
 node *q,*r;
 if((p->left==NULL)&&(p->right==NULL))
 {
  printf("Dequeue is empty");
  return 0;
 }
 else
 {
  q=p->left;
  x=q->data;
  r=p->left->next;
  r->prev=NULL;
  p->left=r;
  free(q);
  return x;
 }
}

int deleteright(DQD *p)
{
 int x;
 node *q,*r;
 if((p->left==NULL)&&(p->right==NULL))
 {
  printf("Dequeue is empty");
  return 0;
 }
 else
 {
  q=p->right;
  x=q->data;
  r=p->right->prev;
  r->next=NULL;
  p->right=r;
  free(q);
  return x;
 }
}

void display(DQD p)
{
 node *q;
 q=p.left;
 while(q!=NULL)
 {
  printf("%d ",q->data);
  q=q->next;
 }
}

/*Output:
Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
1
Enter element to be added to left:11

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
1
Enter element to be added to left:22

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
2
Enter element to be added to right:33

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
2
Enter element to be added to right:44

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
3
The element deleted from left:22 

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
4
The element deleted from right:44 

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
5
The elements of Dequeue are:
11 33 

Enter 
1.To add a element to left 
2.To add a element to right 
3.To delete a element from left 
4.To delete a element from right 
5.To display 
6.Exit 
6*/
