//for duplicate element in sorted
#include<stdio.h>
int main()
{
	int i,j,count=0;
	int a[10]={6,7,7,8,9,9,9,9,9,15};
	for(i=0;i<9;i++)
	{
		if(a[i]==a[i+1])
		{
			j=i+2;
			while(a[j]==a[i])
				j++;
			printf("%d",a[i]);
			i=j;
			printf("\n%d\n",j-i);	
			
		}		
	}
}
