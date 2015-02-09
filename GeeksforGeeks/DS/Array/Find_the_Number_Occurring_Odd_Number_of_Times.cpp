#include <iostream>
using namespace std;

int getOddOccurrence(int a[],int size){
	int i;
	int res=0;
	for(i=0;i<size;i++){
		res=res^a[i];
	}
	return res;
}

int main(){
	int a[]={1,2,3,2,3,1,3};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<getOddOccurrence(a,n)<<endl; //3
	return 0;
}
