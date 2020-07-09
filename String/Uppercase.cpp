#include<stdio.h>
int main()
{
	int i;
	char name[]="pratham";
	printf("%s\n",name);
	for(i=0;name[i]!='\0';i++)
		name[i]=name[i]-32;
	printf("%s\n",name);
}
