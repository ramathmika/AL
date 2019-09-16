#include <stdio.h>
//#include <climits.h>

int count=0,arr[10][10],mincost = 999999, minperm[10];

void print(int perm[], int n) {
	int cost=0,i;
	for(i=0;i<n;i++) {
		printf("%d ",perm[i]);
		cost += arr[perm[i]][i];
	}
	printf("Cost: %d\n",cost);
	if(cost<mincost) {
		mincost = cost;
		for(i=0;i<n;i++)
			minperm[i] = perm[i];
	}
}

void swap(int *a, int *b){ 
	int temp = *a;
	*a = *b;
    *b = temp;
}

void permute(int array[], int i, int len){ 
	if(len==i){
		count++;
		print(array,len);
		return;
	}
	for(int j=1;j<len;j++){
		swap(array+i,array+j);
		permute(array,i+1,len);
		swap(array+i,array+j);
	}
}

void main() {
	int n,i,perm[10],j;
	printf("Enter the number of jobs or number of people: \n");
	scanf("%d", &n);
	printf("Enter the time taken by person \n");
	for(i=0;i<n;i++){
		perm[i] = i;
		for(j=0;j<n;j++){
			printf("%d for job %d\n",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("%c ",'A'+i);
	permute(perm,0,n);
	for(i=0;i<n;i++)
		printf("%c: %d ",'A'+i, minperm[i]+1);
	printf("\n");
	printf("Count: %d\n",count);
	
}