// BST-SumNode
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
	void PrintLevelOrder(){
       queue<Node*> q;
       Node *node;
       q.push(this->root);
       q.push(NULL);
       while(!q.empty()){
       	  node = q.front();
       	  q.pop();
       	  if(q.empty()){
       	  	cout<<endl;
       	  	break;
       	  }
       	 else if (node == NULL){
       	  	q.push(NULL);
       	  	cout<<endl;
       	  }
       	  else{
          cout<<node->data<<" ";
          if(node->left!=NULL) q.push(node->left);
          if(node->right!=NULL)q.push(node->right);
      }
       }
	}
	//Reverse inorder
	void UpdateBST_help(Node *node,int *sum){
		if(node==NULL) return;
		this->UpdateBST_help(node->right,sum);
		*sum += node->data;
		node->data = *sum - node->data;
		this->UpdateBST_help(node->left,sum);
	}
	void UpdateBST(){
        int sum =0;
		this->UpdateBST_help(this->root,&sum);
	}
};
int main(){
   BST *tree = new BST();
   while(true){
   int n;
   cin>>n;
   if(n==-1){
   	break;
   }
   tree->insert(n);
}
tree->UpdateBST();
tree->PrintLevelOrder();
}