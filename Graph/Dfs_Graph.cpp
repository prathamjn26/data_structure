#include<stdio.h>
#include<malloc.h>
 struct stack{
 	int data;
 	struct stack *next;
 };
 
 struct stack *top=NULL;
 
 struct stack *nn(int data)
 {
 	struct stack *p=(struct stack*)malloc(sizeof(struct stack));
 	p->data=data;
 	p->next=NULL;
 }
 
 void push(int data)
 {
 	struct stack *ptr;
 	ptr=nn(data);
 	if(top==NULL)
 		top=ptr;
 	else{
 		ptr->next=top;
 		top=ptr;
	 }
 }
 
 int pop()
 {
 	struct stack *ptr=top;
 	int x;
 	x=top->data;
 	top=top->next;
 	free(ptr);
 	ptr=NULL;
 	return x;
 }
int checkUnvisited(int s,int g[7][7],int v[])
{
	int i;
	for(i=0;i<7;i++)
	{
 		if(g[s][i]==1&&v[i]==0)
		{
 			push(s);
 			return i;
		}
	}
	return -1;
} 
void dfs(int s,int visited[],int g[7][7])
{
 	int i,x;
 	printf("%d\n",s);
 	visited[s]=1;
 	x=checkUnvisited(s,g,visited);
 	while(top)
 	{
 		if(x<0)
 		{
 			x=pop();
 		 	x=checkUnvisited(x,g,visited);	
		}
		else{
			printf("%d\n",x);
 			visited[x]=1;
 			x=checkUnvisited(x,g,visited);
		}		
	}
}
 
 
 int main()
 {
 	int graph[7][7]={{0,1,1,1,0,0,0},{1,0,1,0,0,0,0},{1,1,0,1,1,0,0},{1,0,1,0,1,0,0},{0,0,1,1,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0}};
 	int visited[7]={0};
 	dfs(0,visited,graph);
 }
