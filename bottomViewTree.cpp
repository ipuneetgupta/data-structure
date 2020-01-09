
#include<iostream>
#include<queue>
#include<map>
using namespace std;
class Node
{
public:
    Node *left ;
    Node *right;
    int data;
    int hd;
    Node(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
        this->hd = 0;
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

void bottomView(Node *root) 
{ 
    if (root == NULL) 
        return; 
    map<int, int> m; 
    queue<Node *> q; 
    int hd =0;
    q.push(root);  
       while (!q.empty()) 
    { 
        Node *node = q.front();   
        hd = node->hd; 
        m[hd] = node->data; 
        if (node->left != NULL) 
        { 
            node->left->hd = hd-1; 
            q.push(node->left); 
        } 
        if (node->right != NULL) 
        { 
            node->right->hd = hd+1; 
            q.push(node->right); 
        } 
        q.pop();
    } 
  
    for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 
} 
void printPreorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
    return;
}

int main()
{
    Node *root = levelOrderInput(root);
    bottomView(root);
    // printPreorder(root);
}

