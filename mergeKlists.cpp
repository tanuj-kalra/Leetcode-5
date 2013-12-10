#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

class Play {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return 0;
        int n = lists.size();
        while(n > 1) {
            int i;
            for(i = 0; i < n/2; ++i)
                lists[i] = mergeTwoList(lists[2*i], lists[2*i+1]);
            if(n % 2) {
                lists[i] = lists[n-1];
                n = n/2 + 1;
            } else
                n = n/2;
        }
        return lists[0];
    }

    ListNode *mergeTwoList(ListNode *s, ListNode *t) {
        ListNode *h, **c = &h;
        while(s && t) {
            if(s->val < t->val) {
                *c = s;
                s = s->next;
            } else {
                *c = t;
                t = t->next;
            }
            c = &(*c)->next;
        }
        if(s) 
            *c = s;
        else 
            *c = t;
        return h;
    }
};

int main() {
    Play pp;
    vector<ListNode *> l;
    ListNode *t, **h;
    int p = 1000, c = 0;
    while(cin >> c) {
        if(c == 0)
            break;
        if(c < p) {
            t = new ListNode(c);
            l.push_back(t);
            h = &t->next;
            p = c;
        } else {
            *h = new ListNode(c);
            h = &(*h)->next;
            p = c;
        }
    }

    t = pp.mergeKLists(l);
    while(t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;

    return 0;
}

