/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
ListNode* reverse(ListNode* node){
    if(node==NULL || node->next==NULL) return node;
    ListNode* temp=reverse(node->next);
    node->next->next=node;
    node->next=NULL;
    return temp;
}
    void reorderList(ListNode* head) {
           ListNode* slow=head; ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
 
        ListNode* node = reverse(slow->next);
        slow->next=NULL;
        
        while(node!=NULL && head!=NULL){
            ListNode* temp=head->next;
            ListNode* node_next = node->next;
            head->next=node;
            node->next = temp;
            node= node_next;
            head = head->next->next;
        }
    }
};
