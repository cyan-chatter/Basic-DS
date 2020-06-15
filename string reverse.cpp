//Reversing a String in one go  
#include<iostream>
using namespace std;
int main()
{
	char A[]="python",t;
	int i,j;
	for(i=0; A[i]!='\0'; i++)
	{
	}
	i--;
	for(j=0;j<i;i--,j++)
	{
		t=A[i];
		A[i]=A[j];
		A[j]=t;
	}
	puts(A);
	return 0;
}
