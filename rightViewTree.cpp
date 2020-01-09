
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
    int level;
    Node(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
        this->level = 0;
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

void rightView(Node *root)
{
    queue<Node *> q;
    map<int, int> m;
    q.push(root);
    int l = 0;
    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        l = node->level;
         m[l] = node->data;
        if(node->left != NULL)
        {
            q.push(node->left);
            node->left->level = l + 1;
        }
        if(node->right != NULL)
        {
            q.push(node->right);
            node->right->level = l + 1;
        }
    }
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
    return;
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
    rightView(root);
    // printPreorder(root);
}

