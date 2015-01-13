/*Given a binary tree, print it vertically. The following example illustrates vertical order traversal.

           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9         
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    int key;
    Node *left, *right;
};

struct Node *newNode(int data){
    struct Node *node=new Node;
    node->key=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

//using hash map
class Solution{
public:
    void printVerticalOrder(Node *root){
        map<int, vector<int> > m;
        int hd=0;
        getVerticalOrder(root,hd,m);
        map<int,vector<int> >::iterator it;
        for(it=m.begin();it!=m.end();it++){
            for(int i=0;i<it->second.size();i++){
                cout<<it->second[i]<<" ";
            }
            cout<<endl;
        }
    }
    void getVerticalOrder(Node *root,int hd,map<int,vector<int> > &m){
        if(root==NULL){
            return;
        }
        m[hd].push_back(root->key);
        getVerticalOrder(root->left,hd-1,m);
        getVerticalOrder(root->right,hd+1,m);
    }
};

int main(){
    Solution solution;
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->right->left=newNode(6);
    root->right->right=newNode(7);
    root->right->left->right=newNode(8);
    root->right->right->right=newNode(9);
    //4
    //2
    //1 5 6
    //3 8
    //7
    //9
    solution.printVerticalOrder(root);
    return 0;
}
