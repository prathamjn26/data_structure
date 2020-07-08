#include<stdio.h>
#include<malloc.h>
#define size 10

struct list{
	int data;
	struct list *next;
};

struct list *arr[size]={NULL};

struct list *nn(int data)
{
	struct list *p=(struct list*)malloc(sizeof(struct list));
	p->data=data;
	p->next=NULL;
}

void insert(int data)
{
	struct list *ptr,*ptr1=arr[data%10],*ptr2=NULL;
	ptr=nn(data);
	while(ptr1!=NULL&&ptr1->data<ptr->data)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	ptr->next=ptr1;	
	if(ptr1!=arr[data%10])
		ptr2->next=ptr;
	else
		arr[data%10]=ptr;
}

int search(int data)
{
	struct list *ptr=arr[data%10];
	while(ptr)
	{
		if(ptr->data==data)
			return 1;
		if(ptr->data>data)
			return -1;
		ptr=ptr->next;
	}
	return -1;
}

void display()
{
	int i;
	struct list *ptr;
	for(i=0;i<=9;i++)
	{
		ptr=arr[i];
		while(ptr)
		{
			printf("%d ",ptr->data);
			ptr=ptr->next;
		}
		if(ptr!=arr[i])
			printf("\n");
	}
}

int main()
{
	int ch,v,result,val;
	while(1)
	{
		printf("\n1. Insert");
		printf("\n2. Display");
		printf("\n3. Search");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter value: ");
				scanf("%d",&v);
				insert(v);
				break;
			case 2:display();
				break;
			case 3:
				printf("\nEnter value want to search: ");
				scanf("%d",&val);				
				result=search(val);
				if(result==1)
					printf("\nResult found");
				else
					printf("\nResult not found");
				break;
			case 4:return 0;
			default:printf("\nInvalid Choice");
		}	
	}
}
