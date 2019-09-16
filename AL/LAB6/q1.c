#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcount = 0;

struct node {
	int val;
	struct node *lchild, *rchild;
};

typedef struct node* TreeNode;

TreeNode Insert(TreeNode root){
	int key,i;
	char dir[100];
	printf("Enter the key: ");
	scanf("%d",&key);

	TreeNode newNode = (TreeNode)malloc(sizeof(struct node));
	newNode->val = key;
	newNode->lchild = NULL;
	newNode->rchild = NULL;

	if(!root){
		root = newNode;
		return root;
	}

	printf("Enter the direction from the root to this node: ");
	scanf("%s",dir);

	TreeNode temp = root;

	int n = strlen(dir);

	for(i=0;i<n-1;i++){
		if(dir[i] == 'L')
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}
	if(dir[i] == 'L')
		temp->lchild = newNode;
	else
		temp->rchild = newNode;

	return root;
}

int nodeCount(TreeNode root){
	opcount++;
	if(!root)
		return 0;
	return (1 + nodeCount(root->lchild) + nodeCount(root->rchild));
}

void main(){
	int ch;
	TreeNode root = NULL;
	do{
		printf("\n1.Insert Node.\n2.Number of nodes\n3.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1: root = Insert(root);
					break;
			case 2: printf("Number of nodes: %d\n",nodeCount(root));
					printf("Opcount: %d\n",opcount);
					opcount = 0;
					break;
			case 3: break;
		}
	}while(ch!=3);
}