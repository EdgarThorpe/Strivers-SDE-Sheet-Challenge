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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Slow Fast Method
        // if(head==NULL) return head;
        // if(head->next==NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(n--){
            fast = fast->next;
        }
        if(fast==NULL) return head->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* RedNode = slow->next;
        slow->next = slow->next->next;
        delete RedNode;
        return head;


        // if(head==NULL) return NULL;
        // if(head->next==NULL) return NULL;
        // ListNode *curr = head;
        // int len = 1;
        // while(curr->next!=NULL){
        //     curr=curr->next;
        //     len++;
        // }
        // if(len<n) return NULL;
        // else if(len==n){
        //     head = head->next;
        //     return head;
        // }
        // else{

        //     curr = head;
        //     int k = len-n-1;
        //     while(k--){
        //         curr=curr->next;
        //     }
        //     // curr->next=curr->next->next;
        //     //curr = 3
        //     ListNode *temp = curr->next;
        //     ListNode *last = temp->next;
        //     curr->next = last;
        //     delete temp;
        // }
        // return head;

        // ListNode *slow = head, *fast = head;
        // while (n--) fast = fast->next;
        // if (!fast) return head->next;
        // while (fast->next) {
        //     slow = slow->next;
        //     fast = fast->next;
        // }
        // ListNode* toDelete = slow->next;
        // slow->next = slow->next->next;
        // delete toDelete;
        return head;



    }
};