// FindSum_BT
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
class Node{
public:
	Node *left;
	Node *right;
	long data;
     Node(long d){
    	this->left = NULL;
    	this->right = NULL;
    	this->data = d;
    }
};
class B_Tree{
public:
	Node *root;
	B_Tree(){
		this->root = NULL;
	}
	Node* ConstructBB_Tree(long *arr,long s,long e){
		if(s>e) return NULL;
        long mid = s + (e-s)/2;
        Node *node = new Node(arr[mid]);
        node->left = ConstructBB_Tree(arr,s,mid-1);
        node->right = ConstructBB_Tree(arr,mid+1,e);
        return node;
	}
	int FindSum_temp(Node *node){
		if(node==NULL) return 0;
      long l_sum = FindSum_temp(node->left);
      long r_sum = FindSum_temp(node->right);
      return node->data+l_sum+r_sum;
	}
	void FindSum(){
     cout<<(this->FindSum_temp(this->root));
	}
};

int main(){
	long n;
	cin>>n;
	long arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
    B_Tree *tree = new B_Tree();
    tree->root = tree->ConstructBB_Tree(arr,0,n-1);
    tree->FindSum();
}