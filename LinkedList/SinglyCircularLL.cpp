#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct student{
	int rollno;
	int age;
	struct student* next;
};

struct student* start=NULL;

struct student* nn(int rno,int ag)
{
	struct student* p=(struct student*)malloc(sizeof(struct student));
	p->rollno=rno;
	p->age=ag;
	p->next=NULL;
	return p;
}

void add()
{
	int rollno,age;
	char ch;
	struct student* p1;
	struct student* ptr;
	do{
		printf("\n Enter rollno:");
		scanf("%d",&rollno);
		printf("\n Enter age:");
		scanf("%d",&age);
		p1=nn(rollno,age);
		if(start==NULL)
		{
			start=p1;
			p1->next=start;	
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
				ptr=ptr->next;
			ptr->next=p1;
			p1->next=start;
		}
		printf("\n Do you want to add more node?(y/n): ");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}

void display(struct student* ptr)
{
	int i;
	if(ptr==NULL)
		printf("List is empty\n");
	else{
		do{
			printf("%d---->%d\n",ptr->rollno,ptr->age);
			ptr=ptr->next;
		}while(ptr!=start);
	}
}

int count(struct student* ptr)
{
	int count=0;
	if(ptr==NULL)
		return 0;
	else
	{
		do{
			count++;
			ptr=ptr->next;
		}while(ptr!=start);		
	}
	return count;
}

void insert()
{
	int pos,n,c,rollno,age;
	struct student *ptr,*p1;
	printf("\nEnter position: \n");
	scanf("%d",&pos);
	n=count(start);
	if(pos<0||pos>n+1)	
		printf("\nInvalid Position");
	else{
		printf("\n Enter Rollno: ");
		scanf("\n%d",&rollno);
		printf("\nEnter age:");
		scanf("\n%d",&age);
		p1=nn(rollno,age);
		if(pos==1)
		{
			ptr=start;
			do{
				ptr=ptr->next;
			}while(ptr->next!=start);
			ptr->next=p1;
			p1->next=start->next;
			start=p1;
		}
		else{
			ptr=start;
			c=0;
			while(pos-2>c)
			{
				ptr=ptr->next;
				c++;	
			}
			if(ptr->next==start)
			{
				ptr->next=p1;
				p1->next=start;
			}
			else
			{
				p1->next=ptr->next;
				ptr->next=p1;	
			}
		}
	}
}

void delete1()
{
	int pos,c,n;
	struct student *ptr,*ptr1;
	printf("\nEnter position of node which you want to delete\n");
	scanf("%d",&pos);
	n=count(start);
	if(pos<0||pos>n+1)	
		printf("\nInvalid Position");
	else{
		if(pos==1)
		{
			if(start->next==start)
			{
				free(start);
				start=NULL;	
			}
			else{
				ptr=start;
				while(ptr->next!=start)
				{
					ptr=ptr->next;
				}
				start=start->next;
				free(ptr->next);
				ptr->next=start;
			}			
		}
		else{
			ptr=start;
			c=0;
			while(pos-2>c)
			{
				ptr=ptr->next;
				c++;
			}
				ptr1=ptr->next;
				ptr->next=ptr->next->next;
				free(ptr1);
				ptr1=NULL;
		}
	}
}

void update()
{
	int n,c,rollno,age,pos;
	struct student *ptr;
	printf("\nEnter position of node which you want to update\n");
	scanf("%d",&pos);
	n=count(start);
	if(pos<0||pos>n+1)	
		printf("\nInvalid Position");
	else{
		ptr=start;
		c=0;
		while(pos-1>c)	
		{
			ptr=ptr->next;
			c++;
		}
		printf("\nEnter rollno: ");
		scanf("%d",&ptr->rollno);
		printf("\nEnter age: ");
		scanf("%d",&ptr->age);
	}
}

void reverse()
{
	struct student *current,*forward, *prev, *ptr;
	current=start;
	for(ptr=start;ptr->next!=start;ptr=ptr->next);
	prev=ptr;
	do{
		forward=current->next;
		current->next=prev;
		prev=current;
		current=forward;
	}while(current!=start);
	start=prev;	
}

int main()
{
	char ch;
	while(1)
	{
		printf("\n1:add");
		printf("\n2:display");
		printf("\n3:count node");
		printf("\n4:insert node");
		printf("\n5:delete node");
		printf("\n6:update node");
		printf("\n7:reverse node");
		printf("\n8:EXIT");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: add();
			break;
			case 2: display(start);
			break;
			case 3: printf("\nNo of node is:%d",count(start));
			break;
			case 4: insert();
			break;
			case 5: delete1();
			break;
			case 6: update();
			break;
			case 7: reverse();
			break;
		    case 8: return 0;
			
			default: printf("\nInvalid Option");
			
		}
	}	
}

