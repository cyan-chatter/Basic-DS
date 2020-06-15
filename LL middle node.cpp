//Create and display Linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
 int data;
 struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
 int i;
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->data=A[0];
 first->next=NULL;
 last=first;

 for(i=1;i<n;i++)
 {
 t=(struct Node*)malloc(sizeof(struct Node));
 t->data=A[i];
 t->next=NULL;
 last->next=t;
 last=t;
 }
}

void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}

int findMiddle(struct Node* p)
{
	struct Node* q=p;
	while(q)
	{
		q=q->next;
		if(q) q=q->next;
		if(q) p=p->next;
	}
	return p->data;
}

int main()
{
 struct Node *temp;
 int A[]={3,5,7,10,25,8,32,2},mid=0;
 create(A,8);
 Display(first);
 mid=findMiddle(first);
 printf("\nThe middle node element is = %d\n",mid);
 return 0;
}
