#include<iostream>
#include<queue>
#include<map>
#include<string>
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
        this->level = 1;
    }
};
Node *buildTree()
{
    int d;
    cin >> d;
    Node *temp = new Node(d);
    string ip;
    cin >> ip;
    if(ip == "true") temp->right = buildTree();
    string ip2;
    cin >> ip2;
    if(ip2 == "true") temp->left = buildTree();
    return temp;
}
void zigZagView(Node *root)
{
    queue<Node *> q;
    map<int, vector<int>> m;
    q.push(root);
    int l = 1;
    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        l = node->level;
         m[l].push_back(node->data);
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
        if(it->first % 2 != 0)
        {
        	// cout<<it->first<<" even";
            for(int i = it->second.size() - 1; i >= 0; i--)
            {
                cout << it->second[i] << " ";
            }
        }
        else
        {        	//cout<<it->first<<" odd";

            for(int i = 0; i < it->second.size(); i++)
            {
                cout << it->second[i] << " ";
            }
        }
    }
    return;
}
void printVerticalOrder_(Node *root, int horiDist ,map<int, vector<int>> &m)
{
  if(root==NULL) return;
  m[horiDist].push_back(root->data);
  printVerticalOrder_(root->left,horiDist-1,m);
  printVerticalOrder_(root->right,horiDist+1,m);
  return;   
}

int main()
{
    Node *root =  buildTree();
    // printVerticalOrder(root);
    zigZagView(root);
}