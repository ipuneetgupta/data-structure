#include<iostream>
#include<queue>
using namespace std;
class Node {
public:
	Node *left;
	Node *right;
	int data;
	Node(int d) {
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

void display(Node *node) {
	if (node->left != NULL) cout << node->left->data << " => ";
	else cout << "End => ";
	cout << node->data;
	if (node->right != NULL) cout << " <= " << node->right->data;
	else cout << " <= End";
	cout<<endl;
	if (node->left != NULL) display(node->left);
	if (node->right != NULL) display(node->right);
	return;
}
bool isBalanced(Node *root){
  if(root->left==NULL&&root->right==NULL) return true;
  if(root->left!=NULL&&root->data>root->left->data) return isBalanced(root->left);
  if(root->right!=NULL&&root->data<root->right->data) return isBalanced(root->right);
  return false;
}
int main() {
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
 	cin>>arr[i];
 } 
 Node *root  = buildBst(arr,0,n-1);
 display(root);
 cout<<isBalanced(root);
}