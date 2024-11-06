/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input:
   2
 /    \
1      3
        \
         5
Output: true 
Explanation: 
The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
Input:
  2
   \
    7
     \
      6
       \
        9
Output: false 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 
Input:
   10
 /    \
5      20
      /   \
     9     25
Output: false
Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
Expected Time Complexity: O(n) 
Expected Auxiliary Space: O(Height of the tree)
where n is the number of nodes in the given tree

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// } Driver Code Ends
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBSTUtil(Node* node, int min, int max) {
        // An empty tree is BST
        if (node == nullptr) return true;

        // Check current node's value against min and max constraints
        if (node->data <= min || node->data >= max) return false;

        // Check left subtree with updated max constraint
        // Check right subtree with updated min constraint
        return isBSTUtil(node->left, min, node->data) &&
               isBSTUtil(node->right, node->data, max);
    }
    bool isBST(Node* root) {
      return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};


//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        // if (s[0] == '9') {
        //     cout << "false\n";
        //     return 0;
        // }
        Node* root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "true\n";

        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
