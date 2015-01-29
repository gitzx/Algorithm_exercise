#include <iostream>
#include <stdlib.h>
using namespace std;

void printSorted(int arr[],int start,int end){
    if(start>end){
        return;
    }
    printSorted(arr,start*2+1,end);
    cout<<arr[start]<<" ";
    printSorted(arr,start*2+2,end);
}

int main(){
    int arr[]={4,2,5,1,3};
    int size=sizeof(arr)/sizeof(int);
    printSorted(arr,0,size-1);
    cout<<endl; //1 2 3 4 5
    return 0;
}
