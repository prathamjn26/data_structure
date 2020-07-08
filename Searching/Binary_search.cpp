// require sorted array
#include<stdio.h>

int binarySearch(int arr[],int startIndex,int endIndex,int ele)
{
	int mid;
	while(startIndex<=endIndex)
	{
		mid=(startIndex+endIndex)/2;
		if(arr[mid]==ele)
			return ele;
		else if(arr[mid]<ele)
			startIndex=mid+1;
		else
			endIndex=mid-1;
	}
	return -1;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,11,23,45};
	int ele,result;
	printf("/n enter element want to search");
	scanf("%d",&ele);
	result=binarySearch(arr,0,11,ele);
	if(result>=0)
		prinf("\n element found at %d index",result);
	else
		printf("\n element not found");
}
