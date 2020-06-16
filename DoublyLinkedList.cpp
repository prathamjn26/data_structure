#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct student{
	int age;
	int rollno;
	struct student* next;
	struct student* pre;
};

struct student* start=NULL;

struct student* nn(int rollno,int age)
{
	struct student *p=(struct student*)malloc(sizeof(struct student));
	p->age=age;
	p->rollno=rollno;
	p->next=NULL;
	p->pre=NULL;
	return p;
}

void add ()
{
	struct student *ptr,*p1;
	int age,rollno;
	char ch;
	do{
		printf("Enter the rollno: ");
		scanf("%d",&rollno);
		printf("Enter the age: ");
		scanf("%d",&age);
		p1=nn(rollno,age);
		if(start==NULL)
			start=p1;
		else{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			p1->pre=ptr;
			ptr->next=p1;
		}
			printf("\nDo you want to add more(y/n):");
			fflush(stdin);
			ch=getchar();
	}while(ch=='y');
}

void fdisplay(struct student*ptr)
{
	if(ptr==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n%d---->%d",ptr->rollno,ptr->age);
			ptr=ptr->next;
		}		
	}
}

void recursiveDisplay(struct student* ptr)
{
	if(ptr!=NULL)
	{
		printf("\n%d---->%d",ptr->rollno,ptr->age);
		recursiveDisplay(ptr->next);
	}
}

void rdisplay(struct student* ptr)
{
	if(ptr==NULL)
		printf("List is empty");
	else
	{
		for(;ptr->next!=NULL;ptr=ptr->next);
		while(ptr!=NULL)
		{
			printf("\n%d---->%d",ptr->rollno,ptr->age);
			ptr=ptr->pre;			
		}	
	}
}

int count(struct student* ptr)
{
	int count=0;
	while(ptr!=NULL)
	{
		count=count+1;
		ptr=ptr->next;		
	}
	return count;
}
void insert(){
	int n,c=0,pos,rollno,age;
	struct student *p1,*ptr;
	n=count(start);
	printf("\nEnter position where you want to add: ");
	scanf("%d",&pos);
	if(pos<=0||pos>n+1)
		printf("\nInvalid position");
	else{
		printf("\nEnter rollno: ");
		scanf("%d",&rollno);
		printf("\nEnter age: ");
		scanf("%d",&age);
		p1=nn(rollno,age);
		if(pos==1)
		{
			p1->next=start;
			start->pre=p1;
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
			if(ptr->next==NULL)
			{
				p1->pre=ptr;
				ptr->next=p1;					
			}
			else{
				p1->pre=ptr;
				p1->next=ptr->next;
				ptr->next->pre=p1;
				ptr->next=p1;					
			}
		}
	}
}

void update()
{
	int pos,n,c;
	struct student *ptr;
	n=count(start);
	printf("\nEnter position where you want to update: ");
	scanf("%d",&pos);
	if(pos<=0||pos>n+1)
		printf("\nInvalid position");
	else{
		c=0;
		ptr=start;
		while(pos-1>c)
		{
			ptr=ptr->next;
			c++;
		}
		printf("\nEnter Rollno: ");
		scanf("%d",&ptr->rollno);
		printf("\nEnter age: ");
		scanf("%d",&ptr->age);
	}
}

void delete1()
{
	int pos,n,c;
	struct student *ptr;
	n=count(start);
	printf("\nEnter node which you want to delete: ");
	scanf("%d",&pos);
	if(pos<=0||pos>n+1)
		printf("\nInvalid position");	
	else{
		if(pos==1)
		{
			ptr=start;
			start->next->pre=NULL;
			start=start->next;
			free(ptr);
			ptr=NULL;
		}
		else{
			ptr=start;
			c=0;
			while(pos-1>c)
			{
				ptr=ptr->next;
				c++;
			}
			if(ptr->next==NULL)
			{
				ptr->pre->next=NULL;
				free(ptr);
				ptr=NULL;
			}
			else{
				ptr->next->pre=ptr->pre;
				ptr->pre->next=ptr->next;
				free(ptr);
				ptr=NULL;
			}
		}
	}
}

int main()
{
	char ch;
	while(1)
	{
		printf("\n1:add");
		printf("\n2:display");
		printf("\n3:recursive display");
		printf("\n4:reverse display");
		printf("\n5:insert");
		printf("\n6:delete");
		printf("\n7:update");	
		printf("\n8:count node");
		printf("\n9:EXIT");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: add();
			break;
			case 2: fdisplay(start);
			break;
			case 3: recursiveDisplay(start);
			break;			
			case 4: rdisplay(start);
			break;	
			case 5: insert();
			break;
			case 6: delete1();
			break;
			case 7: update();
			break;
			case 8: printf("\nNo of node is:%d",count(start));
			break;
			case 9: return 0;
			default: printf("\nInvalid Option");			
		}
	}
}

