//Inserting and Appending in a Array 
#include<stdio.h>
struct Array
{
int A[10];
int size;
int length;
}; 
void Display(struct Array arr)
 {
int i;
printf("\nElements are\n");
for(i=0;i<arr.length;i++)
printf("%d ",arr.A[i]);
 }
void Append(struct Array *arr,int x)
 {
if(arr->length<arr->size)
 arr->A[arr->length++]=x;
 }
void Insert(struct Array *arr,int index,int x)
 {
int i;
if(index>=0 && index<=arr->length && arr->length<arr->size)
 {
for(i=arr->length;i>index;i--)
 arr->A[i]=arr->A[i-1];
 arr->A[index]=x;
 arr->length++;
 }
} 
int main()
{
	int i;
struct Array arr1;
printf("Enter number of elements in array\n");
scanf("%d",&arr1.length);
printf("Enter total size of array\n");
scanf("%d",&arr1.size);
printf("Enter elements of array\n");
for(i=0;i<arr1.length;i++)
scanf("%d",&arr1.A[i]);

Append(&arr1,10);
Insert(&arr1,0,12);
Display(arr1);
return 0; 
}
