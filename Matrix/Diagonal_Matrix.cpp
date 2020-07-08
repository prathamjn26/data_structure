#include<stdio.h>
#define n1 5

int A[n1]={0};
void insert(int i,int j, int ele)
{
	if(i==j)
		A[i]=ele;
}
int get(int i,int j)
{
	if(i==j)
		return A[i];
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
	int i,x,n;
	printf("Enter size of diagonal matrix: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter value of A[%d][%d]: ",i,i);
		scanf("%d",&x);
		insert(i,i,x);
	}
	display(n);
}
