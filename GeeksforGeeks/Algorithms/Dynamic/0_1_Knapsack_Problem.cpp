//完全背包
//多重背包
//0-1背包

#include <stdio.h>
int max(int a,int b){
	return (a>b)?a:b;
}
int knapSack(int w, int wt[], int val[], int n){
	int i,j;
	int k[n+1][w+1];
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			if(i==0||j==0)
				k[i][j] = 0;
			else if(wt[i-1] <= j){
				k[i][j] = max(val(i-1) + k[i-1][j-wt[i-1]], k[i-1][j]);
			}else{
				k[i][j] = k[i-1][j];
			}
		}
	}
	return k[n][w];
}

int main(){
	int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}