#include <iostream>
using namespace std;

class Node {
public :
    int childcount;
    int data ; 
    Node(int d,int n) {
        data = d ;
        childcount = n ;
        right = left = NULL ; 
    }
    Node *right ;
    Node *left ;
};


class GenericTree{
public:
	Node *root;
	GenericTree(){
		this->root = NULL;
	}
Node* buildTreeHelper(Node *root){
    int d,c ;
    cin >> d >> c;
    root = new Node(d,c);
    if(c==0){
        return root ; 
    }
    else if(c==1){
        root->left = buildTreeHelper(root->left);
        return root ;
    }
    else {
        root->left = buildTreeHelper(root->left);
        root->right = buildTreeHelper(root->right) ; 
        return root ;
    }
}
void buildTree(){
	this->root = this->buildTreeHelper(this->root);
}
 int sumAtK_(Node *node,int k){
 	int s=0;
 	if(node==NULL){
        return 0;
 	}
 	if(k<=0){
 		return node->data;
 	}
 	if(node->childcount==1){
  		s+= sumAtK_(node->left,k-1);
 	}
 	else if(node->childcount==2){
 		s+= sumAtK_(node->left,k-1)+sumAtK_(node->right,k-1);
 	}
 	return s;
 }
 int sumAtK(int k){
  return this->sumAtK_(this->root,k);
 }
};

int main(){
 GenericTree *tree = new GenericTree();
 tree->buildTree();
 int k;
 cin>>k;
 cout<<tree->sumAtK(k);
}
