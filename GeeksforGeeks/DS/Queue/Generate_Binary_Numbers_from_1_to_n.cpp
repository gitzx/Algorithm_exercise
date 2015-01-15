#include <iostream>
#include <queue>
using namespace std;

void generatePrintBinary(int n){
    queue<string> q;
    q.push("1");
    while(n--){
        string s1=q.front();
        q.pop();
        cout<<s1<<endl;
        string s2=s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}

int main(){
    int n=9;
    generatePrintBinary(n);
    return 0;
}

/*
1
10
11
100
101
110
111
1000
1001
*/
