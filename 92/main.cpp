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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftptr = head;
        for (int i = 0; i < left; ++i) {
            leftptr = leftptr->next;
        }
        ListNode* rightptr = leftptr;
        for (int i = left; i < right; ++i) {
            rightptr = rightptr->next;
        }
        short n = right - left;
        if ((leftptr != nullptr) && (rightptr != nullptr)) {
            // 1 2 3 4 5 6
            if (n % 2 == 0) {
                ListNode* mid = leftptr;
                for (int i = 0; i < n/2; ++i) {
                    mid = mid->next;
                }
                for (int i = 1; i <= n/2; ++i) {
                    ListNode* temp = leftptr;
                    int tempval;
                    for (int j = 0; j < n/2-i; ++j) {
                        temp = temp->next;
                    }
                    tempval = mid->val;
                    mid->val = temp->val;
                    temp->val = tempval;
                    mid = mid->next;
                }
            } else {
                // 1 2 3 4 5 6 7
                ListNode* mid = leftptr;
                for (int i = 0; i < n/2 + 1; ++i) {
                    mid = mid->next;
                }
                for (int i = 1; i <= n/2; ++i) {
                    ListNode* temp = leftptr;
                    int tempval;
                    for (int j = 0; j < n/2-i; ++j) {
                        temp = temp->next;
                    }
                    tempval = mid->val;
                    mid->val = temp->val;
                    temp->val = tempval;
                    mid = mid->next;
                }
            }
        }
        return head;
    }
};

int main() {
    return 0;
}
