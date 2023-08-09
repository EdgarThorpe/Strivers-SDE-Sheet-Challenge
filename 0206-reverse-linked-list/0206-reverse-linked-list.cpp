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


    ListNode* revList(ListNode* curr, ListNode* prev) {
        
        if(curr==NULL) return prev;
        
        ListNode* next = curr->next;
        curr->next = prev;
        return revList(next,curr);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        return revList(head, prev);


        // vector<int>arr;
        // for(ListNode *curr = head; curr!=NULL; curr=curr->next){
        //     arr.push_back(curr->val);
        // }
        // for(ListNode *curr=head; curr!=NULL; curr=curr->next){
        //     curr->val=arr.back();
        //     arr.pop_back();
        // }
        // return head;

        // ListNode *curr = head;
        // ListNode *prev = NULL;
        // while(curr!=NULL){
        //     ListNode *next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;






        // if(head==NULL||head->next==NULL)return head;
        // ListNode *rest_head=reverseList(head->next);
        // ListNode *rest_tail=head->next;
        // rest_tail->next=head;
        // head->next=NULL;
        // return rest_head;


        
    }
};