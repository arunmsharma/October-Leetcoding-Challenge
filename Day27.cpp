//Day 27
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        while(slow and fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast){
                break;
            }
        }
        if(!slow or !fast or !fast->next){
            return nullptr;
        }
        
        slow = head;
        while(slow!=fast){
            slow=slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
