#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Play {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *n = head, **h = &head;
        while(n && n->next) {
            *h = n->next;
            n->next = n->next->next;
            (*h)->next = n;
            h = &(n->next);
            n = n->next;
        }
        return head;
    }
};

int main() {
    ListNode A(1),B(2),C(3),D(4),E(5);
    A.next = &B, B.next = &C, C.next = &D, D.next = &E;

    ListNode *r = &A;
    Play pp;
    r = pp.swapPairs(r);
    while(r) {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
    return 0;
}
