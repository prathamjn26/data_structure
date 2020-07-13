#include<stdio.h>
void insert(int a[] ,int i)
{
	int t=a[i];
	while(i>0&& t>a[(i-1)/2])
	{
		a[i]=a[(i-1)/2];	
		i=(i-1)/2;
	}
	a[i]=t;
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
	int a[]={10,20,30,50,15,11,28};
	for(i=1;i<=6;i++) 		//create of tree  time complexity: nlogn so due to this reason we use maxheapify
	{
		insert(a,i);
	}
	for(i=6;i>=1;i--) 		//for sorting
	{
		delete1(a,i);
	}
	for(i=0;i<7;i++)
		printf("\n%d",a[i]);
}
