// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		// int n = 0;
// 		// int m = 0;
// 		// ListNode* ptr1 = headA;
// 		// ListNode* ptr2 = headB;
// 		// while(ptr1 != NULL){
// 		// 	n++;
// 		// 	ptr1 = ptr1 -> next;
// 		// }
// 		// while(ptr2 != NULL){
// 		// 	m++;
// 		// 	ptr2 = ptr2 -> next;
// 		// }
// 		// int t = abs(n - m);
// 		// if(n > m){
// 		// 	while(t){
// 		// 		headA = headA -> next;
// 		// 		t--;
// 		// 	}
// 		// }
// 		// else{
// 		// 	while(t){
// 		// 		headB = headB -> next;
// 		// 		t--;
// 		// 	}
// 		// }
// 		// while(headA != NULL and headB != NULL){
// 		// 	if(headA == headB){
// 		// 		return headA;
// 		// 	}
// 		// 	headA = headA -> next;
// 		// 	headB = headB -> next;
// 		// }
// 		// return NULL;

// 		if(headA==NULL || headB == NULL){
// 			return NULL;
// 		}


// 		int countA = 0;
// 		for(ListNode* currA = headA; currA->next!=NULL; currA=currA->next){
// 			countA++;
// 		}
// 		int countB = 0;
// 		for(ListNode* currB = headB; currB->next!=NULL; currB=currB->next){
// 			countB++;
// 		}

// 		int diff = abs(countA-countB);
// 		if(countA > countB){
// 			while(diff--){
// 				headA=headA->next;
// 			}
// 		}
// 		else if(countB > countA){
// 			while(diff--){
// 				headB=headB->next;
// 			}
// 		}
// 		while(headA!=headB){
// 				headA=headA->next;
// 				headB=headB->next;
// 		}
// 		return headA;








		
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode *pA = headA;
        // ListNode *pB = headB;
        // while (pA != pB) {
        //     pA = pA == nullptr ? headB : pA->next;
        //     pB = pB == nullptr ? headA : pB->next;
        // }
        // return pA;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA!=pB){
            pA = pA == NULL ? headB: pA->next;
            pB = pB == NULL ? headA: pB->next;

        }
        return pA;

        // Note: In the case lists do not intersect, the pointers for A and B
        // will still line up in the 2nd iteration, just that here won't be
        // a common node down the list and both will reach their respective ends
        // at the same time. So pA will be NULL in that case.
    }
};











// 	}
// };