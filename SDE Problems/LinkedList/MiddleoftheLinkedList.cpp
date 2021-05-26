/**
 * Basic Approach
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int cnt=0;
        while(head!=NULL){
            cnt++;
            
            head=head->next;
        }
        return cnt;
    }
    ListNode* middleNode(ListNode* head) {
        int ln = length(head);
        int ind;
        ind = ln/2+1;
        ListNode* ans;
        while(ind){
            ans=head;
            head=head->next;
            ind--;
        }
        return ans;
    }
};
// Best approach
//Slow and fast pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow =head;
        ListNode*  fast = head;
        while(fast and fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};