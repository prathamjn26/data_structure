#include<stdio.h>
#include<malloc.h>

struct stack{
	int data;
	struct stack* next;
};

struct stack* top=NULL;

struct stack *nn(int data)
{
	struct stack *p=(struct stack*)malloc(sizeof(struct stack));
	p->data=data;
	p->next=NULL;
	return p;
}

void push()
{
	int data;
	struct stack* p1;
	printf("\nEnter data: ");
	scanf("%d",&data);
	p1=nn(data);
	if(p1==NULL)
		top=p1;
	else{
		p1->next=top;
		top=p1;
	}
}

void display()
{
	struct stack* ptr;
	if(top==NULL)
	{
		printf("\nStack is Empty.");
		return;
	}
	ptr=top;
	while(ptr)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}

void pop()
{
	struct stack* ptr;
	if(top==NULL)
	{
		printf("\nStack is Empty.");
		return;
	}
	else{
		ptr=top;
		top=top->next;
		free(ptr);
		ptr=NULL;
	}
}

void peek()
{
	if(top==NULL)
	{
		printf("\nStack is Empty.");
		return;
	}
	printf("\n%d",top->data);
}

int main()
{
	int ch;
	while(1)
	{
	printf("\n1. Push");
	printf("\n2. Display");
	printf("\n3. Pop");
	printf("\n4. Peek");
	printf("\n5. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:push();
			break;
		case 2: display();
			break;
		case 3:pop();
			break;
		case 4:peek();
			break;
		case 5:return 0;
		default:printf("\n Invalid choice");
		}
	}
}
