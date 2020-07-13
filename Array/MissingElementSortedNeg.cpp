//for multiple in sorted
#include<stdio.h>
int main()
{
	int i;
	int a[9]={-6,-5,-4,-2,-1,1,0,2,3};
	int diff=0-a[0];
	for(i=0;i<9;i++)
	{
		if(i-a[i]!=diff)
		{
				printf("%d\t",i-diff);
				break;
		}		
	}
}
