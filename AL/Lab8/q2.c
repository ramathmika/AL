#include <stdio.h>
int opcount = 0;

void heapify(int heap[], int n){
	 int i, j, isHeap;
	// for(i=0;i<(n/2);i++){
	// 	j = n-1-(2*i), isHeap=0;
	// 	while(j>=0 && !isHeap){
	// 		opcount ++;
	// 		//sibling
	// 		if(!j%2){
	// 			if(heap[j]<heap[j-1])
	// 				j -= 1;
	// 		}
	// 		//parent
	// 		if(heap[j/2] >= heap[j])
	// 			isHeap = 1;
	// 		else{
	// 			int temp = heap[j];
	// 			heap[j] = heap[j/2];
	// 			heap[j/2] = temp;
	// 			j /= 2;
	// 		}	
	// 	}
	// }

	int k, v;
	for(i=(n/2);i>=1;i--){
		k = i; 
		v = heap[k], isHeap = 0;
		while(!isHeap && 2*k<n){
			opcount++;
			j = 2*k;
			if(j<n)
				if(heap[j]<heap[j+1])
					j += 1;
			if(v >= heap[j])
				isHeap = 1;
			else{
				heap[k] = heap[j];
				k = j;
			}
		}
		heap[k] = v;
	}
}

void main() {
	int i, n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int heap[n],sortedArray[n];
	printf("Enter the elements: ");

	for(i=1;i<=n;i++)
		scanf("%d",&heap[i]);

	int k = n;
	for(i=1;i<=n;i++){
		heapify(heap,k);
		sortedArray[i] = heap[1];

		int t = heap[1];
		heap[1] = heap[k];
		heap[k] = t;

		k--;
		
	}
	
	printf("\nSorted Array: ");
	for (i = 1; i <= n; ++i)
		printf("%d ",sortedArray[i]);

	printf("\nopcount: %d\n",opcount);
}