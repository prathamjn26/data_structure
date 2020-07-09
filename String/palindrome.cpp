#include<stdio.h>
int main()
{
	int i,j,flag=0;
	char name[]="xabcx";
	for(i=0;name[i];i++);
		i=i-1;
	for(j=0;i>j;i--,j++)
	{
		if(name[j]==name[i])
			flag=1;
		else
		{
			flag=0;
			break;	
		}
	}
	if(flag==1)
		printf("\nString is a palindrome");
	else
		printf("\nString is not a palindrome");
}

//Another way
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i,j=0,count=0;
//	char name[]="xabax";
//	for(i=0;name[i];i++);
//		count=i;
//		i=i-1;
//	while((j<=count/2)||(i==j-1))
//	{
//		printf("\ni:%d,j:%d",i,j);
//		if(name[j]!=name[i])
//		{
//			printf("\nString is not a palindrome");	
//			exit(0);		
//		}
//		else
//			printf("\nI::%d\t",i--);
//			printf("\nJ::%d\t",j++);
//	}
//		printf("\nString is a palindrome");
//}
