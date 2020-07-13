//pair sum in sorted
#include<stdio.h>
int main()
{
	int i=0,j=9;
	int k=11;
	int a[10]={1,3,5,6,7,8,9,10,12,14};
	int h[8]={0};
	while(i<j)	
	{
		if(a[i]+a[j]==k)
        {
        	printf("%d %d\n",a[i],a[j]);
			i++;
			j--;	
		}
		else if(a[i]+a[j]>k)
			j--;
        else
        	i++;
	}
}
