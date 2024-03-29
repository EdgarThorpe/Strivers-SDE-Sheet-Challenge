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
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        ListNode* head1 = first;
        ListNode* head2 = second;
        int sum = (head1->val)+(head2->val);
        int carry = sum/10;
        ListNode* head3 = new ListNode(sum%10);
        ListNode* curr = head3;
        cout<<head3->val;
        head1=head1->next;
        head2=head2->next;
        while(head1 || head2){
            int l = carry;
            if(head1){
                l+=head1->val;
                head1=head1->next;
            }
            if(head2){
                l+=head2->val;
                head2=head2->next;
            }
            ListNode* y = new ListNode(l%10);
            head3->next = y;
            head3 = y;
            carry = l/10;
        }

        if(carry){
            ListNode* bindu = new ListNode(carry);
            head3->next = bindu;
        }

        return curr;
















        
    }
};