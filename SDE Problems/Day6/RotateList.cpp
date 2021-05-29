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
        if(head==NULL or head->next==NULL){
            return head;
        }
        int length = 0;
        ListNode* newhead = head;
        while(newhead!=NULL){
            length++;
            if(newhead->next==NULL){
                newhead->next=head;
                break;
            }
            newhead=newhead->next;
        }
        k = length - k%length;
        for(int i=0;i<k;i++){
            newhead=newhead->next;
        }
        head=newhead->next;
        newhead->next=NULL;
        return head;
    }
};