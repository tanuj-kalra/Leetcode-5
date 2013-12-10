#include<iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
    Node() : val(0), next(NULL) {}
};

Node * corruptHead(Node *h) {
    Node *p1 = h, *p2 = h;
    while(p2->next != NULL) {
        p1 = p1->next;
        p2 = (p2->next)->next;
        if(p1 == p2)
            break;
    }
    if(p2 == NULL)
        return NULL;
    p1 = h;
    while(p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

void printList(Node *h, int n) {
    for(; n > 0; n--) {
        cout << " " << h->val << "->" 
            << (h->next)->val << " ";
        h = h->next;
    }
    cout << '\n';
}

int main() {
    int n = 28;
    Node *h = new Node[n];
    int i;
    for(i=0; i < n-1; i++) {
        h[i].next = h + i + 1;
        h[i].val = i;
    }
    h[n-1].val = n - 1;
    h[n-1].next = h + 8; //corrupt the Linked list
    printList(h, n);
    Node *p = corruptHead(h);
    cout << p->val <<'\n';

    return 0;
}


