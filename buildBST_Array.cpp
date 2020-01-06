// buildBST_Array
#include<iostream>
using namespace std;
class Node{
public:
	Node *left;
	Node *right;
	int data;
	Node(int d){
		this->left = NULL;
		this->right = NULL;
		this->data = d;
	}
};
Node * buildBst(int *arr,int low ,int high){
	if(low>high) return NULL;
	int mid = low + (high-low)/2;
	Node *node = new Node(arr[mid]);
	node->left = buildBst(arr,low,mid-1);
	node->right = buildBst(arr,mid+1,high);
	return node;
}
void printPreOrder(Node *root){
	if(root == NULL) return ;
	cout<<root->data<<" ";

	printPreOrder(root->left);
	printPreOrder(root->right);
	return;
}
int main(){
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
		Node *root = buildBst(arr,0,n-1);
	printPreOrder(root);
}
}