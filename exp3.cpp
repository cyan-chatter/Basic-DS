#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}
void Bubble(int A[],int n)
{
 int i,j,flag=0;

 for(i=0;i<n-1;i++)
 {
 flag=0;
 for(j=0;j<n-i-1;j++)
 {
 if(A[j]>A[j+1])
 {
 swap(&A[j],&A[j+1]);
 flag=1;
 }
 }
 if(flag==0)
 break;
 }

}




int main()
{
 int lowVal, highVal, A[100]={ }, t, n, i, j;
 scanf("%d",&t);
 for(j=1;j<=t;j++)
 {
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&A[i]);
	 }
 	
 	scanf("%d",&lowVal);
 	scanf("%d",&highVal);
 
  Bubble(A,n);

 for(i=0;i<n;i++)
 printf("%d ",A[i]);
 printf("\t");
	
 }

 
 return 0;
}
