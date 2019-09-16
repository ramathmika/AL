# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
	int n;
	int flag;
	struct ll * head;
}NODE;

typedef struct ll
{
	struct node * n;
	struct ll * next;
}LL;

NODE * getVal(NODE *t,int n){
	t = (NODE *)malloc(sizeof(struct node));
	t->n = n;
	t->flag=0;
	t->head=NULL;
	return t;
}

LL * insLL(LL *head,NODE *t)
{
	if(head == NULL)
	{
		head = (LL *)malloc(sizeof(struct ll)); 
		head->n = t;
		head->next = NULL;
		return head;
	}
	head->next = insLL(head->next,t);
	return head;
} 

void printAdj(NODE *t)
{
	if(t == NULL)
		return;
	printf("%d:\t",t->n);
	LL *l = t->head;
	while(l != NULL)
	{
		printf("%d\t",l->n->n);
		l=l->next;
	}
	printf("\n\n");
}

void printStack(LL *stack){
	if (stack != NULL)
	{
		printStack(stack->next);
		printf("%d\t",stack->n->n);
	}
}

int zeropos(int a[],int n){
	for(int i=0;i<n;i++)
		if(a[i] == 0)	return i;
	return -1;
}

int Arrsize(int a[],int n){
	int re = 0;
	for (int i = 0; i < n; ++i)
		if(a[i] >= 0) re++;
	return re;
}

LL * RevPOPDepth(NODE *a ,LL *stack)
{
	a->flag = 1;
	LL *t;
	t = a->head;
	while(t != NULL)
	{
		if(t->n->flag==0)
			stack = RevPOPDepth(t->n,stack);
		t=t->next;
	} 
	stack=insLL(stack,a);
	return stack;
}

void Topology1(NODE **a,int n)
{
	LL *stack = NULL;
	for(int i=0;i<n;i++)
		if(a[i]->flag==0)
			stack = RevPOPDepth(a[i],stack);
	for (int i = 0; i < n; ++i)
		a[i]->flag=0;
	printStack(stack);
}

void removeSource(NODE **a,int n,int *ine,int *topo,int *s){
	if(Arrsize(ine,n)== 0)	return;
	int z = zeropos(ine,n);
	if(z == -1){
		printf("Cyclic Graph\n");
		*s = -1;
		return;
	}
	topo[++(*s)] = z+1;
	LL *t = a[z]->head;
	while (t!=NULL)
	{
		--ine[(t->n->n)-1];
		t = t->next;
	}
	ine[z] = -1;
	removeSource(a,n,ine,topo,s);
}

void Topology2(NODE **a,int n)
{
	int inedge[n],topo[n],s=-1; 
	for (int i = 0; i < n; i++)
		inedge[i]=0;
	
	LL *t = NULL;

	for(int i=0;i<n;i++){
		t = a[i]->head;
		while(t != NULL){
			inedge[t->n->n - 1]++;
			t = t->next;
		}
	}
	removeSource(a,n,inedge,topo,&s);
	for (int i = 0; i <= s; ++i)
		printf("%d\t",topo[i]);
}

int main()
{
	int n,m,k,s,e;
	printf("Enter no. of V:\n");
	scanf("%d",&n);
	printf("\n\n");
	
	NODE **Adj=(NODE **)malloc(sizeof(struct node *)*n);
	for (int i = 0; i < n; ++i)
		Adj[i]=getVal(Adj[i],i+1);
	
	printf("Enter no. of E:\n");
	scanf("%d",&m);
	
	printf("\nEnter edge:\n");
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&s,&e);
		Adj[s-1]->head = insLL(Adj[s-1]->head,Adj[e-1]);
		printf("Edge ADDED\n");
	}
	
	for(int i = 0; i < n; i++)
		printAdj(Adj[i]);

	printf("\n\nDFS technique:\n\n");
	Topology1(Adj,n);

	printf("\n\nSource removal:\n\n");
	Topology2(Adj,n);
	printf("\n");
	return 0;
}