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
void justLargerElement(Node *root, int key, Node **ans)
{
    if(root == NULL) return ;
    if(root->data > key)
    {
        if((*ans) == NULL || (*ans)->data > root->data)
        {
            *(ans) =  root;
        }
    }
    for(int i = 0; i < root->children.size(); i++)
    {
        justLargerElement(root->children[i], key, ans);
    }
    return;
}
void display(Node *root)
{
    cout << root->data << " -> ";
    for(int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << "END"<<endl;
    for(int i = 0; i < root->children.size(); i++)
    {
        display(root->children[i]);
    }
}
int main()
{
    Node *root = buildTree();
    Node *ans = NULL;
    display(root);
    int key;
    cin >> key;
    justLargerElement(root, key, &ans);
    cout << ans->data << endl;
}