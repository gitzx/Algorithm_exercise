/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //Using Moore’s Voting Algorithm
    int majorityElement(vector<int> &num){
        int majority_index=0;
        int count =1;
        vector<int>::size_type it;
        for(it=0;it!=num.size();++it){
            if(num[majority_index]==num[it]){
                count++;
            }else{
                count--;
            }
            if(count==0){
                majority_index = it;
                count = 1;
            }
        }
        return num[majority_index];
    }
};

int main(){
    Solution solution;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    cout<<solution.majorityElement(v)<<endl; //1
    return 0;
}
