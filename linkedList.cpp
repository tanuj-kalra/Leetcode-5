#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
};

class Solution {
public:
    ListNode *findMid(ListNode *h) {
        ListNode *m = h;
        while(NULL != h){
            h = h->next;
            if(NULL != h)
                h = h->next;
            else 
                break;
            m = m->next;
        }
        return m;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if((k < 2) || (NULL == head)) return head;
        ListNode *t = head;
        int i = 1;
        while((t=t->next) != NULL)
            ++i;
        i /= k;
        ListNode **h = &head;
        while (i-- > 0)
            h = revK(h, k);
        return head;
    }

    ListNode **revK(ListNode **h, int k) {
        ListNode *t = *h, *c = t->next;
        while(--k > 0) {
            t->next = c->next;
            c->next = *h;
            *h = c;
            c = t->next;
        }
        return &(t->next); // This is the tail.
    }

    ListNode *reverseTwo(ListNode *head, int m, int n) {
        n = n - m;
        ListNode **h = &head;
        while((--m)>0) 
                h = &((*h)->next);
        ListNode *t, *c;
        t = *h;
        c = t->next;
        while((n--)>0) {
            t->next = c->next;
            c->next = *h;
            *h = c;
            c = t->next;
        }
        return head;
    }

    ListNode *rotateRight(ListNode *head, int k) {
        if (NULL == head) return head;
        ListNode *h, *t;
        h = head;
        t = head;
        while((k--) > 0) {
            t = t->next;
            if(NULL == t) 
                t = head;
        }
        while(NULL != t->next) {
            h = h->next;
            t = t->next;
        }
        t->next = head;
        head = h->next;
        h->next = NULL;
        return head;
    }

    ListNode *rotateLeft(ListNode *head, int k) {
        if (NULL == head) return head;
        if (k <= 0) return head;
        ListNode *h, *t;
        h = head;
        while((--k) > 0) {
            h = h->next;
            if(NULL == h)
                h = head;
        }
        if ((NULL == h->next)) return head;
        t = h->next;
        while(NULL != t->next)
            t = t->next;
        t->next = head;
        head = h->next;
        h->next = NULL;
        return head;
    }

    void printNode(ListNode *h) {
        if (NULL == h) return;
        cout << "List: " << h->val << " ";
        while(NULL != (h = h->next)) 
            cout << h->val << " ";
        cout << '\n';
    }
};

int main() {
    int n = 15;
    ListNode *nodes = new ListNode[n+1];
    int i;
    for(i=0; i< n; ++i) {
        nodes[i].val = i + 1;
        nodes[i].next = nodes + i + 1;
    }
    nodes[n].val = n + 1;

    Solution pp;
    pp.printNode(nodes);
    ListNode *head = pp.rotateRight(nodes, 0);
    pp.printNode(head);
    head =  pp.rotateLeft(head, 0);
    pp.printNode(head);
    head = pp.reverseKGroup(head, 5);
    pp.printNode(head);
    head = pp.reverseTwo(head, 4, 4);
    pp.printNode(head);
    cout << (pp.findMid(head))->val << '\n';

    delete [] nodes;

    return 0;
}

