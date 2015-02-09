#include <iostream>
using namespace std;

//Using Moore’s Voting Algorithm
int findCandidate(int a[],int size){
	int maj_index=0,count=1;
	int i;
	for(i=0;i<size;i++){
		if(a[maj_index]==a[i]){
			count++;
		}else{
			count--;
		}
		if(count==0){
			maj_index=i;
			count=1;
		}
	}
	return a[maj_index];
}

int isMajority(int a[],int size,int cand){
	int i,count=0;
	for(i=0;i<size;i++){
		if(a[i]==cand){
			count++;
		}
	}
		if(count>size/2){
			return 1;
		}else{
			return 0;
		}
}

int main(){
	int a[]={1,1,3,3,4,4,4,4,5,4,4};
	int n=sizeof(a)/sizeof(int);
	int cand=findCandidate(a,n);
	cout<<cand<<" is majority? "<<isMajority(a,n,cand)<<endl; //4 is majority? 1
	return 0;
}
