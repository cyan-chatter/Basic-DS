//Stack Header File
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

Node* stackTop(struct Stack st)
{
 if(!isEmptyStack(st))
 return st.S[st.top];
 return NULL;
}

