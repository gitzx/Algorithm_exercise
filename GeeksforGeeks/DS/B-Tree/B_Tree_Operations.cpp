/*
 B-Tree Operations:
 (1)traverse
 (2)search
 (3)insert
 (4)delete
 */


#include <iostream>
using namespace std;

class BTreeNode{
	int *keys; //An array of keys
	int t; //Minimum degree (defines the range for number of keys)
	BTreeNode **C; //An array of child pointers
	int n; //Current number of keys
	bool leaf; //Is true when node is leaf. Otherwise false
public:
	BTreeNode(int _t, bool _leaf);
	void traverse();
	BTreeNode *search(int k);
friend clss BTree;
};

class BTree{
	BTreeNode *root;
	int t;
public:
	BTree(int _t){
		root=NULL;
		t=_t;
	}
	void traverse(){
		if(root!=NULL){
			root->traverse();
		}
	}
	BTreeNode *search(int k){
		return (root=NULL)?NULL:root->search(k);
	}
};

BTreeNode::BTreeNode(int _t,bool _leaf){
	t=_t;
	leaf=_leaf;
	keys=new int[2*t-1];
	C=new BTreeNode *[2*t];
	n=0;
}

//traverse
void BTreeNode::traverse(){
	int i;
	for(i=0;i<n;i++){
		if(leaf==false){
			C[i]->traverse();
		}
		cout<<keys[i]<<" ";
	}
	if(leaf==false){
		C[i]->traverse();
	}
}

//search
BTreeNode *BTreeNode::search(int k){
	int i=0;
	while(i<n&&k>keys[i]){
		i++;
	}
	if(keys[i]==k){
		return this;
	}
	if(leaf==true){
		return NULL;
	}
	return C[i]->search(k);
}

//insert

}
