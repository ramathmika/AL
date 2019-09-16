#include<stdio.h>

int min(int a,int b){
	if(a<b)
		return a;
	return b;
}

int main(){
	int n,m,i,count1=0,gcd;
	printf("Enter the two numbers: ");
	scanf("%d %d",&n,&m);
	if(!n || !m){
		count1++;
		gcd = (n>0?n:m);
	}
	else{
		for(i=min(n,m);i>0;i--){
			count1++;
			if(n%i==0 && m%i==0){
				gcd = i;
				break;
			}
		}
	}
	printf("GCD is: %d\nOperation count: %d\n",gcd,count1);
}