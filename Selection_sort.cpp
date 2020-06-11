#include<stdio.h>

void selection_Sort(int arr[],int size)
{
	int min,i,j;
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		int temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}

int main()
{
	int arr1[]={1,6,-2,78,-23,-45,76,3,4,11};
	selection_Sort(arr1,10);
}

//worst case
//time complexity:o(n2)
//space complexity:o(n)

//best case
//time complexity :o(n2)
//space commplexity:o(1)

//It is 
//It is stable
