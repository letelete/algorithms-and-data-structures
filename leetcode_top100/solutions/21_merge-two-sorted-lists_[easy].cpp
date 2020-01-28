/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) {
      return l1 == nullptr ? l2 : l1;
    }

    ListNode *head, *trav;

    if (l1->val <= l2->val) {
      head = l1;
      l1 = l1->next;
    } else {
      head = l2;
      l2 = l2->next;
    }

    trav = head;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val <= l2->val) {
        trav->next = l1;
        l1 = l1->next;
      } else {
        trav->next = l2;
        l2 = l2->next;
      }
      trav = trav->next;
    }

    if (l1 != nullptr) {
      trav->next = l1;
    }
    if (l2 != nullptr) {
      trav->next = l2;
    }

    return head;
  }
};