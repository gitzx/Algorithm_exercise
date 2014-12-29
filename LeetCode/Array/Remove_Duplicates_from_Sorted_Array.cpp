/*Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution1{
public:
    int removeDuplicates(int A[], int n){
        if(n<=1){
            return n;
        }
        int j=0;
        for(int i=1;i<n;++i){
            if(A[j]!=A[i]){
                A[++j]=A[i];
            }
        }
        return j+1;
    }
};

class Solution2{
public:
    int removeDuplicates(int A[], int n){
        return distance(A, unique(A, A + n));
    }
};

int main(){
    Solution solution1;
    int A[5]={1,1,2,2,2};
    cout<<solution1.removeDuplicates(A,5)<<endl;
    cout<<solution2.removeDuplicates(A,5)<<endl;
    return 0;
}
