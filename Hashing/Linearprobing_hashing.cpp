#include<stdio.h>
#include<malloc.h>
#define size 10

int arr[size]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
void insert(int data)
{
	int i,x=0,index;
	index=data%10;
	if(arr[index]==-1)
	{
		arr[index]=data;
	}
	else
		{
			i=(index+x)%10;
			while(arr[i]!=-1)
				i=(index+(x++))%10;
			arr[i]=data;
		}
}

int search(int data)
{
	int i=0;
	while(arr[((data%10)+i)%10]!=-1&&i<10)
	{
		if(arr[((data%10)+i)%10]==data)
			return 1;
		i++;
	}
	return -1;
}

void display()
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==-1)
			continue;
		printf("%d ",arr[i]);
	}
}

int main()
{
	int ch,v,val,result,c=0;
	while(1)
	{
		printf("\n1. Insert");
		printf("\n2. Display");
		printf("\n3. Search");
		printf("\n4. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(c<10)
				{
					printf("\nEnter value: ");
					scanf("%d",&v);
					insert(v);
					c++;	
				}
				break;
			case 2:display();
				break;
			case 3:
				printf("\nEnter element for search: ");
				scanf("%d",&val);
				result=search(val);
				if(result==1)
					printf("\nResult Found");
				else
					printf("\nResult not Found");
				break;
			case 4:return 0;
			default:printf("\nInvalid Choice");
		}	
	}
}
