#include <stdio.h>
#include <limits.h>


int mini(int dist[], int path[], int v){
	int min = INT_MAX, i, ind;
	for(i=0;i<v;i++)
		if(!path[i] && dist[i]<=min){
			min = dist[i];
			ind = i;
		}
	return ind;
}

void Dijkstra(int graph[][100], int start, int v){

	int dist[v], path[v], ind, i, j;

	for(i=0;i<v;i++){
		dist[i] = INT_MAX;
		path[i] = 0;
	}

	dist[start] = 0;

	for(j=0;j<v-1;j++){
		ind = mini(dist,path,v);
		path[ind] = 1;

		for(i=0;i<v;i++)
			if(!path[i] && graph[ind][i] && dist[ind]!=INT_MAX && ((dist[ind]+graph[ind][i])<dist[i]))
				dist[i] = dist[ind] + graph[ind][i];
	}


	printf("\nShortest paths to each vertex from vertex %d is:\n",start);
	for(i=0;i<v;i++)
		if(i!=start){
			printf("Vertex %d: %d\n",i+1,dist[i]);
		}

}

// struct node{
// 	int val;
// 	struct node* next;
// };
// typedef struct node* Node;

void main(){
	int v,i,j;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	int graph[v][v];

	printf("Enter graph/weight matrix.(0 if no edge)\n");
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			scanf("%d",&graph[i][j]);

	int start;
	printf("Enter starting vertex number: ");
	scanf("%d",&start);

	Dijkstra(graph,start-1, v);

	
}