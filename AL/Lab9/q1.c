#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int table[256];

void shiftTable(char pattern[]){
	int m = strlen(pattern),i;
	for(i=0;i<256;i++)
		table[i] = 0;
	for(i=0;i<m-1;i++)
		table[(int)pattern[i]] = m - 1 - i;
}

int Horspool(char text[], char pattern[]){
	int i,j,n,m;

	n = strlen(text);
	m = strlen(pattern);
	shiftTable(pattern);

	i = m-1;
	while(i<n){
		j = 0;
		while(j<m && pattern[m-1-j] == text[i-j])
			j++;
		if(j == m)
			return i-m+1;
		else
			i += table[text[i]];
	}
	return -1;
}

void main(){
	char text[256],pattern[256];
	printf("Enter the text: ");
	gets(text);
	printf("Enter the pattern: ");
	gets(pattern);
	int ind = Horspool(text,pattern);
	if(ind != -1)
		printf("Pattern found starting at position %d\n", ind);
	else
		printf("Pattern not found\n");
}