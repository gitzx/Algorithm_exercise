#include <iostream>
using namespace std;

//using Iterative
void reverseArray1(int arr[],int start,int end){
	int temp;
	while(start<end){
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;
		start++;
		end--;
	}
}

//using recursive
void reverseArray2(int arr[],int start,int end){
	int temp;
	if(start>=end){
		return;
	}
	temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	reverseArray2(arr,start+1,end-1);
}

void printArray(int arr[],int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arr[]={1,2,3,4,5};
	reverseArray1(arr,0,4); //5 4 3 2 1
	printArray(arr,5);
	reverseArray2(arr,0,4); //1 2 3 4 5
	printArray(arr,5);
	return 0;
}
