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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) return nullptr;

    ListNode* answer_head = new ListNode(0);
    ListNode* trav = answer_head;

    int additional_value = 0;
    while (l1 || l2 || additional_value) {
      trav->next = new ListNode(0);
      trav = trav->next;

      int sum = additional_value;

      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }

      if (sum >= 10) {
        additional_value = 1;
        sum %= 10;
      } else {
        additional_value = 0;
      }

      trav->val = sum;
    }

    return answer_head->next;
  }
};