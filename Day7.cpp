//Day 7
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int len = 0;
        ListNode *temp =head;
        while(temp){
            len++;
            temp=temp->next;
        }
        k%=len;
        ListNode *prev = NULL;
        temp=head;
        for(int i=0;i<len-k;i++){
            prev = temp;
            temp = temp->next;
        }
        /*1->2->3->4->5->NULL
        len = 5, k= 2;
        len-k = 3;
        temp -> 4
        prev -> 3
        */
        
        if(temp==NULL){
            //wholse list is rotated no effect
            return head;
        }
        else{
            prev->next=NULL;
            ListNode *node = head;
            head = temp;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = node;
            return head;
        }
        
    }
};
