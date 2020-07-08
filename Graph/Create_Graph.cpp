#include<stdio.h>
#include<malloc.h>

struct list{
	int data;
	struct list *next;
}; 

struct list* nn(int v)
{
	struct list *ptr=(struct list*)malloc(sizeof(struct list));
	ptr->data=v;
	ptr->next=NULL;
	return ptr;
}

void createGraph(int n)
{
	struct list *arr[n];
	struct list *ptr,*ptr1;
	int i,j,x,data;
	for(i=0;i<n;i++)
		arr[i]=NULL;
	for(i=0;i<n;i++)
	{
		printf("\nEnter no. of adjacent vertex of %d:",i);
		scanf("%d",&x);
		for(j=1;j<=x;j++)
		{
			printf("\nEnter %d adjacent vertices: ",j);
			scanf("%d",&data);
			ptr=nn(data);
			if(arr[i]==NULL)
				arr[i]=ptr;

			else{
				ptr1=arr[i];
				while(ptr1->next)
				{
					ptr1=ptr1->next;
				}
				ptr1->next=ptr;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\nAdjacent vertex of %d node is: ",i);
		ptr=arr[i];
		while(ptr)
		{
			printf("%d",ptr->data);
			ptr=ptr->next;
		}
	}
}

int main()
{
	createGraph(5);	
}
