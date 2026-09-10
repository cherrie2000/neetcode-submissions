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
void calculate(ListNode* list, ListNode* node,int carry){
    while(list!=NULL){
        int temp= list->val+carry;
        node->next = new ListNode(temp%10);
        carry = temp/10;
        list=list->next;
        node=node->next;
    }
    if(carry){
        node->next = new ListNode(carry);
    }
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           ListNode* list1 = l1; ListNode* list2 = l2;
        int carry=0;
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        while(list1!=NULL && list2!=NULL){
            int temp = list1->val+list2->val+carry;
            node->next = new ListNode(temp%10);
            carry = temp/10;
            node= node->next;
            list1= list1->next, list2 = list2->next;
        }
        if(list1==NULL){
             calculate(list2,node,carry);
        }
        else{
            calculate(list1,node,carry);
        }
        return head->next;
    }
};
