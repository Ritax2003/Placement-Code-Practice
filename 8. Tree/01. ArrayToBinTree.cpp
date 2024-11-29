#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;

    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};
node* arraytobt(vector<int> v){
    if(v.empty()) return NULL;

    node* root = new node(v[0]);

    queue<node*> q;
    q.push(root);

    int i = 1;

    while(i<v.size()){
        node* curr = q.front();
        q.pop();

        if(i<v.size() && v[i]!=-1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if (i < v.size() && v[i] != -1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
    
}


void printTree(node* root){
    if(!root) return;

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        if(curr){
            cout<<curr->val<<" ";
            q.push(curr->left);
            q.push(curr->right);
        }
        
    }
}
int main(){
    vector<int>v;

    vector<int> arr = {1, 2, 3, -1, 4, 5, 6}; // Example array
    node *root = arraytobt(arr);

    cout << "Level-order traversal of the binary tree: ";
    printTree(root);

    return 0;
}
