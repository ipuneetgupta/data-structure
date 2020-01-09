#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
    }
};
class BST
{
public:
    Node *root;
    BST()
    {
        this->root = NULL;
    }
    Node *insert_help(Node *node, int data)
    {
        if(node == NULL)
        {
            Node *newNode = new Node(data);
            return newNode;
        }
        if(node->data >= data)
        {
            node->left = this->insert_help(node->left, data);
        }
        else
        {
            node->right = this->insert_help(node->right, data);
        }
        return node;
    }
    void insert(int data)
    {
        this->root = this->insert_help(this->root, data);
    }
    void printRange_(Node *root, int k1, int k2)
    {
        if(root == NULL)
            return;

        printRange_(root->left, k1, k2);


        if(root->data >= k1 && root->data <= k2)

            cout << root->data << " ";

        if(root->data >= k2)
        {
            return ;
        }

        printRange_(root->right, k1, k2);
    }
    void printRange(int k1,int k2){
    	this->printRange_(this->root,k1,k2);
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
};
int main()
{
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
        cout<<"# Preorder : ";
        tree->printPreOrder();
        cout<<endl;
        cout<<"# Nodes within range are : ";
        int k1,k2;
        cin>>k1>>k2;
        tree->printRange(k1,k2);
        cout<<endl;

    }
}