//for duplicate element in sorted usinh hash
#include<stdio.h>
int main()
{
	int i,j,count=0;
	int a[10]={8,6,7,10,9,7,9,9,11,9};
	for(i=0;i<9;i++)
	{
		if(a[i]!=-1)
		{
		for(j=i+1;j<10;j++)
			if(a[i]==a[j])
			{
				count++;
				a[j]=-1;				
			}					
		if(count>1)
		{
			printf("%d--->%d",a[i],count);
		}
		}
	}		
}
