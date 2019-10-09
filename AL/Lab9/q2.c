#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

struct node {
	int val;
	struct node *next;
};

typedef struct node* Node;

Node Init(Node root, int key){
	Node newNode = (Node)malloc(sizeof(struct node));
	newNode->val = key;
	newNode->next = NULL;
	if(!root){
		root = newNode;
		return root;
	}
	
	Node temp = root;
	while(temp->next)
		temp = temp->next;
	temp->next = newNode;
	return root;
}

void Display(Node root){
	if(!root){
		printf("Empty row\n");
		return ;
	}
	while(root){
		printf("%d ",root->val);
		root = root->next;
	}
	printf("\n");
}

void Search(Node table[], int m, int key){
	int r = key%m;
	while(table[r]){
		opcount++;
		if(table[r]->val == key){
			printf("Successful search\n");
			return ;
		}
		table[r] = table[r]->next;
	}
	printf("Unsuccessfulll search.\n");
}

void main(){
	int m,n,i,key,r;
	printf("Enter no of slots in hash table, and number of keys(m, n): \n");
	scanf("%d %d",&m, &n);
	Node table[m];
	for(i=0;i<m;i++){
		table[i] = (Node)malloc(sizeof(struct node));
		table[i] = NULL;
	}
	printf("Enter the keys: \n");
	for(i=0;i<n;i++){
		scanf("%d",&key);
		r = key%m;
		table[r] = Init(table[r],key);
	}

	// printf("Hash table: \n");
	// for(i=0;i<m;i++){
	// 	printf("\nRow %d:\n",i);
	// 	Display(table[i]);
	// }

	printf("Enter value to be searched: ");
	scanf("%d",&key);
	Search(table, m, key);
	printf("Key comparisions: %d\n",opcount);
}