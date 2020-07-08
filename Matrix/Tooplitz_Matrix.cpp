//row wise
#include<stdio.h>
#define n1 5

int A[2*n1-1]={0};
void insert(int i,int j, int ele)
{
	if(i<=j)
		A[j-i]=ele;
	else
		A[n1+i-j-1]=ele;
}
int get(int i,int j)
{
	if(i<=j)
		return A[j-i];
	else
		return A[n1+i-j-1];
}
void display(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ", get(i,j));
		}
		printf("\n");
	}
}
int main()
{
	int i,x,j;
		for(j=0;j<n1;j++)
		{
		printf("Enter value of A[0][%d]: ",j);
		scanf("%d",&x);
		insert(0,j,x);	
		}	
		for(i=1;i<n1;i++)
		{
		printf("Enter value of A[%d][0]: ",i);
		scanf("%d",&x);
		insert(i,0,x);	
		}
	display(n1);
}
