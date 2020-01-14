#include<iostream>
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
int search(int *arr, int key, int low, int high)
{
    for(int i = low; i <=high; i++)
    {
        if(arr[i] == key) return i;
    }
    return -1;
}
Node *createTree(int *pre, int *in, int low, int high, int &preIdx, int n )
{
    if (low > high) return NULL;
    if(preIdx == n) return NULL;
    Node *node = new Node(pre[preIdx]);
    preIdx++;
    if(low == high) return node;
    int inIdx = search(in, node->data, low, high);
    node->left = createTree(pre, in, low, inIdx - 1, preIdx, n);
    node->right = createTree(pre, in, inIdx + 1, high, preIdx, n);
    return node;
}
void printPreorder(Node *node)
{
    if(node == NULL) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void display(Node *node)
{
    if(node == NULL) return;
    if(node->left != NULL) cout << node->left->data << " => ";
    else cout << "END => ";
    cout << node->data;
    if(node->right != NULL) cout << " <= " << node->right->data << endl;
    else cout << " <= END" << endl;


    if(node->left != NULL)
    {
        display(node->left);
    }
    if(node->right != NULL)
    {
        display(node->right);
    }
    return;
}
int main()
{
    int n;
    cin >> n;

    int pre[n];
    for(int i = 0; i < n; i++) cin >> pre[i];

    int m;
    cin >> m;

    int in[n];
    for(int i = 0; i < m; i++) cin >> in[i];
    int preIdx = 0;
    Node *root = createTree(pre, in, 0, n - 1, preIdx, n);
    // printPreorder(root);
    display(root);
}