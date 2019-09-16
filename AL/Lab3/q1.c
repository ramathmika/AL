#include <stdio.h>

void bubbleSort(int a[],int n,int *c){
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++,(*c)++)
			if(a[j]>=a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
	

}

int main(){
	int n,i,c=0;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	bubbleSort(a,n,&c);

	printf("Sorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nOperation Count: %d\n",c);
}