#include <stdio.h>
#include <stdlib.h>
struct Node
{
 char data;
 struct Node *next;
}*top=NULL;
void push(char x)
{
 struct Node *t;
 t=(struct Node*)malloc(sizeof(struct Node));

 if(t==NULL)
 printf("stack is full\n");
 else
 {
 t->data=x;
 t->next=top;
 top=t;
 }

}
char pop()
{
 struct Node *t;
 char x=-1;

 if(top==NULL)
 printf("Stack is Empty\n");
 else
 {
 t=top;
 top=top->next;
 x=t->data;
 free(t);
 }
 return x;
}
void Display()
{
 struct Node *p;
 p=top;
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
 printf("\n");
}

int stackTop()
{
 if(top!=NULL)
 return top->data;
 return -1;
}

int isBalanced(char *exp)
{
 int i;
 char last;
 for(i=0;exp[i]!='\0';i++)
 {
 if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
 {
 	 push(exp[i]);
	 printf("\npushed\n");
 }
 else if(exp[i]==')'&&last=='(')
 {
 if(top==NULL)
 return 0;
 pop();
 printf("\n ( popped\n");
 }
 else if(exp[i]=='}'&&last=='{')
 {
 if(top==NULL)
 return 0;
 pop();
 printf("\n { popped\n");
 }
 else if(exp[i]==']'&&last=='[')
 {
 if(top==NULL)
 return 0;
 pop();
 printf("\n [ popped\n");
 }
 else if(exp[i]!='('||exp[i]!=')'||exp[i]!='{'||exp[i]!='}'||exp[i]!='['||exp[i]!=']')
 continue; 
 else return 0;
 last=stackTop();
 }
 if(top==NULL)
 return 1;
}
int main()
{
 char exp[]="({}[(a+b)*(c-d)])";

 printf("%d ",isBalanced(exp));

 return 0;
}
