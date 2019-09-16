#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode *lchild,*rchild;
};

typedef struct TreeNode* TreeNode;

TreeNode NewNode(int x){
	TreeNode temp = (TreeNode)malloc(sizeof(TreeNode));
	temp->val = x;
	temp->lchild = temp->rchild = NULL;
	return temp;
}

TreeNode CreateTree(TreeNode root, int x){
	if(root==NULL){
		root = (TreeNode)malloc(sizeof(TreeNode));
		root->val = x;
		root->lchild = root->rchild = NULL;
	//	printf("Root added.\n");
		return root;
	}

	if(x < root->val)
		root->lchild = CreateTree(root->lchild,x);
	else 
		root->rchild = CreateTree(root->rchild,x);
	return root;
}

TreeNode SearchKey(TreeNode root, int key){
	TreeNode temp = root;

	if(root==NULL){
		root = CreateTree(root,key);
		printf("Empty tree. Key inserted as a node.\n");
		return root;
	}

	while(temp!=NULL){
		if(key == temp->val){
			printf("Key found.\n");
			return root;
		}
		else if(key>temp->val)
			temp = temp->rchild;
		else
			temp = temp->lchild;
	}

	printf("Key not found. Key inserted as a node.\n");
	root = CreateTree(root, key);
	return root;
}

void Inorder(TreeNode root){
	if(!root)
		return ;
	Inorder(root->lchild);
	printf("%d ",root->val);
	Inorder(root->rchild);
}

void Preorder(TreeNode root){
	if(!root)
		return ;
	printf("%d ",root->val);
	Preorder(root->lchild);
	Preorder(root->rchild);
}

void Postorder(TreeNode root){
	if(!root)
		return ;
	Postorder(root->lchild);
	Postorder(root->rchild);
	printf("%d ",root->val);
}

int main(){
	TreeNode root = NULL;
	int ch,val;
	do{
		printf("1.Insert into tree.\n2.Search in tree.\n3.Inorder Traversal.\n4.Preorder Traversal.\n5.Postorder Traversal.\n6.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch){
			case 1: printf("Enter value for node: \n");
					scanf("%d",&val);
					root = CreateTree(root,val);
					printf("Node added.\n");
					printf("\n");
					break;
			case 2:	printf("Enter key to be searched: \n");
					scanf("%d",&val);
					root = SearchKey(root,val);
					printf("\n");
					break;
			case 3: Inorder(root);
					printf("\n\n");
					break;
			case 4: Preorder(root);
					printf("\n\n");
					break;
			case 5: Postorder(root);
					printf("\n\n");
					break;
			case 6: break;
		}
	}while(ch!=6);
	return 0;
}