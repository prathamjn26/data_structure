#include<stdio.h>
#include<stdlib.h>
int find(int s[7],int x)
{
	int y;
	y=x;
	while(s[y]>0)
	{
		y=s[y];
	}
	return y;
}

void union1(int s[7],int x,int y)
{
	if(s[x]>s[y])
	{
		s[y]=s[x]+s[y];
		s[x]=y;
	}
	else{
		s[x]=s[x]+s[y];
		s[y]=x;
	}
}

int main()
{
	int e[3][9]={{0,0,1,2,2,3,3,4,5},{1,2,3,6,5,6,4,5,6},{4,20,14,5,9,12,8,11,10}};
	int v[9]={0};
	int s[7]={-1};
	int result[2][6];
	int i=0,x,y,es=9,n=7,min,vp,j;
	while(i<n-1)
	{
		for(j=0;j<es;j++)
		{
			if(e[2][j]<min)
			{
				min=e[2][j];	
				vp=j;
				x=e[0][j];
				y=e[1][j];
			}
		}	
		v[vp]=1;
		if(find(s,x)!=find(s,y))
		{
			result[0][i]=x;
			result[1][i]=y;
			union1(s,find(s,x),find(s,y));
			i++;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d--->%d\n",result[0][i],result[1][i]);
	}
}
