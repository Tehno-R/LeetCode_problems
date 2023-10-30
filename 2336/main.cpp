#include <iostream>
using namespace std;

struct LinkedList{
public:
    int value;
    LinkedList* next;
    LinkedList* prev;

    LinkedList(int val = 0, LinkedList* n = nullptr, LinkedList* p = nullptr) {
        this->value = val;
        this->next = n;
        this->prev = p;
    }

    void Add(int val, int ind = -1) {
        LinkedList* cur = this;
        bool last = false;
        if (ind != -1) { // индекс указан
            int i = 0;
            for (; cur->next != nullptr; ++i) {
                cur = cur->next;
            }
            if (i < ind) last = true;
            if (last) cur->next = new LinkedList(val, nullptr, cur); // в конец
            else if (cur->prev != nullptr) {
                cur->prev->next = new LinkedList(val, cur, cur->prev); // не в конец
                cur->prev = cur->prev->next;
            } else { // в начало
                cur->next = new LinkedList(cur->value, cur->next, cur);
                if (cur->next->next != nullptr) cur->next->next->prev = cur->next;
                cur->value = val;
            }
        } else { // индекс не указан, значит в конец
            while (cur->next != nullptr) cur = cur->next;
            cur->next = new LinkedList(val, nullptr, cur);
        }
    }
    void Pop(int ind) {
        LinkedList* cur = this;
        if (ind != -1) {
            for (int i = 0; i < ind && cur->next != nullptr; ++i) cur = cur->next;
            if (cur->prev != nullptr && cur->next != nullptr) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            } else if (cur->next != nullptr) {
                LinkedList* temp = cur->next;
                cur->value = cur->next->value;
                cur->next = cur->next->next;
                delete temp;
            } else if (cur->prev != nullptr) {
                cur->prev->next = nullptr;
                delete cur;
            } else {
                delete cur;
            }
        }
    }
};

class SmallestInfiniteSet {
public:

    SmallestInfiniteSet() {

    }

    int popSmallest() {

    }

    void addBack(int num) {

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


int main() {
//    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
//    int param_1 = obj->popSmallest();
//    obj->addBack(param_1);
    LinkedList* ll = new LinkedList(5);
//    ll->Add(7,0);
//    ll->Add(6, 1);
//    ll->Add(10,2);
    ll->Pop(0);
    cout << (ll == NULL) << endl;
    return 0;
}
