#include <stdio.h>

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int Knapsack(int table[][100], int i, int j, int val[], int weight[]){
	if(j==0 || i==0)
		return 0;
	if(j>0 && i>0){
		if(j >= weight[i])
			table[i][j] = max(Knapsack(table, i-1,j,val,weight), (val[i]+Knapsack(table, i-1,j-weight[i],val,weight)));	
		else
			table[i][j] = Knapsack(table,i-1,j,val,weight);
	}
	
	return table[i][j];
}

void main(){
	int n, i,capacity,j;
	printf("Enter number of items: ");
	scanf("%d",&n);
	int weight[n], val[n];
	printf("Enter weight and value for each item.\n");
	for(i=1;i<=n;i++)
		scanf("%d %d",&weight[i], &val[i]);
	printf("Enter capacity: ");
	scanf("%d",&capacity);

	// printf("\nW\tVal\n");
	// for(i=1;i<=n;i++)
	// 	printf("%d\t%d\n",weight[i],val[i]);

	int table[n+1][capacity+1];
	for(i=0;i<=n;i++)
		table[i][0] = 0;
	for(i=0;i<=capacity;i++)
		table[0][i] = 0;


	int temp = Knapsack(table,n,capacity,val, weight);
	printf("Maximal value: %d\n",temp);
}