#include<stdio.h>
int main()
{
	int i,j;
	char ch;
	char name[]="pratham";
	for(i=0;name[i];i++);
		i=i-1;
	for(j=0;i>j;i--,j++)
	{
		ch=name[i];
		name[i]=name[j];
		name[j]=ch;
	}
	printf("%s\n",name);
}
