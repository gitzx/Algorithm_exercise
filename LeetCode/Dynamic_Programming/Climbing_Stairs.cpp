#include <iostream>
#include <vector>
using namespace std;

//using recursive
class Solution1{
public:
    int climbStairs(int n){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

//using DP
class Solution2{
public:
    int climbStairs(int n){
        vector<int> res(n+1);
        res[0]=1;
        res[1]=1;
        for(int i=2;i<=n;i++){
            res[i]=res[i-1]+res[i-2];
        }
        return res[n];
    }
};

//using DP
class Solution3{
public:
    int climbStairs(int n){
        int fn_2=1,fn_1=2;
        if(n==1){
             return fn_2;
        }
        if(n==2){
            return fn_1;
        }
        int fn;
        for(int i=3;i<=n;i++){
            fn=fn_2+fn_1;
            fn_2=fn_1;
            fn_1=fn;
        }
        return fn;
    }
};

int main(){
    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;
    cout<<solution1.climbStairs(5)<<endl; //8
    cout<<solution2.climbStairs(5)<<endl; //8
    cout<<solution3.climbStairs(5)<<endl; //8
    return 0;
}
