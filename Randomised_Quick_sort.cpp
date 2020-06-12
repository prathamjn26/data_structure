#include<stdio.h>
#include<stdlib.h>

int partiation(int arr[],int start,int end)
{
	int i,index=start,temp,pivot;
	int x=(rand()%(end-start+1))+start;
	int temp1=arr[x];
	arr[x]=arr[end];
	arr[end]=temp1;
	pivot=arr[end];
	for(i=start;i<=end;i++)
	{
		if(arr[i]<pivot)
		{
			temp=arr[i];
			arr[i]=arr[index];
			arr[index]=temp;
			index++;
		}
	}
	arr[end]=arr[index];
	arr[index]=pivot;

	return index;
}

void quick_Sort(int arr[],int start,int end)
{
	int pindex;
	if(end>start)
	{
		pindex=partiation(arr,start,end);
		quick_Sort(arr,start,pindex-1);
		quick_Sort(arr,pindex+1,end);
	}
}


int main()
{
	int arr[]={1,2,9,12,3,14,6,8,5};
	quick_Sort(arr,0,8);
	for(int i=0;i<9;i++)
	{
		printf("%d\t",arr[i]);
	}
}


//worst case
//time complexity:o(n2)
//space complexity:o(n)

//best case
//time complexity :o(n2)
//space commplexity:o(1)

//It is not adaptive
//It is not stable
