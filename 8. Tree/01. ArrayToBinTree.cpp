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


vector<vector<int>> printTree(node* root){
    vector<vector<int>>res;
    if(root == NULL) return res;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        res.push_back(temp);
    }
}
int main(){
    vector<int>v;

    vector<int> arr = {1, 2, 3, -1, 4, 5, 6}; // Example array
    node *root = arraytobt(arr);

    cout << "Level-order traversal of the binary tree: "<<endl;
    vector<vector<int>>ans = printTree(root);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
