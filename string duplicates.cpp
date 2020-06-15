//finding duplicates in a string
#include<iostream>
using namespace std;

struct Duplicates
{
	char Dupl[50];
	int count[50];
};

 struct Duplicates stringDuplicates(char* A)
{
	int hash[26]={ };
	struct Duplicates dup;
	for(int i=0;A[i]!='\0';i++)
	{
		++hash[A[i]-97];
	}
	for(int i=0,j=0;i<26;i++)
	{
		if(hash[i]>1)
		{
			dup.Dupl[j]=i+97;
			dup.count[j]=hash[i];
			j++;
		}
	}
	 return dup;
}
int main()
{
	char A[100]=" ";
	gets(A);
	struct Duplicates d;  
	d = stringDuplicates(A);
	for(int i=0;d.Dupl[i]!='\0';i++)
	{
		cout<<"\n"<<d.Dupl[i]<<" is present "<<d.count[i]<<" times\n";
	}
	return 0;
}
