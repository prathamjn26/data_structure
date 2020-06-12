#include<stdio.h>
#include<string.h>
struct student{
	int rollno;
	char name[20];
	int marks;
};

int main()
{
	struct student a;
	printf("%d",sizeof(a));
	a.rollno=20;
	a.marks=80;
	strcpy(a.name,"pratham");
	printf("%d,%d,%s",a.rollno,a.marks,a.name);
	return 0;
}
