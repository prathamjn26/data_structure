#include<stdio.h>
#include<malloc.h>
#define size 20
struct graphnode{
	int node;
	struct graphnode *next;
}; 

struct graphnode* nn(int data)
{
	
}

int main()
{
	int arr[size],n,i;
	printf("\nEnter no. of vertices: ");
	scanf("%d",&n);
	printf("\nEnter vertices: ")
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nVertices are: ");
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	createGraph(arr,n);	
}
