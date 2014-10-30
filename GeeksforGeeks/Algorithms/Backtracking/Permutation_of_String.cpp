#include<stdio.h>
void swap(int *pa, int *pb){
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
void permute(char* a,int low,int high){
	if(low==high){
		printf("%s", a);
	}else{
		for(int j=low;j<=high;j++){
			swap(a+low, a+j);
			permute(a, low+1, high);
			swap(a+low, a+j);
		}
	}
}
int main(){
	char a[]="abc";
	permute(a,0,2);
	getchar();
	return 0;
}