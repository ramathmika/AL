#include<stdio.h>
#include<stdlib.h>
int cost[10][10],min_cost=9999;


void swap(int *a, int *b){ 
	int temp = *a;
	*a = *b;
    *b = temp;
}

int find_cost(int cost[][10],int path[],int n,int start) {
	int i,j,k,c=0;
	c += cost[start][path[0]];
	for(i=0;i<n-1;i++){
		c += cost[path[i]][path[i+1]];
	}
	c += cost[path[n-1]][start];
	return c;
}

void permutation(int path[],int i,int n,int start){
	if(i==n){
		int c = find_cost(cost,path,n,start);
		printf("\n\nPath: ");
		printf("%d ",start);
		for(i=0;i<n;i++)
			printf("%d ",path[i]);
		printf("%d ",start);
		printf("\nCost: %d",c);
		if(c < min_cost){
			min_cost = c;
		}
		return;
	}
	for(int j=1;j<n;j++){
		swap(path+i,path+j);
		permutation(path,i+1,n,start);
		swap(path+i,path+j);
	}
}


int tsp(int cost[][10], int n, int start){
	int i,path[n-1],k=0,c;
	//path[0] = start;
	for(i=0;i<n;i++){
		if(i!=start)
			path[k++] = i; //i+1
	}
	//path[n] = start;
	c = find_cost(cost,path,n-1,start);
	printf("\n\nPath: ");
	printf("%d ",start);
	for(i=0;i<n-1;i++)
		printf("%d ",path[i]);
	printf("%d ",start);
	printf("\nCost: %d",c);
	if(c < min_cost){
		min_cost = c;
	}
	permutation(path,0,n-1,start);
	return min_cost;
}

void main(){
	int n,i,j,start;
	printf("Enter the number of cities: ");
	scanf("%d",&n);
	printf("Enter the cost adjacency matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	printf("Enter starting city: ");
	scanf("%d",&start);
	int minimum = tsp(cost,n,start);
	printf("\n\nMinimum travelling cost: %d\n",minimum);
}