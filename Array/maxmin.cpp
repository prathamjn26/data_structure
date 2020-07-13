//using single loop
#include<stdio.h>
int main()
{
	int i;
	int a[9]={6,7,8,9,12,13,14,15,16};
	int min=a[0],max=a[0];
	for(i=1;i<9;i++)
	{
		if(a[i]<min)
			min=a[i];
		else if(a[i]>max)
			max=a[i];
	}
	printf("min: %d",min);
	printf("max: %d",max);
}
