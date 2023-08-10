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
    ListNode* rotateRight(ListNode* head, int k) {
        // if (head == NULL || head->next == NULL || k == 0) {
        //     return head;
        // }
        
        // int len = 1;
        // ListNode* tail = head;
        // while (tail->next != NULL) {
        //     tail = tail->next;
        //     len++;
        // }
        
        // k = k % len;
        // if (k == 0) {
        //     return head;
        // }
        
        // ListNode* curr = head;
        // for (int i = 1; i < len - k; i++) {
        //     curr = curr->next;
        // }
        
        // tail->next = head;
        // head = curr->next;
        // curr->next = NULL;
        
        // return head;

        if(head==NULL) return NULL;

        int len = 1;
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail=tail->next;
            len++;
        }

        k%=len;

        if(k==0) return head;

        ListNode* temp = head;
        for(int i = 1; i < len-k; i++){
            temp=temp->next;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;

        // int len = 1;
        // ListNode* tail = head;
        // while(tail->next!=NULL){
        //     tail=tail->next;
        //     len++;
        // }

        // k %= len;

        // if(k==0) return head;

        // ListNode* temp = head;
        // for(int i = 1; i < len-k; i++){
        //     temp=temp->next;
        // }
        // tail->next = head;
        // head=temp->next;
        // temp->next = NULL;
        // return head;




    }
};