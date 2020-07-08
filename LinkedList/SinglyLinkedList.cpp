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
		printf("\nEnter rollno: ");
		scanf("%d",&rollno);
		printf("\nEnter age: ");
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
		printf("\nDo you want to add more node?(y/n): ");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}

void display(struct student* ptr)
{
	if(ptr==NULL)
		printf("\nList is empty");
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
	printf("\nEnter position: ");
	scanf("%d",&pos);
	n=count(start);
	if(pos<0||pos>n+1)	
		printf("\nInvalid Position");
	else{
		printf("\nEnter Rollno: ");
		scanf("%d",&rollno);
		printf("\nEnter age: ");
		scanf("%d",&age);
		ptr=nn(rollno,age);
		if(pos==1)
		{
			ptr->next=start;
			start=ptr;
		}
		else{
			ptr1=start;
			for(c=0;c<pos-2;c++)
			{
				ptr1=ptr1->next;
			}
			ptr->next=ptr1->next;
			ptr1->next=ptr;
		}
	}
}

void delete1()
{
	int pos,n;
	struct student *ptr,*ptr1;
	printf("\nEnter position who you want to delete: ");
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
	printf("\nEnter the rollno: ");
	scanf("%d",&rollno);
	printf("\nEnter the age: ");
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

void middle(struct student *ptr)
{
	struct student *ptr1=ptr;
	while(ptr&&ptr->next)
	{
		ptr=ptr->next->next;
		if(ptr)
			ptr1=ptr1->next;
	}
	printf("%d---->%d",ptr1->rollno,ptr1->age);
}

void deleteByRollno()
{
	int rollno;
	struct student *ptr,*ptr1;
	printf("\nEnter rollno which data you want to delete: ");
	scanf("%d",&rollno);
	if(start->rollno==rollno)
	{
		ptr=start;
		start=start->next;
		free(ptr);
		ptr=NULL;
	}
	else{
		ptr=start;
		while(ptr&&ptr->rollno!=rollno)
		{
			ptr1=ptr;
			ptr=ptr->next;	
		}
		if(ptr)
		{
			ptr1->next=ptr->next;
			free(ptr);
			ptr=NULL;
		}
		else
			printf("\nRollno not found");
	}
}

void isLoop()
{
	struct student *ptr=start,*ptr1=start;
	do{
	ptr=ptr->next;
	ptr1=ptr1->next;
	if(ptr1)
		ptr1=ptr1->next;
	}while(ptr1!=ptr&&ptr1&&ptr);
	if(ptr1==ptr&&ptr1)
		printf("\nThere is a loop");
	else
		printf("\nNo loop");
}

void isSorted()
{
	struct student *ptr=start;
	int rollno=-1,flag=0;
	while(ptr)
	{
		if(ptr&&ptr->rollno<rollno)
		{	
			flag=1;
			break;
		}		
			rollno=ptr->rollno;
			ptr=ptr->next;
	}
	if(flag==1)
		printf("\nNot Sorted");
	else
		printf("\nSorted");
}

void insertAtSortedPosition()
{
	struct student *ptr,*ptr1=start,*ptr2=NULL;
	int age,rollno;
	printf("\nEnter Rollno: ");
	scanf("%d",&rollno);
	printf("\nEnter age: ");
	scanf("%d",&age);
	ptr=nn(rollno,age);
	while(ptr1&&ptr1->rollno<ptr->rollno)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	ptr->next=ptr1;
	if(ptr1!=start)
		ptr2->next=ptr;
	else
		start=ptr;
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
		printf("\n11. Middle");
		printf("\n12. DeleteByRollno");
		printf("\n13. isLoop");
		printf("\n14. isSorted");
		printf("\n15. Insert at sorted position");
		printf("\n16. Exit");
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
			case 11:middle(start);
				break;
			case 12:deleteByRollno();
				break;
			case 13:isLoop();
				break;
			case 14:isSorted();
				break;
			case 15:insertAtSortedPosition();
				break;
			case 16:return 0;
			default: printf("\nInvalid option");
		}
	}
}
