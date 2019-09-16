#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;

NODE * getnode(int x)
{
	NODE * t=(NODE *)malloc(sizeof(NODE));
	if(t==NULL)
		exit(0);
	t->data=x;
	t->left=t->right=NULL;
	return t;
}

NODE * insertnode(NODE * root)
{
	int x;
	printf("Enter element :\t");
	scanf("%d",&x);
	NODE * t=getnode(x);
	
	if(root==NULL)	return t;
	
	int i;
	char dir[10];
	
	NODE * prev=NULL;
	NODE * cur=root;
	
	printf("DIR:\t");
	scanf("%s",dir);
	for(i=0;i!=strlen(dir) && cur!=NULL;i++)
	{
		prev=cur;
		if(dir[i]=='l')	cur=cur->left;
		else cur=cur->right;
	}
	
	if(cur!=NULL || i!=strlen(dir))
	{
		printf("Insertion Not Possible");
		return root;
	}

	if(dir[i-1]=='r')	
		prev->right=t;
	else	
		prev->left=t;
	return root;
}

int max(int a,int b){
	if(a > b)	return a;
	return b;
}

int Height(NODE *root){
	if(root ==  NULL)	return 0;
		return 1+max(Height(root->left),Height(root->right));
}

int Diameter(NODE *root)
{
	if(root == NULL)	return 0;
	int lh = Height(root->left);
	int rh = Height(root->right);

	int lD = Diameter(root->left);
	int rD = Diameter(root->right);

	return max(lh+rh+1,max(lD,rD));
}

void main()
{
	int n;
	printf("Enter no. of nodes :\t");
	scanf("%d",&n);
	printf("Enter nodes :\n");
	NODE * root=NULL;
	for(int i=0;i<n;i++)
		root=insertnode(root);
	
	printf("\n\nDiameter :  %d\n",Diameter(root));

}