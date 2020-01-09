
#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
	Node *left;
	Node *right;
	int data;
	Node(int d){
		this->left=NULL;
		this->right=NULL;
		this->data=d;
	}
};
class BST{
public:
	Node *root;
	BST(){
		this->root =NULL;
	}
	Node* insert_help(Node *node,int data){
          if(node == NULL){
          	Node *newNode = new Node(data);
          	return newNode;
          }
          if(node->data>=data){
           node->left = this->insert_help(node->left,data);
          }else{
           node->right = this->insert_help(node->right,data);
          }
          return node;
	}
	void insert(int data){
        this->root = this->insert_help(this->root,data);
	}
	   void printPreOrder_(Node *node)
    {
        if(node == NULL) return;
        cout << node->data << " ";
        printPreOrder_(node->left);
        printPreOrder_(node->right);
    }
    void printPreOrder()
    {
        this->printPreOrder_(this->root);
    }
	//Reverse inorder
	void UpdateBST_help(Node *node,int *sum){
		if(node==NULL) return;
		this->UpdateBST_help(node->right,sum);
		*sum += node->data;
		node->data = *sum ;
		this->UpdateBST_help(node->left,sum);
	}
	void UpdateBST(){
        int sum =0;
		this->UpdateBST_help(this->root,&sum);
	}
};
int main(){
  int t;
    cin >> t;
    while(t--)
    {
        BST *tree = new BST();
        int p;
        cin >> p;
        while(p--)
        {
            int n;
            cin >> n;
            tree->insert(n);
        }
        tree->printPreOrder();
        cout<<endl;
        tree->UpdateBST();
        tree->printPreOrder();

    }
}

    