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
			start=p1;
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=p1;
		}
		printf("\n Do you want to add more node?(y/n): ");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}

void display(struct student* ptr)
{
	if(ptr==NULL)
		printf("\n List is empty");
	else
	{
		for(;ptr!=NULL;ptr=ptr->next)
		{
			printf("\n%d--->%d",ptr->rollno,ptr->age);
		}
	}
}

void rdisplay(struct student* ptr)
{
	if(ptr!=NULL)
	{
		printf("\n%d--->%d",ptr->rollno,ptr->age);
		rdisplay(ptr->next);
	}
}

int count(struct student* ptr)
{

	int count;
	for(count=0;ptr!=NULL;ptr=ptr->next)
		count++;
	return count;
}

void insert()
{
	int pos,rollno,age,n,c;
	struct student *ptr1,*ptr;
	printf("\nEnter position: \n");
	scanf("%d",&pos);
	n=count(start);
	printf("pos: %d",pos);
	if(pos<0||pos>n+1)	
		printf("\nInvalid Position");
	else{
		printf("\n Enter Rollno: ");
		scanf("\n%d",&rollno);
		printf("\nEnter age:");
		scanf("\n%d",&age);
		ptr=nn(rollno,age);
		if(pos==1)
		{
			ptr->next=start;
			start=ptr;
			printf("first");
		}
		else{
			ptr1=start;
			for(c=0;c<pos-2;c++)
			{
				ptr1=ptr1->next;
			}
			ptr->next=ptr1->next;
			ptr1->next=ptr;
			printf("second");
		}
	}
}

int main()
{
	add();
	rdisplay(start);
	insert();
	rdisplay(start);
	return 0;
}
