/*Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//hash
class Solution1{
public:
    vector<int> twoSum(vector<int> &numbers,int target){
        map<int,int> mapping;
        vector<int> result;
        for(int i=0;i<numbers.size();i++){
            mapping[numbers[i]]=i;
        }
        for(int i=0;i<numbers.size();i++){
            int searched = target - numbers[i];
            if(mapping.find(searched)!=mapping.end()){
                result.push_back(i+1);
                result.push_back(mapping[searched]+1);
                break;
            }
        }
        return result;
    }
};

//two points
class Solution2{
public:
    struct Node{
        int val;
        int index;
        Node(int pVal,int pIndex):val(pVal),index(pIndex){}
    };
    static bool compare(const Node &left,const Node &right){
        return left.val<right.val;
    }
    vector<int> twoSum(vector<int> &numbers, int target){
        vector<Node> elements;
        for(int i=0;i<numbers.size();i++){
            elements.push_back(Node(numbers[i],i));
        }
        sort(elements.begin(),elements.end(),compare);
        int start=0,end=numbers.size()-1;
        vector<int> result;
        while(start<end){
            int sum=elements[start].val+elements[end].val;
            if(sum==target){
                result.push_back(elements[start].index+1);
                if(elements[start].index<elements[end].index){
                    result.push_back(elements[end].index+1);
                }else{
                    result.insert(result.begin(),elements[end].index+1);
                }
                break;
            }else if(sum>target){
                end--;
            }else{
                start++;
            }
        }
        return result;
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);
    vector<int> vt1=solution1.twoSum(numbers, 9);
    vector<int> vt2=solution2.twoSum(numbers, 9);
    for(int i=0;i<vt1.size();i++){
        cout<<vt1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<vt2.size();i++){
        cout<<vt2[i]<<" ";
    }
    cout<<endl;
    return 0;
}
