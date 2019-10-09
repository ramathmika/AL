#include <stdio.h>
int opcount = 0;

void main(){
	int n,i,j,k;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int graph[n][n],dist[n][n];
	printf("Enter the graph matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
			dist[i][j] = graph[i][j];
		}

	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					opcount++;
					dist[i][j] = dist[i][k] + dist[k][j];
				}


	printf("Shortest paths: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",dist[i][j]);
		printf("\n");
	}
}