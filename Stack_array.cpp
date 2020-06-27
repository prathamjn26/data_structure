#include<stdio.h>
#define size 5
int stack[size];
int top =-1;

void push()
{
	if(top==size-1)
		printf("\nStack is full");
	else{
		printf("\nEnter data: ");
		scanf("%d",&stack[++top]);
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty");
		return;
	}
	else
		printf("%d is deleted",stack[top--]);
}

void display()
{
	int i;
	if(top==-1)
		printf("\nStack is empty");
	else{
		for(i=top;i>=0;i--)
			printf("\n%d",stack[i]);		
	}	
}

void peek()
{
	if(top==-1)
		printf("\nStack is Empty");
	printf("\n%d",stack[top]);
	
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Peek");
		printf("\n4. Display");
		printf("\n5. Exit");
		printf("\nEnter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:peek();
				break;
			case 4:display();
				break;
			case 5: return 1;
			default:printf("\n Invalid option");
		}	
	}
}

