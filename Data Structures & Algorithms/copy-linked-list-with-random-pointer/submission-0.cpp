/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
              if(head==NULL) return head;
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next=temp;
            curr = curr->next->next;
        }
        curr=head;
        while(curr!=NULL && curr->next!=NULL){
            
            curr->next->random = curr->random?curr->random->next:NULL;
            curr=curr->next->next;
        }

        curr=head;
        Node* newHead=head->next;
        Node* temp = newHead;
        while(curr!=NULL && temp!=NULL){
            curr->next = curr->next->next;
            temp->next = temp->next?temp->next->next:NULL;
            curr=curr->next;
            temp=temp->next;
        }
        return newHead;
    }
};
