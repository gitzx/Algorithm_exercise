/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

注：杨辉三角有一个特点，就是第m行的第k个数刚好是C(m,k)，
那么只要该问题只要求出C(k,0),C(k,1)...C(k,k)，即可。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> getRow(int rowIndex){
       vector<int> vt;
       long long  ans = 1;
       vt.push_back((int)ans);
       long long m = rowIndex;
       for(int i=1;i<=rowIndex;++i){
           ans = ans*(m-i+1)/i;
           vt.push_back((int)ans);
       }
       return vt;
    }
};

int main(){
    Solution solution;
    vector<int> vt = solution.getRow(3);
    for(int i=0;i<vt.size();++i){
        cout<<vt[i]<<" ";
    }
    cout<<endl;
    return 0;
}
