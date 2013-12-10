#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL) {}
};

class Solution {
public:
    ListNode * removeDuplicate(ListNode *h){
        ListNode *u, *v = h;
        while(v) {
            u = v;
            while(v && (v->val == u->val))
                v = v->next;
            u->next = v;
        }
        return h;
    }
    
    ListNode * delDuplicate(ListNode *h){
        ListNode ** p = &h;
        while(*p) {
            ListNode *t = *p;
            int ct = 0;
            while(t->next && (*p)->val == (t->next)->val){
                t = t->next;
                ct ++;
            }
            if(ct)
                *p = t->next;
            else p = &(t->next);
        }
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
    a[0].val = 1, a[1].val = 2, a[2].val = 2, a[3].val = 3, a[4].val = 3;
    int i;
    for(i=0;i<4; i++)
        a[i].next = a+i+1;

    Solution pp;
    pp.printList(a);
    ListNode *h = pp.removeDuplicate(a);
    pp.printList(h);
    int preb[] = {2,2,2,3,4,4,5,6,6,6,7,8,8,9};
    int n = sizeof(preb)/sizeof(int);
    ListNode *b = new ListNode[n];
    for(i=0; i < n-1; i++){
        b[i].next = b+i+1;
        b[i].val = preb[i];
    }
    b[n-1].val = preb[n-1];
    pp.printList(b);
    h = pp.delDuplicate(b);
    pp.printList(h);

    return 0;
}
                
                
