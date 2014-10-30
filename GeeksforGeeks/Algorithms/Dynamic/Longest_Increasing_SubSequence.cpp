#include<stdio.h>
#include<stdlib.h>
int lis_n_2(int a[], int n){
	int *lis;
	int i,j,max=0;
	lis=(int*)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		lis[i]=1;
	}
	for(i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(a[j]<a[i]&&lis[i]<lis[j]+1){
				lis[i]=lis[j]+1;
			}
		}
	}
	for(i=0;i<n;i++){
		if(max<lis[i]){
			max=lis[i];
		}
	}
	free(lis);
	return max;
}

int main(){
  int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(a)/sizeof(a[0]);
  printf("Length of LIS is %d\n", lis(a, n));
  getchar();
  return 0;
}