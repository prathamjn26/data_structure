//#include<stdio.h>
//
//int mergeSortedArray(int arr1[],int n,int arr2[],int m)
//{
//	int arr3[n+m]={};
//	int i=0,j=0;
//	for(int k=0;k<=n+m;k++)
//	{
//		if(arr1[i]<arr2[j])
//		{
//			arr3[k]=arr1[i];
//			i++;
//		}
//		else
//		{
//			arr3[k]=arr2[j];
//			j++;
//		}
//	}
//	for(int k=0;k<n+m;k++)
//	{
//		printf("\n%d",arr3[k]);
//	}
//}
//
//int main()
//{
//	int arr1[]={2,4,10,12,13};
//	int arr2[]={3,5,7,9,16};
//	printf("The Sorted array is");
//	mergeSortedArray(arr1,5,arr2,5);
//}

#include<stdio.h>

void merge(int arr1[],int arr2[],int size1,int size2)
{
	int i=0,j=0,k;
	int arr3[size1+size2]={};
	for(k=0;i!=size1&& j!=size2;k++)
	{
		if(arr1[i]<=arr2[j])
		{
			arr3[k]=arr1[i];
			i++;
		}
		else
		{
			arr3[k]=arr2[j];
			j++;	
		}
	}
	if(i!=size1)
	{
		for(k=i+j;i!=size1;k++)
		{
			arr3[k]=arr1[i];
			i++;
		}
	}
	else
	{
		for(k=i+j;i!=size2;k++)
		{
			arr3[k]=arr2[j];
			j++;
		}
	}
	printf("\n sorted array is:");
	for(k=0;k<(size1+size2);k++)
	{
		printf("\n%d",arr3[k]);
	}
}

int main()
{
	int s1,s2;
	int arr1[s1],arr2[s2];
	
	printf("enter size of first array");
	scanf("%d",&s1);
	
	printf("enter first array in sorted order %d elements",s1);
	for(int i=0;i<s1;i++)
	{
		scanf("%d",&arr1[i]);	
	}

	printf("enter size of second array");
	scanf("%d",&s2);
	
	printf("enter second array in sorted order %d elements",s2);
	for(int i=0;i<s2;i++)
	{
		scanf("%d",&arr2[i]);	
	}
	
	merge(arr1,arr2,s1,s2);
}
