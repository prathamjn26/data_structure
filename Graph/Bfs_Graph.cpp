#include<stdio.h>
#include<malloc.h>
 struct queue{
 	int data;
 	struct queue *next;
 };
 
 struct queue *front=NULL;
 struct queue *rear=NULL;
 
 struct queue *nn(int data)
 {
 	struct queue *p=(struct queue*)malloc(sizeof(struct queue));
 	p->data=data;
 	p->next=NULL;
 }
 
 void insert(int data)
 {
 	struct queue *ptr,*ptr1;
 	ptr=nn(data);
 	if(front==NULL)
 		front=rear=ptr;
 	else{
 		rear->next=ptr;
 		rear=ptr;
	 }
 }
 
 int delete1()
 {
 	struct queue *ptr;
 	int x;
 	x=front->data;
 	ptr=front;
 	front=front->next;
 	free(ptr);
 	ptr=NULL;
 	return x;
 }
 
int bfs(int s,int visited[],int g[7][7])
{
 	int i,x;
 	printf("%d\n",s);
 	visited[s]=1;
 	insert(s);
 	while(front)
 	{
 		x=delete1();
 		for(i=0;i<7;i++)
		{
	 		if(g[x][i]==1&&visited[i]==0){
	 			printf("%d\n",i);
	 			visited[i]=1;
	 			insert(i);
			 }
	    }
	}
}
 
 
 int main()
 {
 	int graph[7][7]={{0,1,1,1,0,0,0},{1,0,1,0,0,0,0},{1,1,0,1,1,0,0},{1,0,1,0,1,0,0},{0,0,1,1,0,1,1},{0,0,0,0,1,0,0},{0,0,0,0,1,0,0}};
 	int visited[7]={0};
 	bfs(1,visited,graph);
 }
