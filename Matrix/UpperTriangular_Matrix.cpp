//row wise
#include<stdio.h>
#define n1 4
int A[(n1*(n1+1))/2]={0};
void insert(int i,int j, int ele)
{
	if(i<=j)
		A[(n1*j-(j*(j-1))/2)+i-j]=ele;
}
int get(int i,int j)
{
	if(i<=j)
		return A[n1*j-(j*(j-1))/2+i-j];
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
		for(j=i;j<n1;j++)
		{
		printf("Enter value of A[%d][%d]: ",i,j);
		scanf("%d",&x);
		insert(i,j,x);	
		}
	}
	display(n1);
}
