/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int> > generate(int numRows){
        vector<vector<int> > vt;
        if(numRows==0){
            return vt;
        }
        for(int i=1;i<=numRows;++i){
            vector<int> v(i,0);
            v[i-1]=v[0]=1;
            for(int j=1;j<i-1;++j){
                v[j]=vt[i-2][j-1]+vt[i-2][j];
            }
            vt.push_back(v);
        }
        return vt;
    }
};

int main(){
    Solution solution;
    vector<vector<int> > vt = solution.generate(5);
    for(int i=0;i<vt.size();++i){
        for(int j=0;j<vt[i].size();++j){
            cout<<vt[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
