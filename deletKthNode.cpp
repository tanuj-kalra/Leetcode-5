#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode() : val(0), next(NULL) {}
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *h, int n) {
        ListNode *p1 = h, *p2 = h;
        while(n-- > 0)
            p2 = p2->next;
        if(NULL == p2)
            return h->next;
        p2 = p2->next;
        while(p2 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return h;
    }

    void print(ListNode *h) {
        while(h != NULL) {
            cout << h->val << " ";
            h = h->next;
        }
        cout << '\n';
    }
};

int main() {
    int n = 20;
    ListNode *h = new ListNode[n];
    for(int i = 0; i<n; i++) {
        h[i].next = h + i + 1;
        h[i].val = i;
    }
    h[n-1].next = NULL;

    Solution pp;
    pp.print(h);

    ListNode *t = pp.removeNthFromEnd(h, 15);
    pp.print(t);

    delete [] h;
    return 0;
}
