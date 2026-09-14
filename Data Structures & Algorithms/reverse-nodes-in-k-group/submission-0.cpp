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
    ListNode* reverseKGroup(ListNode* head, int k) {
               if(head==NULL) return NULL;
        int i=0;
        ListNode* prev=NULL; ListNode* curr = head;
        ListNode* next = NULL;
        while(i<k && curr!=NULL){
            i++; curr=curr->next;
        }
         if(i!=k){ 
            return head;}
            i=0; curr=head;
        while(i<k && curr!=NULL){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;            
            i++;
        }

        ListNode* node = reverseKGroup(curr,k);
        head->next=node;
        return prev;
    }
};
