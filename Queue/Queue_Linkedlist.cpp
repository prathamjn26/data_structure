#include<stdio.h>
#include<malloc.h>

struct queue{
	int data;
	struct queue* next;	
};

struct queue* rear=NULL;
struct queue* front=NULL;

struct queue* nn(int data)
{
	struct queue* p=(struct queue *)malloc(sizeof(struct queue));
	p->data=data;
	p->next=NULL;
	return p;
}

void insert()
{
	int data;
	syruct queue* ptr;
	printf("\nEnter data: ")
	scanf("%d",&data);
	ptr=nn(data);
	if(rear==NULL)
		front=rear=ptr;
	
}
