//THIS IS MY SOLUTION WHICH O(1) SPACE COMPLEXITY CHECK STRIEVER CODE ALSO
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = l1;
        int carry=0;
        int sm=0;
        while(l1!=NULL and l2!=NULL){
            sm = l1->val + l2->val;
            if(carry){
                sm+=1;
                carry=0;
            }
            if(sm>9){
                carry=1;
                sm=sm-10;
            }
            l1->val=sm;
            if(l1->next==NULL and l2->next!=NULL){
                l1->next=l2->next;
                l1=l1->next;
                break;
            }
            if(l1->next == NULL and carry){
                ListNode* newsum = new ListNode(1);
                l1->next=newsum;
                l1=l1->next->next;
                break;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            sm = l1->val;
            if(carry){
                sm+=1;
                carry=0;
            }
            if(sm>9){
                carry=1;
                sm=sm-10;
            }
            l1->val=sm;
            if(l1->next == NULL and carry){
                ListNode* newsum = new ListNode(1);
                l1->next=newsum;
                break;
            }
            l1=l1->next;
        }
        return sum;
    }
};