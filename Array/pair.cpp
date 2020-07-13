//pair ka sum
#include<stdio.h>
int main()
{
	int i,j;
	int k=9;
	int a[9]={6,7,8,9,2,1,3,5,16};
	int min=a[0],max=a[0];
	for(i=0;i<8;i++)
	{
		for(j=i+1;j<9;j++)
		if(a[i]+a[j]==k)
	printf("%d %d\n",a[i],a[j]);		
	}
}
