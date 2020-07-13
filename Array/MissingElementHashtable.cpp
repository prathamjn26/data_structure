# for single element in sorted
#include<stdio.h>
int main()
{
	int i;
	int a[10]={6,7,8,9,11,12,13,14,15,16};
	int diff=a[0]-0;
	for(i=0;i<10;i++)
	{
		if(a[i]-i!=diff)
		{
			printf("%d",diff+i);
			      break;			
		}		
	}
}
