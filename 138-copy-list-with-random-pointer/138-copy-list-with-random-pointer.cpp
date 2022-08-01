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
//     // Insert the deep copy nodes
//     Node *itr=head;
//     Node *front=head;
//     while(itr!=NULL){
//         Node *copy=new Node(itr->val);
//         itr->next=copy;
//         copy->next=front;
//         itr=front;
//     }   
//         // Step 2
//         // Connect the random pointers
//         itr=head;
//         while(itr!=NULL){
//             if(itr->random!=NULL){
//             itr->next->random=itr->random->next;
//         }
//             itr=itr->next->next;
//         }
//         // Step 3 separating the original linked list and the deep copy
//         Node *dummy=new Node(0);
//         Node *pseudoHead=dummy;
    
//         itr=head;
//         while(itr!=NULL){
//             front=itr->next->next;
//             pseudoHead->next=itr->next;
//             itr->next=front;
//             pseudoHead=pseudoHead->next;
//             itr=itr->next;
//         }
//         return dummy->next;
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;

          while (iter != NULL) {
            front = iter->next->next;

            // extract the copy
            copy->next = iter->next;

            // restore the original list
            iter->next = front;
              
            copy = copy -> next; 
            iter = front;
          }

          return pseudoHead->next;
    }
};