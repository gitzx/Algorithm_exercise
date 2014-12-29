/*Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
*/

#include <iostream>
using namespace std;

class Solution{
public:
    void merge(int A[], int m,int B[],int n){
        int k=m+n-1;
        int i=m-1;
        int j=n-1;
        for(;i>=0&&j>=0;k--){
            if(A[i]>=B[j]){
                A[k]=A[i];
                i--;
            }else{
                A[k]=B[j];
                j--;
            }
        }
        while(j>=0){
            A[k]=B[j];
            k--;
            j--;
        }
    }
};

int main(){
    Solution solution;
    int A[6]={1,2,4,5,7,9};
    int B[5]={4,6,8,9,11};
    solution.merge(A, 6, B, 5);
    for(int i=0;i<11;i++){
       cout<<A[i]<<endl; 
    }
    return 0;
}
