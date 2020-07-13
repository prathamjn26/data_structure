//for multiple in sorted
#include<stdio.h>
int main()
{
	int i;
	int a[9]={6,7,8,9,12,13,14,15,16};
	int diff=a[0]-0;
	for(i=0;i<9;i++)
	{
		if(a[i]-i!=diff)
		{
			while(diff<a[i]-i)
			{
				printf("%d",diff+i);
				diff++;				
			}
		}		
	}
}
