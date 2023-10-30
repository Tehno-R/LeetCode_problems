#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* newList = new ListNode();
        ListNode* cur = newList;
        if (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                cur->val = list2->val;
                list2 = list2->next;
            } else {
                cur->val = list1->val;
                list1 = list1->next;
            }
            while (list1 != nullptr && list2 != nullptr) {
                if (list1->val > list2->val) {
                    cur->next = new ListNode(list2->val);
                    cur = cur->next;
                    list2 = list2->next;
                } else {
                    cur->next = new ListNode(list1->val);
                    cur = cur->next;
                    list1 = list1->next;
                }
            }
            if (list1 != nullptr) {
                while (list1 != nullptr) {
                    cur->next = new ListNode(list1->val);
                    cur = cur->next;
                    list1 = list1->next;
                }
            } else {
                while (list2 != nullptr) {
                    cur->next = new ListNode(list2->val);
                    cur = cur->next;
                    list2 = list2->next;
                }
            }
        } else {
            if (list1 != nullptr) {
                cur->val = list1->val;
                list1 = list1->next;
                while (list1 != nullptr) {
                    cur->next = new ListNode(list1->val);
                    cur = cur->next;
                    list1 = list1->next;
                }
            } else {
                cur->val = list2->val;
                list2 = list2->next;
                while (list2 != nullptr) {
                    cur->next = new ListNode(list2->val);
                    cur = cur->next;
                    list2 = list2->next;
                }
            }
        }

        return newList;
    }
};
int main() {
//    ListNode* list1 = new ListNode(1,new ListNode(2,new ListNode(4)));
//    ListNode* list2 = new ListNode(1,new ListNode(3,new ListNode(4)));
//    ListNode* list1 = nullptr;
//    ListNode* list2 = nullptr;
    ListNode* list1 = new ListNode(1,new ListNode(5));
    ListNode* list2 = nullptr;
    Solution sol;
    ListNode* res = sol.mergeTwoLists(list1, list2);
    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
