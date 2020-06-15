//Finds Duplicates in an unsorted array using Hash Array
#include<iostream>
using namespace std;

class Array
{
	private:
		int *A;
		int size;
		int length;
		void swap(int *x,int *y);
	public:
 		Array()
 	 {
 		size=10;
 		length=0;
 		A=new int[size];
 	 }
 		Array(int sz)
   {
 		size=sz;
 		length=0;
 		A=new int[size];
 	 }
  	~Array()
   {
		delete []A;
   }
		void Display();
		void Append(int x);
		void Insert(int index,int x);
		int Max();
		int Min();
		void Duplicates();
};

void Array::Display()
 {
	int i;
 	cout<<"\nElements are\n";
	for(i=0;i<length;i++)
 		cout<<A[i]<<" "; 
 }
 
void Array::Append(int x)
 {
	if(length<size)
 	A[length++]=x;
 }

void Array::Insert(int index,int x)
 {
	int i;
	if(index>=0 && index <=length)
  {
		for(i=length;i>index;i--)
 			A[i]=A[i-1];
 		A[index]=x;
 		length++;
  }
 }

void Array::swap(int *x,int *y)
 {
	int temp;
 	temp=*x;
 	*x=*y;
 	*y=temp;
 }
 
 int Array::Max()
{
int max=A[0];
int i;
for(i=1;i<length;i++)
 {
if(A[i]>max)
 max=A[i];
 }
return max;
}

int Array::Min()
{
int min=A[0];
int i;
for(i=1;i<length;i++)
 {
if(A[i]<min)
 min=A[i];
 }
return min;
}

void Array:: Duplicates()
 {
	int h=0;
	h=Max();
	int hash[h]={ };
	for(int i=0;i<length;i++)
	{
		++hash[A[i]];
	}
	for(int i=0;i<h;i++)
	{
		if(hash[i]>1)
			cout<<"\nDuplicate element "<<i<<" is present "<<hash[i]<<" times\n";
	}
 }

int main()
 {
	Array *arr1;
	int x,index=0,sz;
	cout<<"Enter Size of Array\n";
	cin>>sz;
 	arr1=new Array(sz);
 	cout<<"Enter elements of array\n";
 	while(index<sz)
 	{
 		cin>>x;
 		arr1->Append(x);
		 ++index;	
	 }
	arr1->Display();
 	arr1->Duplicates();
		return 0;
 }
