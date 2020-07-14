//duplicate in string using bitwise manupulation
#include<stdio.h>
int main()
{
	char a[]="pratham";
	int h=0,x=1,i;
	for(i=0;a[i];i++)
	{
		x=1;
		x=x<<a[i]-97;
		if((x&h)>0)
		{
			printf("%c",a[i]);
			printf("\ne: %d\n",x&h);
		}
		else
			h=h|x;
	}
}
