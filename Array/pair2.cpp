//pair ka sum
#include<stdio.h>
int main()
{
	int i,j;
	int k=9;
	int a[9]={6,7,8,9,2,1,3,5,8};
	int h[8]={0};
	for(i=0;i<9;i++)
	{
		if(a[i]<k)	
			if(h[k-a[i]]!=0)
					printf("%d %d\n",a[i],k-a[i]);
			h[a[i]]++;		
	}
}
