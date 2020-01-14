// countNoOfLeafNodeGT
#include<iostream>
#include<vector>
using namespace std;
class Node
{
public:
    int cSize;
    vector<Node *> children;
    int data;
    Node(int d, int n)
    {
        this->cSize = n;
        this->data = d;
        children.resize(n);
    }
};
Node *buildTree()
{
    int d, n;
    cin >> d >> n;
    Node *root = new Node(d, n);
    for(int i = 0; i < n; i++)
    {
        root->children[i] = buildTree();
    }
    return root;
}
int countLeafNode(Node *root)
{
    if(root == NULL) return 0;
    if(root->children.size()== 0)
    {
        return 1;
    }
    int count = 0;
    for(int i = 0; i < root->children.size(); i++)
    {
        count += countLeafNode(root->children[i]);
    }
    return count;
}
void display(Node *root)
{
    cout << root->data << " -> ";
    for(int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << "END" << endl;
    for(int i = 0; i < root->children.size(); i++)
    {
        display(root->children[i]);
    }
}
int main()
{
    Node *root = buildTree();
    Node *ans = NULL;
    // display(root);
    cout<<countLeafNode(root);
}