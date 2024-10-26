//iterative
class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }
};

//recursive
class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        // code here
        // return head of reversed list
        if(head==NULL||head->next==NULL) return head;
        Node* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return rest;
    }
};
//stack
class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        stack<Node*> s;
        Node* temp = head;

        while (temp->next != NULL) {
            s.push(temp);
            temp = temp->next;
        }
      
      
        head = temp;
  
      
        while (!s.empty()) {
            temp->next = s.top();
            s.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};
