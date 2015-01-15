/*Given a number n, write a function that generates and prints all binary numbers with decimal values from 1 to n.

Examples:

Input: n = 2
Output: 1, 10

Input: n = 5
Output: 1, 10, 11, 100, 101
*/

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
