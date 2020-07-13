//for duplicate element in sorted
#include<stdio.h>
int main()
{
	int i,d=-1;
	int a[10]={6,7,7,8,9,9,9,9,14,15};
	for(i=0;i<10;i++)
	{
		if(a[i]==a[i+1]&&d!=a[i])
		{
			printf("%d",a[i]);
			d=a[i];
		}		
	}
}
