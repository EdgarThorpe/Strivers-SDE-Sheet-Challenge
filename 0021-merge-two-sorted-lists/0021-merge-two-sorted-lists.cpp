/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        //     if(a==NULL)return b;
        // if(b==NULL)return a;
        // ListNode *head=NULL,*tail=NULL;
        // if(a->val<=b->val){
        //     head=tail=a;a=a->next;
        // }
        // else{
        //     head=tail=b;b=b->next;
        // }
        // while(a!=NULL&&b!=NULL){
        //     if(a->val<b->val){
        //         tail->next=a;tail=a;a=a->next;
        //     }
        //     else{
        //         tail->next=b;tail=b;b=b->next;
        //     }
        // }
        // if(a==NULL){tail->next=b;}
        // else{
        //     tail->next=a;
        // }
        // return head;

        if(a==NULL) return b;
        if (b==NULL) return a;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        if(a->val<=b->val){
            head = a;
            tail = a;
            a = a->next;
        }
        else{
            head = b;
            tail = b;
            b=b->next;
        }
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
                tail->next = a;
                tail = a;
                a=a->next;
            }
            else{
                tail->next = b;
                tail = b;
                b=b->next;
            }
        }
        if(a){
            tail->next = a;
        }
        else{
            tail->next = b;
        }

        return head;
    }
};