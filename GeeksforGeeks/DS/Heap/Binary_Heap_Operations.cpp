/*Operations on Min Heap:
(1)getMini();
(2)extractMin();
(3)decreaseKey();
(4)insert();
(5)delete();
*/

#include <iostream>
#include <climits>
using namespace std;
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

class MinHeap{
private:
    int *harr;
    int capacity;
    int heap_size;
public:
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return i*2+1;
    }
    int right(int i){
        return i*2+2;
    }
    int getMin(){
        return harr[0];
    }
    MinHeap(int cap){
        heap_size=0;
        capacity=cap;
        harr=new int[cap];
    }
    void insertKey(int k){
        if(heap_size==capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        heap_size++;
        int i=heap_size-1;
        harr[i]=k;
        while(i!=0&&harr[parent(i)]>harr[i]){
            swap(&harr[i],&harr[parent(i)]);
            i=parent(i);
        }
    }

    // Decreases value of key at index 'i' to new_val.  
    // It is assumed that new_val is smaller than harr[i].
    void decreaseKey(int i,int new_val){
        harr[i]=new_val;
        while(i!=0&&harr[parent(i)]>harr[i]){
            swap(&harr[i],&harr[parent(i)]);
            i=parent(i);
        }
    }

    // A recursive method to heapify a subtree with root at given index
    // This method assumes that the subtrees are already heapified
    void MinHeapify(int i){
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<heap_size&&harr[l]<harr[i]){
            smallest=l;
        }
        if(r<heap_size&&harr[r]<harr[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            swap(&harr[i],&harr[smallest]);
            MinHeapify(smallest);
        }
    }

    //Method to remove minimum element(or root)
    int extractMin(){
        if(heap_size<=0){
            return INT_MAX;
        }
        if(heap_size==1){
            heap_size--;
            return harr[0];
        }
        int root=harr[0];
        harr[0]=harr[heap_size-1];
        heap_size--;
        MinHeapify(0);
        return root;
    }

    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }

};

int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout<<h.extractMin()<<" ";
    cout<<h.getMin()<<" ";
    h.decreaseKey(2,1);
    cout<<h.getMin()<<endl; //2 4 1
    return 0;
}

