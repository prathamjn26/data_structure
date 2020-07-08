// linear search
#include<stdio.h>
int linearSearch(int arr[],int startIndex,int endIndex,int ele)
{
	int i;
	for(i=startIndex;i<=endIndex;i++)
	{
		if(arr[i]==ele)
		{
			int x=arr[i];
			arr[i-1]=x;
			arr[i]=arr[i-1];
			return i;
		}

	}
	return -1;
}

int main()
{
	int arr[]={1,23,3,11,45,34,23,67,98,90};
	int ele,result;
	printf("Enter the no. who you want to search\n");
	scanf("%d",&ele);
	result=linearSearch(arr,0,9,ele);
	if(result>=0)
		printf("Number found at %d index",result);
	else
		printf("Number not found");
}
