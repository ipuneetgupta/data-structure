// parentArrayTree
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
void createParentNode(int *parent,Node *pointerNode[],int i,Node **root){
	if(pointerNode[i]!=NULL) return;
	pointerNode[i] = new Node(i);

	if(parent[i]==-1){
		*(root) = pointerNode[i];
		return;
	}
     
    if(pointerNode[parent[i]]==NULL){
    	createParentNode(parent,pointerNode,parent[i],root);
    }
  
    Node *p = pointerNode[parent[i]];

    if(p->left==NULL){
    	p->left = pointerNode[i];
    }else{
    	p->right = pointerNode[i];
    }

    return;
}
Node* createPointerParent(int *parent,int n){
	Node *pointerNode[n];
	for(int i=0;i<n;i++) pointerNode[i] = NULL;
    
    Node *root = NULL;
    for(int i=0;i<n;i++){
    	createParentNode(parent,pointerNode,i,&root);
    }
    return root;
}
void printPreOrder(Node *root){
	if(root == NULL) return;
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
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		// for(int j=0;j<n;j++){
		// 	cout<<arr[j];
		// }
		Node *root = createPointerParent(arr, n); 
	    printPreOrder(root); 
	    cout<<endl;
	}
}
