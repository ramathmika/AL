#include <stdio.h>
#include <stdlib.h>


void depth(int matrix[10][],int visited[],i){
	int j;
	printf("%d",i+1)
	visited[i] = 1;
	for(j=0;j<v;j++){
		if(!visited[j] && matrix[i][j]==1)
			depth(j);
	}
}

void DFS(int matrix[10][],int v){
	int visited[v],i,j;
	for(i=0;i<v;i++)
		visited[i] = 0;
	depth(matrix,visited,0);
}


void Source_Removal(int matrix[10][], int v){
	
}



void main(){
	int v,v1,v2,i,j,ch;
	
	printf("Enter the number of vertices: ");
	scanf("%d",&v);

	int matrix[v][v];

	do{
		printf("\n1.Enter edge: \n2.Display.\n3.DFS Topological Sort.\n4.Source removal Topological Sort.\n5.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter edge: ");
					scanf("%d %d",&v1,&v2);
					matrix[v1-1][v2-1] = 1;
					
					break;
			case 2: for(i=0;i<v;i++){
						for(j=0;j<v;j++)
							printf("%d ",matrix[i][j]);
						printf("\n");
					}
					printf("\n");
					break;
			case 3: DFS(matrix,v);
					printf("\n");
					break;
			case 4: Source_Removal(matrix,v);
					printf("\n");
					break;
			case 5: break;
		}
	}while(ch!=5);
}