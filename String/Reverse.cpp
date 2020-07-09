#include<stdio.h>
int main()
{
	int i,j;
	char name[]="pratham";
	char name1[9];
	for(i=0;name[i];i++);
		i=i-1;
	for(j=0;i>=0;i--,j++)
		name1[j]=name[i];
	printf("%s\n",name);
	printf("%s\n",name1);
}
