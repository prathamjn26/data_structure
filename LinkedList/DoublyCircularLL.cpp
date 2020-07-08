#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct student{
	int rollno;
	int age;
	struct student* next;
	struct student* pre;
};

struct student* start=NULL;

struct student* nn(int rno,int ag)
{
	struct student* p=(struct student*)malloc(sizeof(struct student));
	p->rollno=rno;
	p->age=ag;
	p->next=NULL;
	p->pre=NULL;
	return p;
}

void add ()
{
	int rollno,age;
	char ch;
	struct student* p1;
	do{
		printf("\nEnter rollno: ");
		scanf("%d",&rollno);
		printf("\nEnter age: ");
		scanf("%d",&age);
		p1=nn(rollno,age);
		if(start==NULL)
		{
			p1->pre=p1->next=start=p1;
		}
		else{
			p1->pre=start->pre;
			p1->next=start;
			start->pre->next=p1;
			start->pre=p1;
		}
		printf("\nDo you want to add more node?(y/n)");
		fflush(stdin);
		ch=getchar();
	}while(ch=='y');
}

int count(struct student* ptr)
{
	int count=0;
	if(ptr==NULL)
		return 0;
	do{
		count++;
		ptr=ptr->next;
	}while(ptr!=start);
	return count;
}

void fdisplay(struct student* ptr)
{
	if(ptr==NULL)
		printf("\nList is empty!!!");
	else{
		do{
			printf("%d--->%d\n",ptr->rollno,ptr->age);
			ptr=ptr->next;	
		}while(ptr!=start);
	}
}

void rdisplay(struct student* ptr)
{
	struct student *ptr1;
	if(ptr==NULL)
		printf("\nList is empty!!!");
	else{
		ptr1=ptr->pre;
		do{
			printf("%d--->%d\n",ptr1->rollno,ptr1->age);
			ptr1=ptr1->pre;	
		}while(ptr1!=ptr->pre);
	}
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
		printf("\nEnter Rollno: ");
		scanf("%d",&rollno);
		printf("\nEnter age: ");
		scanf("%d",&age);
		p1=nn(rollno,age);
		if(pos==1)
		{
			p1->pre=start->pre;
			p1->next=start;
			start->pre->next=p1;
			start->pre=p1;
			start=p1;
		}
		else{
			c=0;
			ptr=start;
			while(pos-c>2)
			{
				ptr=ptr->next;
				c++;
			}
			p1->pre=ptr;
			p1->next=ptr->next;
			ptr->next->pre=p1;
			ptr->next=p1;				
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
			start->next->pre=start->pre;
			start=start->next;
			free(start->pre->next);
			start->pre->next=start;
			}
		}
		else{
			c=0;
			ptr=start;
			while(pos-c>1)
			{
				ptr=ptr->next;
				c++;
			}
			ptr->next->pre=ptr->pre;
			ptr->pre->next=ptr->next;
			free(ptr);
			ptr=NULL;
		}
	}
}

void reverse(struct student* ptr)
{
	struct student* ptr1=NULL;
	while(ptr->next!=start)
	{
		ptr1=ptr->pre;
		ptr->pre=ptr->next;
		ptr->next=ptr1;
		ptr=ptr->pre;
	}
	start=ptr1->pre;
}


int main()
{
	char ch;
	while(1)
	{
		printf("\n1:add");
		printf("\n2:display");
		printf("\n3:reverse display");
		printf("\n4:insert");
		printf("\n5:delete");
		printf("\n6:reverse");	
		printf("\n7:count node");
		printf("\n8:EXIT");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: add();
			break;
			case 2: fdisplay(start);
			break;
			case 3: rdisplay(start);
			break;	
			case 4: insert();
			break;
			case 5: delete1();
			break;
			case 6: reverse(start);
			break;
			case 7: printf("\nNo of node is:%d",count(start));
			break;
			case 8: return 0;			
			default: printf("\nInvalid Option");
			
		}
	}
}

