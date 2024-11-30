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
node* arrtobt(vector<int> v){
    if(v.size()==0) return NULL;
    queue<node*>q;
    node* root = new node(v[0]);
    q.push(root);
     int i = 1;
     while(i<v.size()){
        node* curr = q.front();
        q.pop();
        if(i<v.size() and v[i]!=-1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i<v.size() and v[i]!=-1){
            curr->right=new node(v[i]);
            q.push(curr->right);
        }
        i++;
     }
     return root;
}
vector<vector<int>> printlvlwise(node* root){
    vector<vector<int>>res;
    if(root==NULL) return res;
    queue<node*>q;
    q.push(root);

    while(q.size()!=0){
        int n = q.size();
        vector<int> lvl;
        for(int i =0;i<n;i++){
            node* curr = q.front();
            q.pop();
            lvl.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        res.push_back(lvl);
    }
}
int main(){
    vector<int>tree={1,2,3,-1,4,5,-1,6,7,8,10,-1,34,-1};
    node* root = arrtobt(tree);
    vector<vector<int>>v = printlvlwise(root);
    for(auto i :v){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
        cout<<"---level---"<<endl;
        
    }

}
