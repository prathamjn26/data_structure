#include<stdio.h>

void bubble_Sort(int arr[],int size)
{
 int flag=0;
 
	for(int i=0;i<size-1;i++)
	{
		printf("Pass %d:",i+1);  //print pass no.
		flag=0; //For optimise no. of passes
			
		for(int j=0;j<size-i-1;j++)
		{   //comparison
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;	
			}
		}
		
		for(int k=0;k<size;k++)
		{
			printf("%d ",arr[k]);  //print pass value
		}
		printf("\n");  //change line after each pass
		
		if(flag==0)
			break;
	}
	

}

int main()
{
	int arr1[]={1,6,2,78,23,45,76,3,4,11};
	bubble_Sort(arr1,10);
}
