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
    //find middle
    ListNode* middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* newhead = NULL;
        while(head!=NULL){
            ListNode* next = head->next;
            head->next=newhead;
            newhead=head;
            head=next;
        }
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL){
            return true;
        }
        ListNode* mid = middle(head);
        ListNode* pali = head;
        while(pali!=mid){
            pali=pali->next;
        }
        ListNode* right = reverse(pali->next);
        while(right!=NULL){
            if(right->val != head->val){
                return false;
            }
            right=right->next;
            head=head->next;
        }
        return true;
    }
};