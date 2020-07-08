//row wise
#include<stdio.h>
#include<malloc.h>
struct sparse{
	int x;
	int y;
	int z;
}; 

struct sparse* create()
{
	int num,i;
	struct sparse *arr;
	printf("\nEnter no. of non-zero elements: ");
	scanf("%d",&num);
	arr=(struct sparse *)malloc((num+1)*sizeof(struct sparse));
	printf("\nEnter dimension of matrix: ");
	scanf("%d %d",&arr[0].x,&arr[0].y);
	arr[0].z=num;
	printf("\nEnter elements: ");
	for(i=1;i<=num;i++)
	{
		printf("\nEnter value: ");
		scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
	}
	return arr;
}

struct sparse* sum(struct sparse* arr,struct sparse* arr1)
{
	int i=1,j=1,k=1;
	struct sparse *arr2;
	if(arr[0].x!=arr1[0].x||arr[0].y!=arr1[0].y)
	{
		printf("Dimension of both matrix are not equal");
		return NULL;	
	}
	arr2=(struct sparse *)malloc((arr[0].z+arr1[0].z+1)*sizeof(struct sparse));
	arr2[0].x=arr[0].x;
	arr2[0].y=arr[0].y;
	while(i<=arr[0].z&&j<=arr1[0].z)
	{

		if(arr[i].x<arr1[j].x)
		{
			arr2[k++]=arr[i++];
		}
		else if(arr[i].x>arr1[j].x)
		{
			arr2[k++]=arr1[j++];
		}
		else{
			if(arr[i].y<arr1[j].y)
			{
				arr2[k++]=arr[i++];
			}
			else if(arr[i].y>arr1[j].y)
			{
				arr2[k++]=arr1[j++];
			}
			else{
				arr2[k]=arr[i++];
				arr2[k++].z+=arr1[j++].z;
			}
		}
	}	
	while(i<=arr[0].z)
		arr2[k++]=arr[i++];
	while(j<=arr1[0].z)
		arr2[k++]=arr1[j++];
	arr2[0].z=k-1;
	return arr2;
}


void display(struct sparse *arr)
{
	int i,j,k=1;
	for(i=0;i<arr[0].x;i++)
	{
		for(j=0;j<arr[0].y;j++)
		{
			if(i==arr[k].x&&j==arr[k].y)
				printf("%d ",arr[k++].z);
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int main()
{
	int i,x,j;
	struct sparse* arr1,*arr,*arr2;
	arr=create();
	printf("\nEnter another matrix");
	arr1=create();
	arr2=sum(arr,arr1);
	printf("\nMartix 1:\n");
	display(arr);
	printf("\nMatrix 2:\n");
	display(arr1);
	printf("\nSum is:\n");
	display(arr2);
}
