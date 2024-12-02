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

node* arrtobin(vector<int>v){
    if(v.size()==0) return NULL;
    queue<node*>q;
    node* root = new node(v[0]);
    q.push(root);
    int i =1;
    while(i<v.size()){
        node* curr = q.front();
        q.pop();
        if(i<v.size() and v[i]!=-1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i<v.size() and v[i]!=-1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
vector<vector<int>>printlvlwise(node* root){
    vector<vector<int>> tree;
    if(root==NULL) return tree;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int>lvl;
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();
            lvl.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        tree.push_back(lvl);
    }
    return tree;
}
bool isBSThelper(node* root, int min, int max){
    if(root==NULL) return true;
    if(root->val < min or root->val > max) return false;
    int val = root->val;
    bool left_sub_tree_check = isBSThelper(root->left,min,val);
    bool right_sub_tree_check = isBSThelper(root->right,val,max);

    return left_sub_tree_check and right_sub_tree_check;
}
bool isBST(node* root){
    return isBSThelper(root,INT_MIN,INT_MAX);
}
node* mirrorBST(node* root){
    if(root==NULL) return NULL;
    swap(root->left,root->right);

    mirrorBST(root->left);
    mirrorBST(root->right);
    return root;

}
int main(){
    vector<int> v = {4,2,6,1,3,5,7};
    node* root = arrtobin(v);
    vector<vector<int>>lvl = printlvlwise(root);
    for(auto i : lvl){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    if(isBST(root)) cout<<"yes BST"<<endl;
    else cout<<"No BST"<<endl;

    node* root2 = mirrorBST(root);
    vector<vector<int>>lvl2 = printlvlwise(root);
    for(auto i : lvl2){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
