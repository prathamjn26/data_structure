#include<stdio.h>
void insertion_Sort(int arr[],int size)
{
	int value,hole,i;
	
	for(i=1;i<size;i++)
	{
		value=arr[i];
		hole=i;
		while(hole>1&&arr[hole-1]>value)
		{
			arr[hole]=arr[hole-1];
			hole--;
		}
		arr[hole]=value;
	}
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
}
int main()
{
	int arr1[]={1,6,2,78,23,45,76,3,4,11};
	insertion_Sort(arr1,10);
}

//worst case
//time complexity:o(n2)
//space complexity:o(n2)

//best case
//time complexity :o(n)
//space complexity:o(1)

//It is adaptive
//It is stable
//Useful in case of LinkedList
