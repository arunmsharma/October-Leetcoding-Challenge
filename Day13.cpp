//Day 13
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
    ListNode *merge(ListNode *a,ListNode *b){
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;
        }
        ListNode *res = NULL;
        if(a->val<b->val){
            res = a;
            res->next = merge(a->next,b);
        }
        else{
            res = b;
            res->next = merge(a,b->next);
        }
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        ListNode *slow = head,*fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *newhead = slow->next;
        slow->next=NULL;
        
        return merge(sortList(head),sortList(newhead));
    }
};
