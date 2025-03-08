#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {


 // base case
 if (head == nullptr) {
   smaller = nullptr;
   larger = nullptr;
   return;
 }


 // detatch current node, save ptr to future nodes in head
 Node* temp_next = head->next;
 head->next = nullptr;


 // recur until tail
 llpivot(temp_next, smaller, larger, pivot);


 // if val < pivot, append to smaller array and update head
 if (head->val <= pivot) {
   if (smaller == nullptr) {
     smaller = head;
   } else {
     head->next = smaller;
     smaller = head;
   }
 }


 // if val > pivot, append to larger array and update head
 else if (head->val > pivot) {
   if (larger == nullptr) {
     larger = head;
   } else {
     head->next = larger;
     larger = head;
   }
 }


   head = nullptr;
}