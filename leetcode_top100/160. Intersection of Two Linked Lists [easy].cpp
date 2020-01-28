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
  struct pointer {
    ListNode *node = nullptr;
    bool has_changed_list = false;
  };

  ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr || l2 == nullptr) return nullptr;
    pointer a{l1}, b{l2};
    while (a.node && b.node) {
      if (a.node == b.node) return a.node;
      if (!a.node->next && !a.has_changed_list)
        a = {l2, true};
      else
        a.node = a.node->next;
      if (!b.node->next && !b.has_changed_list)
        b = {l1, true};
      else
        b.node = b.node->next;
    }
    return nullptr;
  }
};