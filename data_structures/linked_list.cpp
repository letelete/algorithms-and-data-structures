#include <bits/stdc++.h>

struct Node {
  int val;
  Node* next = nullptr;
};

/* prints linked list content */
void print(Node* head) {
  if (!head) {
    std::cout << "[]\n";
    return;
  }
  while (head) {
    std::cout << head->val << (head->next ? " -> " : "\n");
    head = head->next;
  }
}

/* pushes given val on front of the linked list */
void push(Node** head_ref, int val) {
  Node* new_node = new Node();
  new_node->val = val;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/*
Write a function to get Nth node in a Linked List
Write a GetNth() function that takes a linked list
and an integer index and returns the data value stored
in the node at that index position.
*/
Node* get_nth(Node* head, int index) {
  if (index < 0) return nullptr;
  Node* trav = head;
  int i{0};
  while (trav && i < index) {
    trav = trav->next;
    i++;
  }
  if (i != index) return nullptr;
  return trav;
}

/*
How do you find the middle element of a singly linked list in one pass
*/
Node* get_middle(Node* head) {
  if (head == nullptr) return nullptr;
  if (head->next == nullptr) return head;
  Node *runner = head, *walker = head;
  while (runner && runner->next) {
    walker = walker->next;
    runner = runner->next->next;
  }
  return walker;
}

/*
Program for n’th node from the end of a Linked List
Given a Linked List and a number n, write a function
that returns the value at the n’th node from the end
of the Linked List.

For example, if the input is below list and n = 3,
then output is “B”
A -> B -> C -> D -> NULL
*/
int value_at(Node* head, int from_end) {
  if (head == nullptr) return -1;
  std::stack<int> nodes;
  Node* trav = head;
  while (trav != nullptr) {
    nodes.push(trav->val);
    trav = trav->next;
  }
  while (--from_end && !nodes.empty()) nodes.pop();
  return nodes.empty() ? -1 : nodes.top();
}

/*
Write a function to delete a Linked List
Algorithm For C/C++: Iterate through the linked list
and delete all the nodes one by one. Main point here
is not to access next of the current pointer if
current pointer is deleted.
*/
void delete_list(Node** head_ref) {
  Node *curr = *head_ref, *next = nullptr;
  while (curr) {
    next = curr->next;
    delete (curr);
    curr = next;
  }
  *head_ref = nullptr;
}

/*
How will you detect loop in singly linked list?
*/
bool detect_loop(Node* head) {
  if (head == nullptr) return false;
  Node *fast = head, *slow = head;
  bool has_cycle = false;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      has_cycle = true;
      break;
    }
  }
  return has_cycle;
}

/*
Given pointers to two single-linked list,
find out if they intersect and at
which node they intersect.

a - b - c
          \
            d - e
    x - y /

d is intersection.
*/
struct pointer {
  Node* node = nullptr;
  bool has_changed_list = false;
};

Node* get_intersection(Node* l1, ListNode* l2) {
  if (l1 == nullptr || l2 == nullptr) return nullptr;
  pointer a{l1}, b{l2};
  while (a.node && b.node) {
    if (a.node == b.node) return a.node;
    if (!a.node->next && !a.has_changed_list) a = {l2, true};
    else a.node = a.node->next;
    if (!b.node->next && !b.has_changed_list) b = {l1, true};
    else b.node = b.node->next;
  }
  return nullptr;
}

/*
Merge two unsorted  linked list in efficient way
*/

/*
Remove and append last N elements of linked list to beginning of list.
ex. 1->2->3->4->5->6->7->8
if N=3, output would be:
6->7->8->1->2->3->4->5
*/

/*
Delete repeated elements from linked list in O(n) time without using extra
space.
*/

/*
How do you reverse a linked list?
*/

int main() {
  Node* head_odd = nullptr;
  Node* head_even = nullptr;

  std::vector<int> odd{{5, 4, 3, 2, 1}};
  std::vector<int> even{{5, 4, 3, 2, 1, 0}};

  for (const int& n : odd) push(&head_odd, n);
  for (const int& n : even) push(&head_even, n);

  std::cout << "Origin linked list with odd length: ";
  print(head_odd);
  std::cout << "Origin linked list with even length: ";
  print(head_even);

  std::cout << "1. get_nth (4): " << get_nth(head_odd, 4)->val << "\n";
  std::cout << "2. get_middle: "
            << "\n a) odd elements case: " << get_middle(head_odd)->val << "\n"
            << " b) even elements case: " << get_middle(head_even)->val << "\n";
  std::cout << "3. value_at(1): " << value_at(head_odd, 1) << "\n";

  std::cout << "Linked list before deletion: ";
  print(head_even);
  delete_list(&head_even);
  std::cout << "Linked list after deletion: ";
  print(head_even);

  for (const int& n : even) push(&head_even, n);
  std::cout << "New list initialization: ";
  print(head_even);

  Node* loop_head = new Node{1};
  loop_head->next = new Node{2};
  loop_head->next->next = new Node{3};
  loop_head->next->next = loop_head->next;
  std::cout << "4. Detect loop: "
            << "\n a) Loop head passed: " << detect_loop(loop_head)
            << "\n b) No loop passed: " << detect_loop(head_even) << "\n";

  Node* intersection_head = new Node{1, new Node{2}};
  Node* pre_intersection_a =
      new Node{1, new Node{2, new Node{3, intersection_head}}};
  Node* pre_intersection_b =
      new Node{0, new Node{-1, new Node{-3, intersection_head}}};
  std::cout << "5. Get intersection(val == 1 is a head of intersection): "
            << get_intersection(pre_intersection_a, pre_intersection_b)->val
            << "\n";
}