#include <stdio.h>
#include<stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode *lchild,*rchild;
};

typedef struct TreeNode* TreeNode;

int max(int x, int y){
	return x>y?x:y;
}

// TreeNode NewNode(int x){
// 	TreeNode temp = (TreeNode)malloc(sizeof(TreeNode));
// 	temp->val = x;
// 	temp->lchild = temp->rchild = NULL;
// 	return temp;
// }

TreeNode CreateTree(TreeNode root, int x){
	if(root==NULL){
		root = (TreeNode)malloc(sizeof(TreeNode));
		root->val = x;
		root->lchild = root->rchild = NULL;
		return root;
	}

	if(x < root->val)
		root->lchild = CreateTree(root->lchild,x);
	else 
		root->rchild = CreateTree(root->rchild,x);
	return root;
}

int Height(TreeNode root){
	if(!root)	
		return 0;
	return 1 + max(Height(root->lchild),Height(root->rchild));
}

void balanceFactor(TreeNode root){
	if(!root)
		return;
	printf("\nNode %d: %d",root->val,(Height(root->lchild)-Height(root->rchild)));
	balanceFactor(root->lchild);
	balanceFactor(root->rchild);
}

int main(){
	TreeNode root = NULL;
	int ch,val;
	do{
		printf("1.Insert into tree.\n2.Balance Factors.\n3.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch){
			case 1: printf("Enter value for node: ");
					scanf("%d",&val);
					root = CreateTree(root,val);
					printf("Node added.\n");
					printf("\n");
					break;
			case 2:	balanceFactor(root);
					printf("\n\n");
					break;
			case 3: break;
		}
	}while(ch!=3);
	return 0;
}