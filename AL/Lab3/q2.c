#include <stdio.h>
#include <string.h>

void stringMatch(char str[],char substr[],int n,int m){
	int i,j,flag,c=0;
	for(i=0;i<n;i++){
		flag = 1;
		for(j=0;j<m;j++){
			c++;
			if(str[i+j] != substr[j]){
				flag = 0;
			}
		}
		if(flag)
			break;
	}
	if(flag)
		printf("Strings match");
	else
		printf("Strings do not match");
	printf("\nCount: %d\n",c);
}

int main(){
	int n,m;
	char str[100],substr[100];
	printf("Enter the string and substring:\n");
	gets(str);
	gets(substr);
	n = strlen(str);
	m = strlen(substr);

	stringMatch(str,substr,n,m);
}