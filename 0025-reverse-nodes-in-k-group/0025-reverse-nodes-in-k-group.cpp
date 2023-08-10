
// /**
//  * Definition for singly-linked list.
//  * struct ListListListNode {
//  *     int val;
//  *     ListListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // if(head == NULL) return NULL;
        // ListNode* next = NULL;
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // int count = 0;
        // ListNode* temp = head;
        // while(temp!=NULL && count<k){
        //     temp=temp->next;
        //     count++;
        // }
        // if(count<k){
        //     return head;
        // }
        // count = 0;
        // while(curr!=NULL && count<k){
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        //     count++;
        // }

        // if(next!=NULL) head->next = reverseKGroup(next,k);

        // return prev;
        if(head==NULL) return NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL && count<k){
            temp=temp->next;
            count++;
        }
        if(count<k) return head;
        count = 0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev = curr;
            curr=next;
            count++;
        }
        if(head!=NULL) head->next = reverseKGroup(next,k);
        return prev;

    }

};
