//Bad approach
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head and head->val == val){
            head=head->next;
        }
        ListNode* cur = head;
        while(cur and cur->next!=NULL){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }
            else{
                cur=cur->next;
            }
        }
        return head;
    }
};

// BEST APPROACH 

//RECURSION 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;        
        }
        ListNode* next =removeElements(head->next, val);
        if(head->val == val){
            return next;
        }
        head->next = next;
        return head;
    }
};