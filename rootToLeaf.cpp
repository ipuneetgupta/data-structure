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
void printVec(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void sumRootToLeaf(Node *root, int key, int sum, vector<int> &v)
{
    if(root == NULL) return;
    sum +=  root->data;
    v.push_back(root->data);
    if(sum == key && (root->left == NULL && root->right == NULL))
    {
        printVec(v);
    }
    if(root->left != NULL)
    {
        sumRootToLeaf(root->left, key, sum, v);
    }
    if(root->right != NULL)
    {
        sumRootToLeaf(root->right, key, sum, v);
    }
    v.pop_back();
}

int main()
{
    Node *root =  buildTree();
    int key;
    cin >> key;
    vector<int> v;
    sumRootToLeaf(root, key, 0, v);

}