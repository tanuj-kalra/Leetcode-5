#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL) {}
};

class Solution {
public:
    ListNode * mergeTwoList(ListNode *l1, ListNode *l2) {
        ListNode *h = NULL;
        ListNode **p = &h;
        while(l1 && l2) {
            if(l1->val < l2->val){
                *p = l1;
                l1 = l1->next;
            }
            else {
                *p = l2;
                l2 = l2->next;
            }
            p = &((*p)->next);
        }
        if(l1) *p = l1;
        else *p = l2;
        return h;
    }

    void printList(ListNode *h) {
        while(h) {
            cout << h->val << "  ";
            h = h->next;
        }
        cout << '\n';
    }
};

int main() {
    ListNode *a = new ListNode[5];
    ListNode *b = new ListNode[4];
    a[0].val = 3, a[1].val = 6, a[2].val = 8, a[3].val = 10, a[4].val = 12;
    b[0].val = 2, b[1].val = 4, b[2].val = 5, b[3].val = 11;
    int i;
    for(i=0;i<4; i++)
        a[i].next = a+i+1;
    for(i=0;i<3; i++)
        b[i].next = b+i+1;

    Solution pp;
    pp.printList(a);
    pp.printList(b);
    ListNode *h = pp.mergeTwoList(a,b);
    pp.printList(h);

    return 0;
}
                
                
