//O(n) approach
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
    int getDecimalValue(ListNode* head) {
        int ln = length(head);
        int digit=0;
        int i=1;
        while(head!=NULL){
            digit+= (head->val) * pow(2,ln-i);
            i++;
            head=head->next;
        }
        return digit;
    }
};

//More better approach
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num= head->val;
        while(head->next!=NULL){
            num = num*2 + head->next->val;
            head=head->next;
        }
        return num;
    }
};

//More better with bit manipulation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num= head->val;
        while(head->next!=NULL){
            num = (num<<1)|head->next->val;
            head=head->next;
        }
        return num;
    }
};