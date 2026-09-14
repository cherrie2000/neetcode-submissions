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
class Compare{
    public:
    bool operator()(ListNode*a, ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(auto it: lists){
            if(it!=NULL) pq.push(it);
        }       
        ListNode* head = new ListNode(0); ListNode* temp=head;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(top->next!=NULL) pq.push(top->next);
            temp->next = top;
            temp = temp->next;
        }
        return head->next;
    }
};
