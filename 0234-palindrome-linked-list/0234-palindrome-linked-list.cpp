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


    // ListNode *reverseList(ListNode *curr,ListNode *prev){
    //     if(curr==NULL)return prev;
    //     ListNode *next=curr->next;
    //     curr->next=prev;
    //     return reverseList(next,curr);
    // }
        
    bool isPalindrome(ListNode* head) {
        
        //Stack, SC = O(n)

        // stack<int>st;
        // for(ListNode *curr=head; curr!=NULL; curr=curr->next) st.push(curr->val);
        // for(ListNode *curr=head; curr!=NULL; curr=curr->next){
        //     if(st.top()!=curr->val) return false;
        //     st.pop();
        // }
        // return true;

        if(head==NULL)return true;
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* next = NULL;
        ListNode* curr = slow->next;
        ListNode* prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        while(prev!=NULL){
            if(head->val!=prev->val){
                return false;
            }
            head=head->next;
            prev=prev->next;
        }
        return true;
        
        

        
        
        // Reverse half Array

        // if(head==NULL)return true;
        // ListNode *slow=head,*fast=head;
        // while(fast->next!=NULL&&fast->next->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // ListNode *rev=reverseList(slow->next,NULL);
        // ListNode *curr=head;
        // while(rev!=NULL){
        //     if(rev->val!=curr->val)
        //         return false;
        //     rev=rev->next;
        //     curr=curr->next;
        // }
        // return true;




        




        




        




        

    }
};