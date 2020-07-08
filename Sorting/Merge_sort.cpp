#include<stdio.h>
void merge(int arr[],int start,int mid,int end)
{
	int arr1[end+1];
	int i=start,j=mid+1,k=start;
	while(i<=mid&&j<=end)
	{
		if(arr[j]>arr[i])
		{
			arr1[k++]=arr[i++];
		}
		else
		{
			arr1[k++]=arr[j++];
		}
	}
	while(i<=mid)
	{
		arr1[k++]=arr[i++];
	}
	while(j<=end)
	{
		arr1[k++]=arr[j++];
	}
	for(i=start;i<=end;i++)
	{
		arr[i]=arr1[i];
	}
}

void merge_Sort(int arr[],int start,int end)
{
	int mid;
	if(end>start)
	{
		mid=(start+end)/2;
		merge_Sort(arr,start,mid);
		merge_Sort(arr,mid+1,end);
		merge(arr,start,mid,end);
	}
}

int main()
{
	int arr[]={30,10,48,16,2,6,32,20};
	merge_Sort(arr,0,7);
	for(int i=0;i<8;i++)
	{
		printf("%d\t",arr[i]);
	}
}
