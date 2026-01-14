#include<stdio.h>
int main(){
	int n=5,a[n],i;
	for(i=0;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n;i++){
		printf("%d\t",a[i]);
	}
	printf("\n\n");
	for(i=0;i<=n;++i){
		printf("%d\t",a[i]);
	}
}
