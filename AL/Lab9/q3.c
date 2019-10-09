#include <stdio.h>
#include <stdlib.h>
int opcount = 0;

void Search(int table[], int m, int key){
	int r = key%m, init, j;
	init = j = r;
		do{
			opcount++;
			if(table[j] == key){
				printf("Successful search\n");
				return ;
			}
			else
				j = (j+1)%m;
		}while(init!=j);
	printf("Unsuccessful search.\n");
}


void main(){
	int m,n,i,key,r,j,init;
	printf("Enter no of slots in hash table, and number of keys(m, n): \n");
	scanf("%d %d",&m, &n);
	int table[m];
	for(i=0;i<m;i++)
		table[i] = 0;

	printf("Enter the keys: \n");
	for(i=0;i<n;i++){
		scanf("%d",&key);
		r = key%m;
		init = j = r;
		do{
			if(!table[j]){
				table[j] = key;
				break;
			}
			else
				j = (j+1)%m;
		}while(init!=j);
	}

	// printf("Hash table: \n");
	// for(i=0;i<m;i++){
	// 	printf("%d ",table[i]);
	// }
	// printf("\n");

	printf("Enter value to be searched: ");
	scanf("%d",&key);
	Search(table, m, key);
	printf("Key comparisions: %d\n",opcount);
}