// printLeafNode
#include<iostream>
#include<queue>
using namespace std;
class Node
{
public:
    Node *left ;
    Node *right;
    int data;
    Node(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
    }
};
Node *levelOrderInput(Node *root)
{
    queue<Node *> q;
    int val;
    cin >> val;
    root = new Node(val);
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();

        if(temp->left == NULL)
        {
            int a;
            cin >> a;
            if(a != -1)
            {
                temp->left = new Node(a);
                q.push(temp->left);
            }
        }
        if(temp->right == NULL)
        {

            int a;
            cin >> a;

            if(a != -1)
            {
                temp->right = new Node(a);
                q.push(temp->right);
            }
            q.pop();

        }
    }
    return root;
}
void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> n;
    n.push(root);
    while (!n.empty())
    {
        cout << n.front()->data << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
    }
}
 void printPreOrder(Node *node)
    {
        if(node == NULL) return;
        cout << node->data << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
 void printLeafNode(Node *root) 
{ 
    if (root==NULL) 
        return; 
      
    if (root->left==NULL && root->right==NULL) 
    { 
        cout << root->data << " ";  
        return; 
    } 
    if (root->left) 
       printLeafNode(root->left); 
    if (root->right) 
       printLeafNode(root->right); 
}  
int main()
{
    Node *root = levelOrderInput(root);
    // printPreOrder(root);
    printLeafNode(root);
}