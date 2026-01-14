#include<stdio.h>
#include<string.h>
void calcPi(char []);
void findP(char P[],char T[]);
int pi[10];

int main()
{
	int i;
	char text[]="ABC ABCDAB ABCDABCDABDE";
	char P[20]="ABCDABD";
	calcPi(P);				//calculate Pi values
	printf("Pi values\n");
	for(i=1;i<strlen(P);i++)
		printf("%d ",pi[i]);
	printf("\nMatched @\n");
	findP(P,text);			// match the pattern
	return 0;
}

// function to calculate Pi vector 
void calcPi(char P[])
{
	pi[0] = -1;
	int k = -1,i;
	for(i = 1; i <strlen(P); i++) {	
		while(k >= 0 && P[k+1] != P[i])
			k = pi[k];
		pi[i] = ++k;
	} 
}

// function for Pattern matching 
void findP(char P[],char T[])
{
	int n=strlen(T)-1;
	int m=strlen(P)-1;
	int k = 0,i;
	for(i = 1; i <= n; i++) {
		
		while(k >= 0 && P[k+1] != T[i])
			k = pi[k];
		k++;
		if(k == m) 
		{
			printf("%d ",i-m+1);
			k = pi[k];
		}
	}
}
