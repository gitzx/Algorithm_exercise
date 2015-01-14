#include <iostream>
#include <stdlib.h>
using namespace std;

struct MaxHeap{
    int size;
    int *array;
};

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

class Solution{
public:
    void maxHeapify(struct MaxHeap *maxHeap,int idx){
        int largest=idx;
        int left=2*idx+1;
        int right=2*idx+2;
        if(left<maxHeap->size&&maxHeap->array[left]>maxHeap->array[largest]){
            largest=left;
        }
        if(right<maxHeap->size&&maxHeap->array[right]>maxHeap->array[largest]){
            largest=right;
        }
        if(largest!=idx){
            swap(&maxHeap->array[largest],&maxHeap->array[idx]);
            maxHeapify(maxHeap,largest);
        }
    }

    struct MaxHeap* createAndBuildHeap(int *array,int size){
        struct MaxHeap* maxHeap=(MaxHeap*)malloc(sizeof(MaxHeap));
        maxHeap->size=size;
        maxHeap->array=array;
        for(int i=(maxHeap->size-2)/2;i>=0;--i){
            maxHeapify(maxHeap,i);
        }
        return maxHeap;
    }

    void heapSort(int *array,int size){
        MaxHeap* maxHeap=createAndBuildHeap(array,size);
        while(maxHeap->size>1){
            swap(&maxHeap->array[0],&maxHeap->array[maxHeap->size-1]);
            --maxHeap->size;
            maxHeapify(maxHeap,0);
        }
    }
};

int main(){
    Solution solution;
    int arr[]={12,11,13,5,6,7};
    solution.heapSort(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; //5 6 7 11 12 13
    return 0;
}
