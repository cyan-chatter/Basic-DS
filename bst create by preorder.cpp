#include<stdio.h>
#include<stdlib.h>

struct Node
{
 struct Node *lchild;
 int data;
 struct Node *rchild;
};



struct Stack
{
 int size;
 int top;
 struct Node **S;
};

void Stackcreate(struct Stack *st,int size)
{
 st->size=size;
 st->top=-1;
 st->S=(Node**)malloc(st->size*sizeof(Node*));
}
void push(struct Stack *st,Node* x)
{
 if(st->top==st->size-1)
 printf("Stack overflow\n");
 else
 {
 st->top++;
 st->S[st->top]=x;
 }
 
}
Node* pop(struct Stack *st)
{
 Node* x=NULL;

 if(st->top==-1)
 printf("Stack Underflow\n");
 else
 {
 x=st->S[st->top--];
 }
 return x;
}
int isEmptyStack(struct Stack st)
{
 if(st.top==-1)
 return 1;
 return 0;
}
int isFullStack(struct Stack st)
{
 return st.top==st.size-1;
}

struct Node *root=NULL;

struct Node *maxVal=NULL;

maxVal=(struct Node *)malloc(sizeof(struct Node));
maxVal->data=32767;
maxVal->lchild=NULL;
maxVal->rchild=NULL;


Node* stackTop(struct Stack st)
{
 if(!isEmptyStack(st))
 return st.S[st.top];
 return maxVal;
}


void createPre(int pre[], int n)
{
	Stack stk;
	Node *t;
	Node *p;
	int i=0;
	printf("\nInitialization done \n");
	root=(struct Node *)malloc(sizeof(struct Node));
	root->data=pre[i++];
	root->lchild=NULL;
	root->rchild=NULL;
	p=root;
	printf("\nRoot Created \n");
	while(i<n)
	{ printf("\nEntered loop for %dth time \n",i);
		if(pre[i]<p->data)
		{
			t=(struct Node *)malloc(sizeof(struct Node));
			printf("\nMemory allocated to LC temp  \n");
			t->data=pre[i++];
			t->lchild=NULL;
			t->rchild=NULL;
			p->lchild=t;
			push(&stk,p);
			p=t;
			printf("\nLeft Child Created \n");
		}
		else
		{
			if(pre[i]>p->data && pre[i]<stackTop(stk)->data)
			{
				t=(struct Node *)malloc(sizeof(struct Node));
				printf("\nMemory allocated to RC temp  \n");
				t->data=pre[i++];
				t->lchild=NULL;
				t->rchild=NULL;
				p->rchild=t;
				p=t;
				printf("\nRight Child created \n");
				
			}
			else
			{
				p=pop(&stk);
				printf("\nPopped \n");
			}
		}
	}
}

void IInorder(struct Node *p)
{
 struct Stack stk;
 Stackcreate(&stk,100);

 while(p || !isEmptyStack(stk))
 {
 if(p)
 {
 push(&stk,p);
 p=p->lchild;
 }
 else
 {
 p=pop(&stk);
 printf("%d ",p->data);
 p=p->rchild;
 }
 }
}

int main()
{
	int preorder[]={6,10,9,14,7,17,1,8,4};
	createPre(preorder,9);
	printf("\ncreatePre done\n");
	IInorder(root);
	return 0;
}
