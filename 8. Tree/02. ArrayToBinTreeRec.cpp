#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

node *arrtobint(vector<int> v, int i, int n){
    if(i>=n or v[i]==-1) return NULL;

    node* root = new node(v[i]);
    root->left = arrtobint(v,2*i+1,n);
    root->right = arrtobint(v,2*i+2,n);
    return root;
}

void printtreelvlwise(node *root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        cout<<curr->val<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
bool isBST(node* root, int min, int max){
    if(root == NULL) return true;

    if(root->val <= min or root->val >= max) return false;

    return isBST(root->left,min,root->val) && isBST(root->right,root->val,max);
}
int main()
{
    vector<int> arr = {1, 2, 3, -1, 4, 5, 6}; // Example array
    int n = arr.size();
    node *root = arrtobint(arr,0,n);

    cout << "Level-order traversal of the binary tree: ";
    printtreelvlwise(root);
    cout<<endl;
    if(isBST(root,INT_MIN,INT_MAX)) cout<<"1";
    else cout<<"0";
}
