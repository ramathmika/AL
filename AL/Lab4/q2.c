#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	int visited;
	struct node* next;
};

typedef struct node* Node;

Node init(Node root,int val){
	root = (Node)malloc(sizeof(struct node));
	root->val = val;
	root->visited = 0;
	root->next = NULL;
	return root;
}

Node Insert(Node l,int x){
	Node temp = l;
	Node newNode = (Node)malloc(sizeof(struct node));
	newNode->val = x;
	newNode->visited = 0;
	newNode->next = NULL;

	if(l == NULL){
		l = newNode;
		return l;
	}

	while(temp->next)
		temp = temp->next;

	temp->next = newNode;
	return l;
}

void Display(Node root){
	root = root->next;
	while(root){
		printf("%d ",root->val);
		root = root->next;
	}
}

void depth(Node *head, Node root,int visit[]){
	if(!(root))
		return;
	(root)->visited = 1;
	visit[(root->val)-1] = 1;
	printf("%d ",(root)->val);
	if((root)->next && visit[(root->next->val)-1] == 0)
		depth(head, head[(root)->next->val-1],visit);
	return;
}

void DFS(Node *root,int v){
	int visit[v],i;
	for(i=0;i<v;i++)
		visit[i] = 0;
	for(i=0;i<v;i++){
		if(visit[i] == 0){
			depth(root, root[i],visit);
			root[i]->visited = 1;
			visit[i] = 1;
		}
	}
}

void breadth(Node root, int visit[]){
	if(!(root))
		return;
	(root)->visited = 1;
	visit[(root->val)-1] = 1;
	printf("%d ",(root)->val);
	if((root)->next && visit[(root->next->val)-1] == 0)
		breadth((root)->next,visit);
	return;
}

void BFS(Node *root,int v){
	int visit[v],i;
	for(i=0;i<v;i++)
		visit[i] = 0;
	for(i=0;i<v;i++){
		if(visit[i] == 0){
			breadth(root[i],visit);
			root[i]->visited = 1;
			visit[i] = 1;
		}
	}
}

void main(){
	int v,v1,v2,i,j,ch;
	
	printf("Enter the number of vertices: ");
	scanf("%d",&v);

	Node *List = (Node *)malloc(sizeof(Node)*v);

	for(int i=0;i<v;i++)
		List[i] = init(List[i], i+1);

	do{
		printf("\n1.Enter edge: \n2.Display.\n3.DFS.\n4.BFS.\n5.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter edge: ");
					scanf("%d %d",&v1,&v2);
					List[v1-1] = Insert(List[v1-1],v2);
					List[v2-1] = Insert(List[v2-1],v1);
					break;
			case 2: for(i=0;i<v;i++){
						printf("\nNode %d: ",List[i]->val);
						Display(List[i]);
					}
					printf("\n");
					break;
			case 3: DFS(List,v);
					printf("\n");
					break;
			case 4: BFS(List,v);
					printf("\n");
					break;
			case 5: break;
		}
	}while(ch!=5);

}