#include <stdio.h>

int opcount = 0;

void merge(int arr[], int low, int mid, int high) {
	int i, j, k, n1 = mid-low+1, n2 = high-mid;
	int left[n1], right[n2];

	for(i=0;i<n1;i++)
		left[i] = arr[low+i];
	for(i=0;i<n2;i++)
		right[i] = arr[mid+1+i];

	i = j = 0;
	k = low;

	while(i<n1 && j<n2) {
		opcount++;
		if(left[i] <= right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
		k++;
	}

	while(i<n1){
		opcount++;
		arr[k++] = left[i++];
	}
	while(j<n2){
		opcount++;
		arr[k++] = right[j++];
	}
}

void mergeSort(int arr[],int low, int high){
	if(low < high){
		int mid = (low + high)/2;

		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);

		merge(arr,low,mid,high);
	}
}

void main(){
	int n,i;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	mergeSort(arr,0,n-1);

	printf("Sorted array is: \n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	printf("\nOpcount: %d\n",opcount);
}