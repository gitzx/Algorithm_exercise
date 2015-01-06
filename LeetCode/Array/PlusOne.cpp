/*Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int> &digits){
        int cary = 1, sum = 0;
        vector<int> result(digits.size(), 0);
        for(int i=digits.size()-1;i>=0;--i){
            sum = cary + digits[i];
            cary = sum/10;
            result[i] = sum%10;
        }
        if(cary>0){
            result.insert(result.begin(), cary);
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(2);
    vt.push_back(4);
    vt.push_back(6);
    vt.push_back(8);
    vt.push_back(9);
    vt.push_back(9);
    vector<int> result;
    result = solution.plusOne(vt);
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<endl;
    }
    return 0;
}
