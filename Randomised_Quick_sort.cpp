#include<stdio.h>
#include<stdlib.h>
int partiation(int arr[],int start,int end)
{
	int i,index=start,temp;
	int pivot_index=(rand()%(end-start+1))+start;
	int pivot=arr[pivot_index];  //this is for randomised quicksort 
	printf("pivot:  %d, pivot_index: %d\n",pivot,pivot_index);											  //int pivot=arr[end]   for normal quicksort
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
//	arr[end]=arr[index];
//	arr[index]=pivot;
temp=arr[index];
arr[index]=pivot;
arr[pivot_index]=temp;					
	for(int i=0;i<9;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\nindex: %d",index);
	printf("\n");

	return index;
}

void randomised_quick_Sort(int arr[],int start,int end)
{
	int pindex;
	if(end>start)
	{
		pindex=partiation(arr,start,end);
		printf("\npindex: %d\n",pindex);
		randomised_quick_Sort(arr,start,pindex-1);
		randomised_quick_Sort(arr,pindex+1,end);
	}
}


int main()
{
	int arr[]={1,2,9,12,2,14,6,8,5};
	randomised_quick_Sort(arr,0,8);
//	for(int i=0;i<9;i++)
//	{
//		printf("%d\t",arr[i]);
//	}
}

//worst case
//time complexity:o(n2)
//space complexity:o(n)

//best case
//time complexity :o(n2)
//space commplexity:o(1)

//It is not adaptive
//It is not stable
