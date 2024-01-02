#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main(void)
{
    ListNode* list = new ListNode(1);
    ListNode* curr = list;
    for (int i = 2; i < 6; ++i) {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    Solution solution;
    solution.reverseList(list);
    ListNode* tmp = list;
    while (list != nullptr) {
        tmp = list;
        list = list->next;
        delete tmp;
    }
    return 0;
}