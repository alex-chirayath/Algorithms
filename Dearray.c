/*Shirley Dsouza
  SE 6745 Batch:A
  Program :To implement Dequeue using array*/

#include<stdio.h>
#include<stdlib.h> 
#define SIZE 10

typedef struct
{
 int a[SIZE];
 int left,right,count;
}Dqarr;

void addleft(Dqarr * ,int );
void addright(Dqarr * ,int );
int deleteleft(Dqarr * );
int deleteleft(Dqarr * );
void display(Dqarr );

int main()
{
 Dqarr d;
 int ele,ch;
 d.right=d.left=d.count=0;
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

void addleft(Dqarr *p,int x)
{
 if(p->count==SIZE)
 {
  printf("Dequeue if full");
 }
 else
 {
  p->count++;
  p->a[p->left]=x;
  p->left=(p->left+1)%SIZE;
 }
}

void addright(Dqarr *p,int x)
{
 if(p->count==SIZE)
 {
  printf("Dequeue if full");
 }
 else
 {
  p->count++;
  p->right=(p->right-1+SIZE)%SIZE;
  p->a[p->right]=x;
 }
}

int deleteleft(Dqarr *p)
{
 int x;
 if(p->count==0)
 {
  printf("Dequeue if empty");
 }
 else
 {
  p->count--;
  p->left=(p->left-1+SIZE)%SIZE;
  x=p->a[p->left];
  return x;
 }
}

int deleteright(Dqarr *p)
{
 int x;
 if(p->count==0)
 {
  printf("Dequeue if empty");
 }
 else
 {
  p->count--;
  x=p->a[p->right];
  p->right=(p->right+1)%SIZE;
  return x;
 }
}

void display(Dqarr p)
{
 while(p.count!=0)
 {
  p.left=(p.left-1+SIZE)%SIZE;
  printf("%d "p.a[p.left]);
  p.count=p.count-1;
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
