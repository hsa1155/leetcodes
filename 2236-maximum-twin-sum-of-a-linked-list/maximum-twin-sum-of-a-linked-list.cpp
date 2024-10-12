class Solution {
public:
    int pairSum(ListNode* head) {
        int n=0;
        ListNode* current= head;
        ListNode* from=nullptr;
        ListNode* tmp=nullptr;
        int ans=0;
        while (current)
        {
            n++;
            current=current->next;
        }
        current=head;

        for(int i=0;i<n/2;i++)
        {
            tmp=current->next;
            current->next=from;
            from=current;
            current=tmp;

        }
        //from goes back current goes foward
        for(int i=0;i<n/2;i++)
        {
            ans=max(ans,current->val+from->val);

            current=current->next;
            from=from->next;

        }
        return ans;
        
    }
};