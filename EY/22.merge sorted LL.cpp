/*
Given two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the merged list.

Examples:

Input: LinkedList1: 5->10->15->40, ListedList2: 2->3->20
Output: 2->3->5->10->15->20->40

Input: LinkedList1: 1->1, LinkedList2: 2->4
Output: 1->1->2->4

Expected Time Complexity: O(n+m)
Expected Auxilliary Space: O(1)

Constraints:
1 <= no. of nodes<= 105
0 <= node->data <= 105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
class Solution {
  public:
    Node* sortedMerge(Node* l1, Node* l2) {
      Node dummy(0);
      Node* curr = &dummy;
      
      while(l1!=NULL and l2!=NULL){
          if(l1->data <l2->data){
              curr->next=l1;
              l1=l1->next;
          }
          else{
              curr->next=l2;
              l2=l2->next;
          }
          curr = curr->next;
      }
      
      if(l1!=NULL){
          curr->next=l1;
      }
      else{
          curr->next=l2;
      }
      
      return dummy.next;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
