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
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *runner = head->next, *walker = head;
    int step = 1;
    while (runner->next != nullptr) {
      if (step % 2 == 0) {
        walker = walker->next;
        runner = runner->next;
      } else if (step % 2) {
        runner = runner->next;
      }
      ++step;
      if (runner == walker) return true;
    }
    return false;
  }
};