#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node* next;
};

typedef struct node* Node;

Node Insert(Node l,int x){
	Node temp = l;
	Node newNode = (Node)malloc(sizeof(struct node));
	newNode->val = x;
	newNode->next = NULL;
	if(l == NULL){
		l = newNode;
		//l->val = x;
		//l->next = NULL;
		return l;
	}
	printf("Test");
	while(!temp->next)
		{   printf("Test");
		temp = temp->next;

	}
	temp->next = newNode;
	printf("Test");
	return l;
}

/*void ListInsert(Node l[],int e1,int e2){
	if(l[e1] == NULL)
		l[e1] = (Node)malloc(sizeof(Node));
	if(l[e2]==NULL)
		l[e1] = (Node)malloc(sizeof(Node));
	l[e1] = Insert(l[e1],e2);
	l[e2] = Insert(l[e2],e1);
}

void MatrixInsert(int m[10][10], int e1, int e2){
	m[e1-1][e2-1] = 1;
	m[e2-1][e1-1] = 1;
	//return m;
}*/

void Display(Node l){
	while(l!=NULL){
		printf("%d ",l->val);
		l = l->next;
	}
}

int main(){
	int ch,e1,e2,n,i,j;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	int m[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m[i][j] = 0;
	Node l[n];
	for(i=0;i<n;i++)
		l[i] = NULL;
	do{
		printf("1.Insert edge.\n2.Adjacency List Display.\n3.Adjacency Matrix Display.\n4.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");

		switch(ch){
			case 1: printf("Enter the edge to be inserted: \n");
					scanf("%d %d",&e1,&e2);
					//ListInsert(l,e1,e2);
					//MatrixInsert(m,e1,e2);
					l[e1-1] = Insert(l[e1-1],e2);
					l[e2-1] = Insert(l[e2-1],e1);

					m[e1-1][e2-1] = 1;
					m[e2-1][e1-1] = 1;
					printf("Edge Inserted.\n\n");
					break;
			case 2: /*for(i=0;i<n;i++){
						printf("Node %d:\n",i+1);
						Display(l[i]);
						printf("\n");
					}*/
					Display(l[0]);
					printf("\n");
					break;
			case 3: for(i=0;i<n;i++){
						for(j=0;j<n;j++)
							printf("%d ",m[i][j]);
						printf("\n");
					}
					printf("\n");
					break;
			case 4:	break;
		}
	}while(ch!=4);
	return 0;
}