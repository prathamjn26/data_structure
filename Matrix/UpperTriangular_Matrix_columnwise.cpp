//column wise
#include<stdio.h>
#define n1 4

int A[(n1*(n1+1))/2]={0};
void insert(int i,int j, int ele)
{
	if(i<=j)
		A[(i*(i+1))/2+j]=ele;
}
int get(int i,int j)
{
	if(i<=j)
		return A[(i*(i+1))/2+j];
	else
		return 0;
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
	for(i=0;i<n1;i++)
	{
		for(j=0;j<=i;j++)
		{
		printf("Enter value of A[%d][%d]: ",j,i);
		scanf("%d",&x);
		insert(j,i,x);	
		}
	}
	display(n1);
}
