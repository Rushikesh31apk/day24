#include<stdio.h>

void disjkstra(int src,int cost[10][10],int n)
{
	int i,j,u,w,min=0,visited[10]={0},dist[10];
	for(i=1;i<=n;i++)
	{
		dist[i]=cost[src][i];
	}
	visited[src]=1;
	dist[src]=0;
	for(i=2;i<=n;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		{
			if(!visited[j])
			{
				if(dist[j]<min)
				{
					min=dist[j];
					u=j;
				}
			}
		}
		visited[u]=1;
		for(w=1;w<=n;w++)
		{
			if(cost[u][w] != 999 && visited[w]==0)
			{
				if(dist[w]>cost[u][w]+dist[u])
				{
					dist[w]=cost[u][w]+dist[u];
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(i != src){
		      printf("Shortest path %d to %d  = %d\n",src,i,dist[i]);
	     }
	}
}
int main()
{
	int i,j;
	int c[10][10],n,src;
	printf("Enter the no.of vertices:");
	scanf("%d",&n);
	printf("Enter the weight in Matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nEnter weight: %d-->%d vertices: ",i,j);
			scanf("%d",&c[i][j]);
		}
	}
	printf("Enter Starting vertex:");
	scanf("%d",&src);
	disjkstra(src,c,n);
}
/*
output:---------------->

Enter the no.of vertices:5
Enter the weight in Matrix:

Enter weight: 1-->1 vertices: 999

Enter weight: 1-->2 vertices: 7

Enter weight: 1-->3 vertices: 999

Enter weight: 1-->4 vertices: 999

Enter weight: 1-->5 vertices: 999

Enter weight: 2-->1 vertices: 999

Enter weight: 2-->2 vertices: 999

Enter weight: 2-->3 vertices: 1

Enter weight: 2-->4 vertices: 999

Enter weight: 2-->5 vertices: 5

Enter weight: 3-->1 vertices: 2

Enter weight: 3-->2 vertices: 999

Enter weight: 3-->3 vertices: 999

Enter weight: 3-->4 vertices: 6

Enter weight: 3-->5 vertices: 999

Enter weight: 4-->1 vertices: 999

Enter weight: 4-->2 vertices: 7

Enter weight: 4-->3 vertices: 999

Enter weight: 4-->4 vertices: 999

Enter weight: 4-->5 vertices: 999

Enter weight: 5-->1 vertices: 999

Enter weight: 5-->2 vertices: 999

Enter weight: 5-->3 vertices: 999

Enter weight: 5-->4 vertices: 1

Enter weight: 5-->5 vertices: 999

Enter Starting vertex:1

Enter Starting vertex:1

Shortest path 1 to 2  = 7
Shortest path 1 to 3  = 8
Shortest path 1 to 4  = 13
Shortest path 1 to 5  = 12

*/
