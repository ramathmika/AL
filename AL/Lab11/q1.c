#include <stdio.h>

struct Edge{
	int src,dest,weight;
};

typedef struct Edge edge;

// struct Node{
// 	int val;
// 	struct Node* next;
// };

// typedef struct Node* node;

// struct head{
// 	int val;
// 	node first, last;
// };

// typedef struct head* header;

// node insert(header root, int val){
// 	node newNode;
// 	newNode = (node)malloc(sizeof(struct Node));
// 	newNode->val = val;
// 	newNode->next = NULL;

// 	if(!root->first){
// 		root->first = root->last = newNode;
// 		root->val = 1;
// 		return root;
// 	}

// 	node temp = root->next;
// 	while(temp->next)
// 		temp = temp->next;
// 	temp->next = newNode;
// 	root->last = newNode;
// 	root->val++;
// 	return root;
// }



int isCycle(int adjMatrix[100][], edge e){
	int parent[v],i,x,y;
	for(i=0;i<v;i++)
		parent[i] = -1;
	x = find(parent,e.src);
	y = find(parent,e.dest);
	if(x==y)
		return 1;
	return 0;
}

void main() {
	int v,e,i,j,e1,e2;
	printf("Enter the number of vertices and edges: ");
	scanf("%d %d",&v, &e);
	int res[v][v];
	edge edges[e];

	for(i=0;i<e;i++){
		printf("Enter edge: ");
		scanf("%d %d",e1,e2);
		// adjMatrix[e1][e2] = 1;
		edges[i].src = e1-1;
		edges[i].dest = e2-1;
		printf("Weight of the edge: ");
		scanf("%d",&edges[i].weight);
	}

	for(i=0;i<e-1;i++)
		for(j=0;j<e-i-1;j++)
			if(edges[j].weight>edges[j+1].weight){
				edge t = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = t;
			}

	for(i=0;i<v;i++)
		for(J=0;j<v;j++)
			res[i][j] = 0;

	for(i=0;i<e;i++){
		if(!isCycle(res,edges[i])){
			res[edges[i].src][edges[i].dest] = 1;
		}
	}

	// header list[v];
	// for(i=0;i<v;i++){
	// 	list[i] = (node)malloc(sizeof(struct Node));
	// 	list[i]->first = list[i]->last = NULL;
	// 	insert(list[i],i+1);
	// }


	printf("Adjacency matrix of the minimum cost spanning tree: \n");
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			printf("%d ",res[i][j]);
		printf("\n");
	}
}