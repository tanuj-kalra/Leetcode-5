#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Play {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *tail, **t = &tail, **h = &head;
        while(*h) {
            if((*h)->val >= x) {
                *t = *h;
                t = &(*t)->next;
                *h = (*h)->next;
            } else {
                h = &(*h)->next;
            }
        }
        *t = 0;
        *h = tail;
        return head;
    }
};

void printList(ListNode *h) {
    while(h) {
        cout << h->val << " ";
        h = h->next;
    }
    cout << endl;
}

int main() {
    Play pp;
    ListNode *head, **h = &head;
    int x, t;
    cin >> x;
    while(cin >> t) {
        *h = new ListNode(t);
        h = &(*h)->next;
    }
    
    head = pp.partition(head, x);
    printList(head);

    return 0;
}
