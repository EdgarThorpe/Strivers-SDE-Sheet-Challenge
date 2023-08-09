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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=(l1->val+l2->val);
        ListNode* head3= new ListNode(sum%10);
        int carry=sum/10;
        ListNode* head1=l1;
        ListNode* head2=l2;
        head1=head1->next;
        head2=head2->next;
        ListNode* ret=head3;
        while(head1 || head2)
        {
            int l=carry;
            if(head1)
            {
                l+=head1->val;
            }
            if(head2)
            {
                l+=head2->val;
            }
            ListNode* y=new ListNode(l%10);
            head3->next=y;
            head3=y;
            carry=l/10;
            if(head1)
            {
                head1=head1->next;
            }
            if(head2)
            {
                head2=head2->next;
            }

        }
        if(carry)
        {
            ListNode* last=new ListNode(carry);
            head3->next=last;
        }
        return ret;
        
    }
};