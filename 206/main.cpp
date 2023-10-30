#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* foo(ListNode* cur, ListNode* prev) {
        if (cur->next) {
            ListNode* res = foo(cur->next, cur);
            cur->next = prev;
            return res;
        } else {
            cur->next = prev;
            return cur;
        }
   }

    ListNode* reverseList(ListNode* head) {
        return foo(head, nullptr);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
