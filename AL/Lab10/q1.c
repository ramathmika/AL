#include <stdio.h>
#define INF 999999
int opcount = 0;

void main(){
	int n,i,j,k;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	int graph[n][n],reach[n][n];
	printf("Enter the adjacency matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
			reach[i][j] = graph[i][j];
		}

	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				reach[i][j] = reach[i][j] || (reach[i][k]&&reach[k][j]);
				opcount++;
			}

	

	printf("Transitive closure: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",reach[i][j]);
		printf("\n");
	}
	printf("Opcount: %d\n",opcount);
}