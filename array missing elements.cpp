//find missing elements of an AP with cd=1 in an array
//Missing1 is for sorted array only
//Missing 2 uses hash array and works for both sorted and unsorted array.
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
		void Missing1();
		void Missing2();
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

void Array::Missing1()
 {
 	int flag=0,diff,fd;
 	fd=A[0];
 	for(int i=0;i<length;i++)
 	{
 		diff=A[i]-i;
 		if(diff!=fd)
 		{
 			cout<<"\nMissing element = "<<A[i]-1<<"\n";
 			flag=1;
 			fd=diff;
		}
	}
	if(flag==0)
	cout<<"\nNo element missing\n"; 	
 }
 
 void Array::Missing2()
 {
	int h,l;
	h=Max();
	l=Min();
	int hash[h-l+1]={ };
	for(int i=0;i<length;i++)
	{
		++hash[A[i]-l];
	}
	for(int i=0;i<h-l+1;i++)
	{
		if(hash[i]==0)
		cout<<"\nMissing element is = "<<i+l<<"\n";
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
 	arr1->Missing2();
		return 0;
 } 
