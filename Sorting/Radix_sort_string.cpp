//index based sorting
#include<stdio.h>
void count_Sort(int arr[],int size,int temp)
{
	int count[27];
	int output[size],i;
	for(i=0;i<27;i++)
		count[i]=0;
	for(i=0;i<size;i++)
		count[(arr[i]/temp)%temp]++;
	for(i=1;i<27;i++)
		count[i]=count[i]+count[i-1];
	for(i=size-1;i>=0;i--)
		output[--count[(arr[i]/temp)%temp]]=arr[i];
	for(i=0;i<size;i++)
	{
		arr[i]=output[i];
	}
}

void radixSort(int arr[],int size,int max)
{
	int temp;
	for(temp=1;max/temp>0;temp=temp*10)
	{
		count_Sort(arr,size,temp);
	}
}
 
int main()
{
	char arr[]={'ba','b','arr','ce','db'},max=0,i;
	for(i=0;i<11;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
//	radixSort(arr,5,max);

	for(i=0;i<5;i++)
	{
		printf("%s\t",arr[i]);
	}
}

//timecomplexity=o(d(n+k))
