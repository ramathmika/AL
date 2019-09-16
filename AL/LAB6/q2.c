#include <stdio.h>

int opcount = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot=low, i=low, j=high;
	while(i<=j){
		opcount += 2;
		while(arr[i] <= arr[pivot] && i<high)
			i++;
		while(arr[j] > arr[pivot])
			j--;
		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	//swap(&arr[i],&arr[j]);
	swap(&arr[j],&arr[pivot]);
	return j;
}

void quickSort(int array[], int low, int high){
	if(low<high){
		int p = partition(array,low,high);

		quickSort(array,low,p-1);
		quickSort(array,p+1,high);
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

	quickSort(arr,0,n-1);

	printf("Sorted array is: \n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	printf("\nOpcount: %d\n",opcount);
}