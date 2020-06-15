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

void delete1()
{
	int pos,n;
	struct student *ptr,*ptr1;
	printf("Enter position who you want to delete:\n");
	scanf("%d",&pos);
	n=count(start);
	if(pos<0||pos>n+1)
		printf("\nInvalid Position\n");
		
	if(pos==1)
	{
		ptr=start;
		start=start->next;
		free(ptr);
		ptr=NULL;
	}
	else{
		ptr=start;
		for(int c=0;c<pos-2;c++)
			ptr=ptr->next;
		ptr1=ptr->next;
		ptr->next=ptr->next->next;
		free(ptr1);
		ptr1=NULL;
	}
}

void update()
{
	int pos,c,n,rollno,age;
	struct student *ptr;
	printf("Enter position that you wany to update:\n");
	scanf("%d",&pos);
	n=count(start);
	if(pos<0||pos>n+1)
		printf("Invalid position\n");
	printf("Enter the rollno:\n");
	scanf("%d",&rollno);
	printf("\nEnter the age:\n");
	scanf("%d",&age);
	if(pos==1)
	{
		ptr=start;
		ptr->rollno=rollno;
		ptr->age=age;
	}
	else{
		for(c=0,ptr=start;c<pos-1;c++)
			ptr=ptr->next;
		ptr->rollno=rollno;
		ptr->age=age;
	}
}

int sumAge(struct student*ptr)
{
	int sum=0;
	while(ptr!=NULL)
	{
		sum=sum+ptr->age;
		ptr=ptr->next;
	}
	return sum;
}

void reverse(){
	struct student *ptr=start,*ptr1=NULL,*ptr2=NULL;
	while(ptr)
	{
		ptr2=ptr->next;
		ptr->next=ptr1;
		ptr1=ptr;
		ptr=ptr2;
	}
	start=ptr1;
}

void updateByRollno()
{
	int rn;
	struct student* ptr;
	printf("\nEnter the Rollno whose data you want to update:");
	scanf("%d",&rn);
	ptr=start;
	while(ptr->rollno!=rn)
	{
		ptr=ptr->next;
	}
	printf("\nEnter new rollno:");
	scanf("%d",&ptr->rollno);
	printf("\nEnter new Age:");
	scanf("%d",&ptr->age);
}

int main()
{
	int ch;
	while(1)
	{
		printf("\n1. Add node");
		printf("\n2. Display");
		printf("\n3. Recursive display");
		printf("\n4. Insert node");
		printf("\n5. Delete node");
		printf("\n6. Upadate node");
		printf("\n7. Count node");
		printf("\n8. Sum age");
		printf("\n9. Update by rollno.");
		printf("\n10. Reverse");
		printf("\n10. Exit");
		printf("\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add();
				break;
			case 2: display(start);
				break;
			case 3: rdisplay(start);
				break;
			case 4: insert();
				break;
			case 5:delete1();
				break;
			case 6:update();
				break;
			case 7:printf("\nno. of nodes=%d\n",count(start));
				break;
			case 8:printf("\nSum of ages=%d\n",sumAge(start));
				break;
			case 9: updateByRollno();
				break;
			case 10:reverse();
				break;
			case 11:return 0;
			default: printf("\nInvalid option");
		}
	}
}
