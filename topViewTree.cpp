
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
    int horiDist;
    Node(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
        this->horiDist = 0;
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
void topView(Node *root)
{
    if(root == NULL) return;
    queue<Node *> q;
    map<int, int> m;
    q.push(root);
    int hd = 0;
    hd = root->horiDist;
    while(!q.empty())
    {
        Node *node = q.front();
        int hd = node->horiDist;
        if(m.count(hd) == 0)
        {
            m[hd] = node->data;
        }
        if(node->left != NULL)
        {
            q.push(node->left);
            node->left->horiDist = hd - 1;
        }
        if(node->right != NULL)
        {
            q.push(node->right);
            node->right->horiDist = hd + 1;
        }
        q.pop();
    }

    for(auto it = m.begin();it!=m.end();it++){
        cout<<it->second<<" ";
    }
    cout<<endl;
    return;
}
int main()
{
    Node *root = levelOrderInput(root);
    topView(root);
}

