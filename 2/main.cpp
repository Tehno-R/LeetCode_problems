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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* it1 = l1;
        ListNode* it2 = l2;
        bool flag = false;
        while (it1->next && it2->next) {
            it1->val += it2->val;
            if (flag) {
                it1->val += 1;
                flag = false;
            }
            if (it1->val > 9) {
                it1->val %= 10;
                flag = true;
            }
            it1 = it1->next;
            it2 = it2->next;
        }
        //
        if (!(it1->next)) it1->next = it2->next;
        it1->val += it2->val;
        if (flag) {
            it1->val += 1;
            flag = false;
        }
        if (it1->val > 9) {
            it1->val %= 10;
            flag = true;
        }
        while (it1->next) {
            it1 = it1->next;
            if (flag) {
                it1->val += 1;
                flag = false;
            }
            if (it1->val > 9) {
                it1->val %= 10;
                flag = true;
            }
        }
        if (flag) it1->next = new ListNode(1);
        return l1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
