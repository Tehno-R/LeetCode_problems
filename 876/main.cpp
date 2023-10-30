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
    ListNode* middleNode(ListNode* head) {
        ListNode* mid = head;
        ListNode* tail = head;
        while (tail != NULL) {
            if (tail->next) {
                tail = tail->next->next;
                mid = mid->next;
            }
            else tail = tail->next;
        }
        return mid;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
