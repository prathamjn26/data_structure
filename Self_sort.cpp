#include<stdio.h>

void self_Sort(int A[],int n )
{
	int gap,i,j,temp;
	for(gap=n/2;gap>=1;gap=gap/2)
	{
		for(j=gap;j<=n-1;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(A[i]<A[i+gap])
					break;
				else{
					temp=A[i];
					A[i]=A[i+gap];
					A[i+gap]=temp;
				}
			}
		}
	}
}

int main()
{
	int A[]={46,58,30,38,62,14,18,10,4};
	self_Sort(A,8);
	for(int i=0;i<8;i++)
	{
		printf("%d\t",A[i]);
	}
}
