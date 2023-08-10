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
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         // ListNode* cursor = head;
//         // for(int i = 0; i < k; i++){
//         //     if(cursor == nullptr) return head;
//         //     cursor = cursor->next;
//         // }
//         // ListNode* curr = head;
//         // ListNode* prev = nullptr;
//         // ListNode* nxt = nullptr;
//         // for(int i = 0; i < k; i++){
//         //     nxt = curr->next;
//         //     curr->next = prev;
//         //     prev = curr;
//         //     curr = nxt;
//         // }
//         // head->next = reverseKGroup(curr, k);
//         // return prev;

        
//         if(head==NULL) return NULL;
//         ListNode* next = NULL;
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         int count = 0;
//         while(curr!=NULL && count<k){
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr=next;
//             count++;
//         }
//         if(head!=NULL) head->next = reverseKGroup(next,k);
//         return prev;
//     }
// };

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
    if (head == NULL) return NULL;
    
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    int count = 0;
    
    // Count the number of nodes in this group
    ListNode* temp = head;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }
    
    if (count < k) {
        // No need to reverse, return the head of this group
        return head;
    }
    
    count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Recursive call to reverse the next group
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }
    
    return prev; // New head of the reversed group
}

};
