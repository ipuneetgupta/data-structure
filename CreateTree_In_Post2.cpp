// CreateTree_In_Pre
#include<iostream>
using namespace std;
class Node{
public:
	Node *left;
	Node *right;
	int data;
	Node(int data){
		this->left = NULL;
		this->right = NULL;
		this->data = data;
	}
};
int search(int *arr,int key,int low,int high){
	for(int i=low;i<=high;i++){
		if(arr[i]==key)
			return i;
	}
}
Node* constructTree(int *post,int *in,int low,int high,int &pos_idx){
     if(low>high) return NULL;
     if(pos_idx<0) return NULL;
     	Node *node = new Node(post[pos_idx]);
        pos_idx--;
        // cout<<node->data<<low<<high;
        if(low == high) return node;

        int idx_r = search(in,node->data,low,high);
        // cout<<idx_r<<endl;
        node->right = constructTree(post,in,idx_r+1,high,pos_idx);
        node->left = constructTree(post,in,low,idx_r-1,pos_idx);
        return node;
}
void printPreorder(Node *node){
	if(node == NULL) return;
	cout<<node->data<<" ";
	printPreorder(node->left);
	printPreorder(node->right);
}
int main(){
	int t;  
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int post[n],in[n];
		for(int i=0;i<n;i++)cin>>in[i];
		for(int j=0;j<n;j++)cin>>post[j];
		Node *root;
	    int pos_idx=n-1;
	    root = constructTree(post,in,0,n-1,pos_idx);
	    printPreorder(root);

}
}
