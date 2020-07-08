#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1,rear=-1;

void insert()
{
	if(rear==size-1)
	{
		printf("\nQueue is full.");
		return;
	}
	printf("\nEnter data: ");
	scanf("%d",&queue[++rear]);
	if(rear==0)
		front=0;
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty.");
		return;
	}
	for(i=front;i<=rear;i++)
	{
		printf("\n%d",queue[i]);
	}
}

void delete1()
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty.");
	}
	for(i=front;i<rear;i++)
	{
		queue[i]=queue[i+1];
	}
	rear--;
	if(rear==-1)
		front =-1;
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1. Insert");	
		printf("\n2. Display");	
		printf("\n3. Delete");	
		printf("\n4. Exit");	
		printf("\nEnter your choice: ");	
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
				break;
			case 2:display();
				break;
			case 3:delete1();
				break;
			case 4:return 0;
			default:printf("\nInvalid Choice");
		}
	}
}
