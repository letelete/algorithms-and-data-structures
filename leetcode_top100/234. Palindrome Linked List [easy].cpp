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
    bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) { return true; }
    ListNode* trav = head;
    std::stack<ListNode*> lifo_head;
    while (trav) {lifo_head.push(trav); trav = trav->next;}
    while (head && head->val == lifo_head.top()->val) {
        head = head->next;
        lifo_head.pop();
    }
    return lifo_head.empty();
    }
};