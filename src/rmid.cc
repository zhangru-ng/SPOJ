// http://www.spoj.com/problems/RMID/

#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int v) : val(v), prev(NULL), next(NULL) {}
};

class List {
private:
    ListNode* head;
    ListNode* tail;
    int size_;
public:
    List() : head(new ListNode(0)), size_(0), tail(new ListNode(0)) {
        head->next = tail;
        tail->prev = head;
    }

    ~List() {
        clean(head);
    }

    void clean(ListNode* n) {
        if (!n) {
            return;
        }
        clean(n->next);
        delete n;
    }

    void push_back(int v) {
        size_++;
        ListNode* n = new ListNode(v);
        n->prev = tail->prev;
        tail->prev->next = n;
        n->next = tail;
        tail->prev = n;
    }

    void erase(ListNode* n) {
        size_--;
        n->prev->next = n->next;
        n->next->prev = n->prev;
        delete n;
    }

    int size() {
        return size_;
    }

    bool empty() {
        return size_ == 0;
    }

    ListNode* first() {
        return head->next;
    }

    void clear() {
        clean(head);
        head = new ListNode(0);
        size_ = 0;
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
    }
};

int main() {
    int n;
    List data;
    ListNode* med_ptr = NULL;
    int pos = 0;
    int size = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            data.clear();
            med_ptr = data.first();
            size = 0;
            pos = 0;
            printf("\n");
        } else if (n == -1) {
            int med = med_ptr->val;
            ListNode* temp = med_ptr;
            if (pos > data.size() / 2) {
                med_ptr = med_ptr->prev;
                --pos;
            } else {
                med_ptr = med_ptr->next;
            }
            data.erase(temp);
            printf("%d\n", med);
        } else if (data.empty()) {
            data.push_back(n);
            pos = 1;
            med_ptr = data.first();
        } else {
            data.push_back(n);
            if (pos < (data.size()+1) / 2) {
                ++pos;
                med_ptr = med_ptr->next;
            }
        }
    }
    return 0;
}
