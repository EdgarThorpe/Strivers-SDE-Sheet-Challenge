/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Method - 1: Hashmap
        unordered_map<Node*, Node*>hm;
        for(Node *curr = head; curr!=NULL; curr=curr->next){
            hm[curr] = new Node (curr->val);
        }   
        for(Node *curr = head; curr!=NULL; curr=curr->next){
            hm[curr]->next = hm[curr->next];
            hm[curr]->random = hm[curr->random];
        }
        return hm[head];   
    }

    // Method - 2: 
};