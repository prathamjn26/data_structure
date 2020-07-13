#include<stdio.h>
int main()
{
	int arr[11]={1,2,3,4,6,7,8,9,10,11};
	int i,sum=0,sum1=0,d;
	sum1=(arr[9]*(arr[9]+1))/2;
	for(i=0;i<11;i++)
	 sum=sum+arr[i];
	printf("Missing is:%d",sum1-sum);
}
