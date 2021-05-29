//BRUTE FORCE
class Solution {
public:
    unordered_map<ListNode *,int> mp;
    ListNode *detectCycle(ListNode *head) {
        int i=0;
        while(head!=NULL){
            if(mp.find(head) == mp.end()){
                mp[head] = i;
                i++;
            }
            else{
                return head;
            }
            head=head->next;
        }
        return head;
    }
};

//BEST APPROACH
