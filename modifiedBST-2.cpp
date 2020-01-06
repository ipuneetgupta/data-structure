// BST-SumNode
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
    Node *removeRange_(Node *node, int low, int high)
    {

        if(node == NULL) return NULL;

        node->left = this->removeRange_(node->left, low, high);
        node->right = this->removeRange_(node->right, low,high);

        //postOrder Traversal first fix left and right subtree then work on root
        if(node->data < low)
        {
            Node *rChild = node->right;
            delete node;
            return rChild;
        }
        if(node->data > high)
        {
            Node *lChild = node->left;
            delete node;
            return lChild;
        }
        return node;
    }
    void *removeRange(int low, int high)
    {
        this->root = this->removeRange_(this->root, low, high);
    }
};
int main()
{
    BST *tree = new BST();
    int t;
    cin >> t;
    while(t--)
    {
        BST *tree = new BST();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            tree->insert(a);
        }
        cout << "Preorder : "; 
        tree->printPreOrder();        
        cout<<endl;
        int low, high;
        cin >> low >> high;
        tree->removeRange(low, high);
        cout << "Preorder : "; 
        tree->printPreOrder();
    }
}