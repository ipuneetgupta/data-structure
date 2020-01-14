#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
    int ht ;
    Node(int d)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = d;
        this->ht = 0;
    }
};
class InfoNode
{
public:
    int min;
    int max;
    bool isBst;
    int ans;
    int size;
    InfoNode(int m, int mx, bool p, int r, int s)
    {
        this->min = m;
        this->max = mx;
        this->isBst = p;
        this->ans = r;
        this->size = s ;
    }
};
int search(int *arr, int key, int low, int high, int n)
{
    for(int i = low; i <= high; i++)
    {
        if(arr[i] == key) return i;
    }
    return -1;
}

Node *createTree(int *pre, int *in, int &preIdx, int low, int high, int n)
{
    if(preIdx == n) return NULL;
    if(low > high) return NULL;
    Node *root = new Node(pre[preIdx]);
    preIdx++;
    int inIdx = search(in, root->data, low, high, n);
    root->left = createTree(pre, in, preIdx, low, inIdx - 1, n);
    root->right = createTree(pre, in, preIdx, inIdx + 1, high, n);
    return root;
}
void preOrder(Node *root)
{
    if(root == NULL) return ;
    cout << root->data << "=>" << root->ht << ",";
    preOrder(root->left);
    preOrder(root->right);
    return ;
}
int height(Node *root)
{
    if(root == NULL) return 0;
    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}
InfoNode *largestSubTreeBST(Node *root)
{
    if(root == NULL) return new InfoNode(INT_MIN, INT_MAX, true, 0, 0);
    if(root->left == NULL && root->right == NULL) return new InfoNode(root->data, root->data, true, 1, 1);

    InfoNode *left = largestSubTreeBST(root->left);
    InfoNode *right = largestSubTreeBST(root->right);

    InfoNode *present;
    present->size = 1 + left->size + right->size;

    if(left->isBst && right->isBst && left->max < root->data && right->min > root->data)
    {
        present->min = min(left->min, min(right->min, root->data));
        present->max = max(right->max, max(left->max, root->data));
        present->isBst = true;
        present->ans = present->size;
        return present;
    }
    present->ans = max(left->ans, right->ans);
    present->isBst = false;
    return present;

}
class Info
{
public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTBT(Node *root)
{

    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    Info present;
    present.size = (1 + l.size + r.size);
    if (l.isBST && r.isBST && l.max < root->data &&
            r.min > root->data)
    {
        present.min = min(l.min, min(r.min, root->data));
        present.max = max(r.max, max(l.max, root->data));
        present.ans = present.size;
        present.isBST = true;

        return present;
    }
    present.ans = max(l.ans, r.ans);
    present.isBST = false;

    return present;
}
int main()
{
    int n;
    cin >> n;
    int pre[n], in[n];
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    int preIdx = 0;
    Node *root = createTree(pre, in, preIdx, 0, n - 1, n);
    cout << largestBSTBT(root).ans << endl;
        // cout << largestSubTreeBST(root)->ans << endl;

    // preOrder(root);
}