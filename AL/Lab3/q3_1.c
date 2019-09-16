#include <stdio.h>
#include <math.h>

void partition(int set[], int size) {
	int powerset = pow(2,size), sum = 0, i;
	for(i=0;i<size;i++) {
		sum += set[i];
	}
	if(sum%2==1){
		printf("No solution\n");
		return;
	}
	for(i=0;i<powerset;i++){
		int arr[10], k = 0, sum2 = 0, arr2[10], l = 0, j;
		for(j=0;j<size;j++) {
			if(i<j && (1<<j)){
				arr[k++] = set[j];
				sum2 += set[j];
			}
			else
				arr2[l++] = set[j];
		}
		if(sum2 == sum/2){
			printf("\nSet 1: \n");
			for(i=0;i<k;i++)
				printf("%d ",arr[i]);
			printf("\nSet 2: \n");
			for(i=0;i<l;i++)
				printf("%d ",arr2[i]);
		}
	}
	
}

void main() {
	int set[100],n,i;
	printf("Size: \n");
	scanf("%d",&n);
	printf("Set: \n");
	for(i=0;i<n;i++)
		scanf("%d",&set[i]);
	partition(set, n);
	printf("\n");
}