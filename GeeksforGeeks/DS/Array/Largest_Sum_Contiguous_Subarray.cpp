#include <iostream>
using namespace std;

//using Kadane's Algorithm
int maxSubArraySum1(int a[],int size){
	int max_so_far=0;
	int max_ending_here=0;
	int i;
	for(i=0;i<size;i++){
		max_ending_here=max_ending_here+a[i];
		if(max_ending_here<0){
			max_ending_here=0;
		}
		if(max_so_far<max_ending_here){
			max_so_far=max_ending_here;
		}
	}
	return max_so_far;
}

//using DP
int max(int a,int b){
	return (a>b)?a:b;
}

int maxSubArraySum2(int a[],int size){
	int max_so_far=a[0],i;
	int curr_max=a[0];
	for(i=1;i<size;i++){
		curr_max=max(a[i],curr_max+a[i]);
		max_so_far=max(max_so_far,curr_max);
	}
	return max_so_far;
}

int main(){
	int a[]={-1,-2,3,-1,-1,1,4,-2};
	int n=sizeof(a)/sizeof(a[0]);
	int max_sum1=maxSubArraySum1(a,n);
	int max_sum2=maxSubArraySum2(a,n);
	cout<<max_sum1<<endl; //6
	cout<<max_sum2<<endl; //6
	return 0;
}


