#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
	return x>y?x:y;
}

//int flag = 1;

struct TreeNode{
	int val;
	struct TreeNode *lchild,*rchild;
};

typedef struct TreeNode* TreeNode;

int Height(TreeNode root){
	if(!root)	
		return 0;
	return 1 + max(Height(root->lchild),Height(root->rchild));
}

// TreeNode balanceFactor(TreeNode root){
// 	if(!root)
// 		return NULL;
// 	if(Height(root->lchild)-Height(root->rchild)<(-1) || Height(root->lchild)-Height(root->rchild)>1){
// 		//flag = 0;
// 		return root;
// 	}
// 	return balanceFactor(root->lchild);
// 	return balanceFactor(root->rchild);
// 	return NULL;
// }

TreeNode rightRotate(TreeNode root){
	TreeNode temp = root->lchild;
	TreeNode temp2 = temp->rchild;

	temp->rchild = root;
	root->lchild = temp2;

	return temp;
}

TreeNode leftRotate(TreeNode root){
	TreeNode temp = root->rchild;
	TreeNode temp2 = temp->lchild;

	temp->lchild = root;
	root->rchild = temp2;

	return temp;
}

int balanceFactor(TreeNode root){
	return Height(root->lchild)-Height(root->rchild);
}

TreeNode getParent(TreeNode root, TreeNode node){
	TreeNode temp = root;
	while(temp->lchild!=node && temp->rchild!=node){
		if(node->val > temp->val)
			temp = temp->rchild;
		else
			temp = temp->lchild;
	}

	return temp;
}


TreeNode CreateTree(TreeNode root, int x){
	TreeNode newNode = (TreeNode)malloc(sizeof(TreeNode));
	newNode->val = x;
	newNode->lchild = newNode->rchild = NULL;
	//flag = 1;

	if(root==NULL)
		return newNode;

	TreeNode temp = root, parent = root;
	while(temp){
		parent = temp;
		if(x < temp->val)
			temp = temp->lchild;
		else
			temp = temp->rchild;
	}

	if(x < parent->val){
		parent->lchild = newNode;
		temp = parent->lchild;
	}
	else{
		parent->rchild = newNode;
		temp = parent->rchild;
	}

	//temp = newNode;

	while(parent!=root){
		parent = getParent(root,temp);
		int bf = balanceFactor(parent), flag;
		temp = parent;
		flag = 0;
	
		if(bf>1 && bf*balanceFactor(parent->lchild)>0){
			printf("Right Rotation at %d\n",parent->val);
			parent = rightRotate(parent);	
			flag = 1;
		}
		else if(bf<-1 && bf*balanceFactor(parent->rchild)>0){
			printf("Left Rotation at %d\n", parent->val]);
			parent = leftRotate(parent);
			flag = 1;
		}
		else if(bf>1 && bf*balanceFactor(parent->lchild)<0){
			printf("Left Right Rotation at %d.\n",parent->val);
			parent->lchild = leftRotate(parent->lchild);
			parent = rightRotate(parent);
			flag = 1;
		}
		else if(bf<-1 && bf*balanceFactor(parent->rchild)<0){
			printf("Right Left Rotationat %d.\n",parent->val);
			parent->rchild = rightRotate(parent->rchild);
			parent = leftRotate(parent);
			flag = 1;
		}

		if(flag){
			if(temp==root)
				root = parent;
			else{
				TreeNode anc = getParent(root,temp);
				if(parent->val < anc->val)
					anc->lchild = parent;
				else
					anc->rchild = parent;
			}
		}

		temp = parent;
	}

	return root;
}

void Inorder(TreeNode root){
	if(!root)
		return ;
	Inorder(root->lchild);
	printf("Node: %d Balance Factor: %d\n",root->val,(Height(root->lchild)-Height(root->rchild)));
	Inorder(root->rchild);
}

void main(){
	TreeNode root = NULL;
	int ch,val;
	do{
		printf("1.Insert into tree.\n2.Inorder Display.\n3.Exit.\nEnter your choice: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch){
			case 1: printf("Enter value for node: ");
					scanf("%d",&val);
					root = CreateTree(root,val);
					printf("Node added.\n");
					printf("\n");
					break;
			case 2:	Inorder(root);
					printf("\n\n");
					break;
			case 3: break;
		}
	}while(ch!=3);
}



