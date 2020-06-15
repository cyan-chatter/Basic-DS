#include<iostream>
using namespace std;

int is_nearly_lucky(char str[])
{
	int i=0, count=0;
while(str[i]!='\0')	
{
	if(str[i]=='4'||str[i]=='7')
		++count;
	++i;
}
if(count==4||count==7)
	return 1;
else 
	return 0;
}

int main()
{
	int c=0;
	char str[]=" ";
	gets(str);	
	c = is_nearly_lucky(str);
	if(c==1)
	cout<<"YES";
	else cout<<"NO";	
	return 0;
}
