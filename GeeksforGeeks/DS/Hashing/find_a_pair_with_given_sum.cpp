/*Write a C program that, given an array A[] of n numbers and another number x, 
determines whether or not there exist two elements in S whose sum is exactly x.
*/

#include <iostream>
using namespace std;
#define MAX 100000

//METHOD 1 (Use Sorting)

//using hash map
class Solution{
public:
    void printPairs(int arr[],int arr_size,int sum){
        int i,temp;
        bool binMap[MAX]={0};
        for(int i=0;i<arr_size;i++){
            temp=sum-arr[i];
            if(temp>=0&&binMap[temp]==1){
                cout<<sum<<":"<<arr[i]<<"+"<<temp<<endl;
            }
            binMap[i]=1;
        }
    }
};

int main(){
    Solution solution;
    int A[]={1,2,3,5,6};
    int n=8;
    solution.printPairs(A,5,n);
    return 0;
}
