#include <iostream>
using namespace std;

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int A[],int start,int end){
	int x=A[end];
	int i=start-1;
	int j;
	for(j=start;j<end-1;j++){
		if(A[j]<=x){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[end]);
	return i+1;
}

void quickSort(int A[],int start,int end){
	int index;
	if(start<end){
		index=partition(A,start,end);
		quickSort(A,start,index-1);
		quickSort(A,index+1,end);
	}
}

//using sorting
int hasArrayTwoCandidates1(int A[],int n,int sum){
	int l, r;
	quickSort(A,0,n-1);
	l=0;
	r=n-1;
	while(l<r){
		if(A[l]+A[r]==sum){
			return 1;
		}else if(A[l]+A[r]<sum){
			l++;
		}else{
			r--;
		}
	}
	return 0;
}


//using hash map
int hasArrayTwoCandidates2(int A[],int n,int sum){
	int i,temp;
	bool binMap[100]={0};
	for(i=0;i<n;i++){
		temp=sum-A[i];
		if(temp>=0&&binMap[temp]==1){
			return 1;
		}
		binMap[A[i]]=1;
	}
	return 0;
}

int main(){
	int A[]={1,3,19,5,9,-1};
	int sum=12;
	int n=6;
	cout<<hasArrayTwoCandidates2(A,n,sum)<<endl; //1
	cout<<hasArrayTwoCandidates1(A,n,sum)<<endl; //1
	return 0;
}
