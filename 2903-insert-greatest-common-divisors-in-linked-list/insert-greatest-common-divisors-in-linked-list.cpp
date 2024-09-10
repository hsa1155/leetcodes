class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current=head;
        while (current->next)
        {
            ListNode* tmp=current->next;
            int gcd=__gcd(current->val,tmp->val);
            ListNode* newnode=new ListNode(gcd,tmp);
            current->next=newnode;
            current=tmp;
        }

        return head;
        
        
    }
};