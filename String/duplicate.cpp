#include<stdio.h>
#define size 26
int main()
{
	int i,j;
	int h[size]={0};
	char s[]="coffee";
	for(i=0;s[i]!='\0';i++)
	{
		h[s[i]-97]++;
	}
	for(i=0;i<size;i++)
	{
		if(h[i]>1)
		{
			printf("%c\n",i+97);
			printf("%d\n",h[i]);
		}
	}
}
