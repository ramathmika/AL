#include<stdio.h>
#include<math.h>


int isPrime(int n){
	int i;
	for(i=2;i<sqrt(n);i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}


int main(){
	int n,m,count=0,gcd=1,i,j;
	printf("Enter the two numbers: ");
	scanf("%d %d",&n,&m);
	if(!n || !m){
		count++;
		gcd = (n>0?n:m);
	}
	else{
		
		i=2;
		while(n>1 && m>1 && i<=m && i<=n){
			count++;
			if(isPrime(i) && n%i==0 && m%i==0){
				gcd*=i;
				m/=i;
				n/=i;
			}
			else
				i++;
		}
	}
	printf("GCD: %d\nOperation Count: %d\n",gcd,count);
}