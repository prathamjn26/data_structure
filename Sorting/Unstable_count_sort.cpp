//index based sorting
//unstable

#include<stdio.h>

void count_Sort(int arr[],int size,int max)
{
	int count[max+1]={0},i,j;
	int output[size];
	for(i=0;i<size;i++)
		count[arr[i]]++;
	i=0,j=0;
	while(i<=max)
	{
		if(count[i]>0)
		{
			arr[j++]=i;
			count[i]--;
		}
		else
			i++;
	}
}

int main()
{
	int arr[]={4,2,1,2,1,4,1,9,6,3,4},max=0,i;
	for(i=0;i<11;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	count_Sort(arr,11,max);
	for(i=0;i<11;i++)
	{
		printf("%d\t",arr[i]);
	}
}

