//BRUTE FORCE

class Solution {
public:
    unordered_map<ListNode*,int> mp;
    bool hasCycle(ListNode *head) {
        while(head!=NULL){
            if(mp.find(head) == mp.end()){
                mp[head]++;
            }
            else{
                return true;
            }
            head=head->next;
        }
        return false;
    }
};

//best approach
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(head==NULL or head->next == NULL){
            return false;
        }
        while(fast and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};