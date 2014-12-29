/*Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
using namespace std;

class Solution{
public:
    int removeElement(int A[], int n, int elem){
        int cur = 0;
        for(int i=0;i<n;++i){
            if(A[i]==elem){
                continue;
            }
            A[cur]=A[i];
            cur++;
        }
        return cur;
    }
};

int main(){
    Solution solution;
    int A[10]={1,2,3,4,5,5,6,7,8,5};
    cout<<solution.removeElement(A,10,5)<<endl; //7
}
