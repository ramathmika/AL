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

NODE * getVal(NODE *t,int n)
{
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

NODE * deleteq(LL *head)
{
	if(head == NULL)	return NULL;
	NODE *t = head->n;
	head = head->n;
	return t;
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

NODE *resetval(NODE *t)
{
	t->flag=0;
	return t;
}

void Depth(NODE *a)
{
	,a->n);

	a->flag = 1;
	LL *t;
	t = a->head;
	while(t != NULL)
	{
		if(t->n->flag==0)
			Depth(t->n);
		t=t->next;
	}
}

void DFS(NODE **a,int n)
{
	for(int i=0;i<n;i++){
		if(a[i]->flag==0)
			Depth(a[i]);
	}
}


void Breadth(NODE *a)
{
	printf("%d Visited.\n",a->n);
	a->flag = 1;
	LL *t;
	NODE *q[100];
	int f,r;
	f=r=-1;
	t = a->head;
	while(t != NULL)
	{
		if(t->n->flag==0)
			printf("\n");
		t=t->next;
	}
}

void BFS(NODE **a,int n)
{
	for(int i=0;i<n;i++){
		if(a[i]->flag==0)
			Breadth(a[i]);
	}
}


int main()
{
	int n,k;

	printf("Enter no. of V:\n");
	scanf("%d",&n);
	printf("\n\n");

	NODE **Adj=(NODE **)malloc(sizeof(struct node *)*n);

	for (int i = 0; i < n; ++i)
		Adj[i]=getVal(Adj[i],i+1);
	
	do
	{
		
		printf("\n\n1.Enter an edge (START --> END):\n2.Adjacency LIST\n3.DFS\n4.BFS\n5.EXIT\n\nEnter your choice:\t");
		scanf("%d",&k);

		int s,e;
		switch(k)
		{
			case 1:	scanf("%d%d",&s,&e);
					Adj[s-1]->head = insLL(Adj[s-1]->head,Adj[e-1]);
					printf("Edge ADDED\n");
					break;

			case 2:	for(int i = 0; i < n; i++)
						printAdj(Adj[i]);
					break;

			case 3: DFS(Adj,n);
					for (int i = 0; i < n; ++i)
						Adj[i]=resetval(Adj[i]);
					break;

			case 4: BFS(Adj,n);
					for (int i = 0; i < n; ++i)
						Adj[i]=resetval(Adj[i]);
					break;
		}
	}while(k!=5);
	return 0;
}