#include<iostream>
using namespace std;

struct IntNode {
    int a;
    int b;
    IntNode *next;
    IntNode(int low, int high) : a(low), b(high), next(NULL) {}
};

struct HeadsNode {
    IntNode *list;
    HeadsNode *next;
    HeadsNode() : next(NULL) {}
};

class MergeInt {
public:

     void merger(HeadsNode *h, HeadsNode *t) {
        if(h == t) return;
        HeadsNode *mid = middle(h,t);
        merger(h, mid);
        merger(mid->next, t);

        h->list = mergeTwoList(h->list, (mid->next)->list);
        h->next = t->next;
    }

    IntNode * mergeTwoList(IntNode *l1, IntNode *l2) {
        IntNode *r;
        IntNode **h = &r;
        while(l1 != NULL && l2 != NULL) {
            if(l1->b < l2->a){
                *h = l1;
                l1 = l1->next;
                h = &(*h)->next;
            } else if(l2->b < l1->a) {
                *h = l2;
                l2 = l2->next;
                h = &(*h)->next;
            } else if(l1->b > l2->b) {
                l1->a = min(l1->a, l2->a);
                l2 = l2->next;
            } else {
                l2->a = min(l1->a, l2->a);
                l1 = l1->next;
            }
        }
        if(l1 == NULL)
            *h = l2;
        else
            *h = l1;
        return r;
    }

    HeadsNode *middle(HeadsNode *h, HeadsNode *t) {
        HeadsNode *p1 = h, *p2 = h->next;
        while(p2 != t) {
            p1 = p1->next;
            p2 = p2->next;
            if(p2 != t)
                p2 = p2->next;
            else
                break;
        }
        return p1;
    }

    void printInts(IntNode *h) {
        while(h!= NULL){
            cout << h->a << ", " << h->b << "  ";
            h = h->next;
        }
        cout << '\n';
    }
};

int main() {
    HeadsNode A[4];
    for(int i = 0; i < 4 - 1; ++i) {
        A[i].next = A + i + 1;
    }
    IntNode **t = &(A[0].list);
    *t = new IntNode(1,2);
    t = &(*t)->next;
    *t = new IntNode(7,9);
    t = &(*t)->next;
    *t = new IntNode(10,13);
    t = &(A[1].list);
    *t = new IntNode(1,3);
    t = &(*t)->next;
    *t = new IntNode(4,5);
    t = &(A[2].list);
    *t = new IntNode(8,12);
    t = &(A[3].list);
    *t = new IntNode(16,20);

    MergeInt pp;
    pp.merger(A, A+3);
    pp.printInts(A[0].list);
    return 0;
}
    
