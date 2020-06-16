//index based sorting
//stable
#include<stdio.h>

void count_Sort(int arr[],int size,int max,int min)
{
	int s=max+min+1;
	int count[s];
	int output[size],i;
	for(i=0;i<s;i++)
		count[i]=0;		
	for(i=0;i<size;i++)
		count[arr[i]+min]++;
	for(i=1;i<s;i++)
		count[i]=count[i]+count[i-1];
	for(i=size-1;i>=0;i--)
			output[--count[arr[i]+min]]=arr[i];	
	for(i=0;i<size;i++)
		arr[i]=output[i];
}

int main()
{
	int arr[]={4,2,-1,2,1,4,1,9,6,3,4},max=0,min=0,i;
	for(i=0;i<11;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
		if(arr[i]<min)
		{
			min=arr[i];
		}
	}
	if(min<0)
		count_Sort(arr,11,max,-min);
	else
		count_Sort(arr,11,max,0);
	for(i=0;i<11;i++)
	{
		printf("%d\t",arr[i]);
	}
}

//time complexity o(n+k) where n=size of array,m=max element
//space complexity o(n+k)

