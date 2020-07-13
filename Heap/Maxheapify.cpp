#include<stdio.h>
void heapify(int a[] ,int n)
{
	int temp, i ,j,x;
	for(i=(n-1)/2;i>=0;i--)
	{
		j=2*i+1;
		x=i;
		while(j<=n)
		{
			if(j<n&&a[j+1]>a[j])
				j=j+1;
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				i=j;
				j=2*i+1;
			}
			else
				break;			
		}
		i=x;
	}
 
}

void delete1(int a[],int n)
{
	int temp, i ,j;
	temp=a[0];
	a[0]=a[n];
	a[n]=temp;
	i=0;j=2*i+1;
	while(j<n)
	{
		if(j<n-1&&a[j+1]>a[j])
			j=j+1;
		if(a[i]<a[j])
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i=j;
			j=2*i+1;
		}
		else
			break;
	}
}

int main()
{
	int i;
	int a[]={10,20,30,50,15,11,28,31,32,30,35};
	heapify(a,11);
	for(i=10;i>=1;i--) 		//for sorting
		delete1(a,i);
	for(i=0;i<11;i++)
		printf("\n%d",a[i]);
}
