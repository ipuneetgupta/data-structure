// verticalOrder_tree
#include<iostream>
#include<map>
#include<bits/stdc++.h>
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
void createParentNode(int *parent, Node *pointerNode[], int i, Node **root)
{
    if(pointerNode[i] != NULL) return;
    pointerNode[i] = new Node(i);

    if(parent[i] == -1)
    {
        *(root) = pointerNode[i];
        return;
    }

    if(pointerNode[parent[i]] == NULL)
    {
        createParentNode(parent, pointerNode, parent[i], root);
    }

    Node *p = pointerNode[parent[i]];

    if(p->left == NULL)
    {
        p->left = pointerNode[i];
    }
    else
    {
        p->right = pointerNode[i];
    }

    return;
}
Node *createPointerParent(int *parent, int n)
{
    Node *pointerNode[n];
    for(int i = 0; i < n; i++) pointerNode[i] = NULL;

    Node *root = NULL;
    for(int i = 0; i < n; i++)
    {
        createParentNode(parent, pointerNode, i, &root);
    }
    return root;
}
void printVerticalOrder_(Node *root, int horiDist ,map<int, vector<int>> &m)
{
  if(root==NULL) return;
  m[horiDist].push_back(root->data);
  printVerticalOrder_(root->left,horiDist-1,m);
  printVerticalOrder_(root->right,horiDist+1,m);
  return;   
}
void printVerticalOrder(Node *root)
{
    map <int, vector<int> > m;
    int horiDist = 0;
    printVerticalOrder_(root, horiDist,m);
    map<int, vector<int>> :: iterator it;
    for( it = m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
        	cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Node *root = createPointerParent(arr, n);
        printVerticalOrder(root);
        cout << endl;
    }
}

