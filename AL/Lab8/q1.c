#include <stdio.h>
int opcount = 0;

void heapify(int heap[], int i, int n){
	int j = i, isHeap = 0;
	while(!isHeap && j>0){
		opcount ++;

		if(heap[j/2] >= heap[j])
			isHeap = 1;
		else{
			int temp = heap[j];
			heap[j] = heap[j/2];
			heap[j/2] = temp;
			j /= 2;
		}	
	}
}

void main() {
	int i, n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int heap[n];
	printf("Enter the elements: ");

	for(i=0;i<n;i++){
		scanf("%d",&heap[i]);
		heapify(heap,i,n);
		//opcount = 0;
	}

	printf("Heap:\n");
	for (i = 0; i < n; ++i)
		printf("%d ",heap[i]);
	printf("\nopcount: %d\n",opcount);
}