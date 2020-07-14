#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Tree{
	int data;
	struct Tree *lchild;
	struct Tree  *rchild;
};

struct Queue
{
	struct Tree * data;
	struct Queue* next;
}
struct Queue* front=NULL;
struct Queue*;
struct Queue*;

struct Tree *tnn(int data)
{
	struct Tree *p;
	p=(struct Tree *)malloc(sizeof)(struct Tree));
	p->data=data;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}

void createTree()
{
	int data;
	struct Tree *root,*ptr,*ptr1;
	printf("\nenter root value: ");
	scanf("%d",&data);
	tnn(data);
	root=tnn(data);
	insert(root);
	while(front!=NULL)
	{
		ptr=delete1();
		printf("\nEnter left child");
		scanf("%d",&data);
		if(data!=-1)
		{
			ptr1=tnn(data);
			insert(ptr1);
			ptr->lchild=ptr1;
		}
	}
		printf("\nEnter right child");
		scanf("%d",&data);
		if(data!=-1)
		{
			ptr1=tnn(data);
			insert(ptr1);
			ptr->rchild=ptr1;
		}
	}	
}

void preorder1(struct Tree *t)
{
	while(t)
	{
	}
	
}	
