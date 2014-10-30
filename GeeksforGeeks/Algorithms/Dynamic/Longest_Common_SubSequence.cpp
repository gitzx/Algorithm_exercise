#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
	return (a>b)?a:b;
}
int lcs(char *X,char *Y,int m,int n){
	if(m==0||n==0){
		return 0;
	}
	if(X[m-1]==Y[n-1]){
		return lcs(X, Y, m-1, n-1)+1;
	}else{
		return max(lcs(X,Y,m-1,n),lcs(X,Y,m,n-1));
	}
}

int main(){
	char a[]="abcd";
	char b[]="acd";
	int m=strlen(a);
	int n=strlen(b);
	printf("Length of LCS is %d\n", lcs( a, b, m, n ) );
 	getchar();
  	return 0;
}