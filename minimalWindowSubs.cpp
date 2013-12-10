#include<iostream>
using namespace std;

struct Node {
    char c;
    int pos;
    Node *next;
    Node *prev;
    Node(char w, int p) : c(w), pos(p), next(NULL), prev(NULL) {}
};

class L {
private:
    Node *sentry;
    int len;
public:
    L() {
        len = 0;
        sentry = new Node(0,-1);
        sentry->next = sentry;
        sentry->prev = sentry;
    }

    ~L() {
        while(sentry->next != sentry) {
            del(head());
        }
        delete sentry;
    }

    void del(Node *n) {
        (n->prev)->next = n->next;
        (n->next)->prev = n->prev;
        len--;
        delete n;
    }

    void push(Node *n) {
        n->next = sentry;
        n->prev = sentry->prev;
        (sentry->prev)->next = n;
        sentry->prev = n;
        len++;
    }

    Node *head() {return sentry->next;}
    Node *tail() {return sentry->prev;}
    int size() {return len;}
    void update(char w, int pos) {
        Node *t = head();
        sentry->c = w;
        while(t->c != w)
            t = t->next;
        if(t != sentry) 
            del(t);
        t = new Node(w, pos);
        push(t);
    }
};

class Play {
public:
    string minWindow(string S, string T) { // linked list solution when T no reapeat
        string F;
        L *l = new L;
        int p = -1, q = S.size();
        for(int i = 0; i < S.size(); ++i) {
            int j = 0;
            bool found = false;
            for(; j < T.size(); ++j)
                if(S[i] == T[j]) {
                    found = true;
                    break;
                }
            if(found) {
                l->update(S[i], i);
                if((l->size() == T.size()) && l->tail()->pos - l->head()->pos
                                <= q-p) {
                        q = l->tail()->pos;
                        p = l->head()->pos;
                }
            }
        }
        if(p != -1)
            while(p <= q)
                F += S[p++];
        delete l;
        return F;
    }

    string minWin(string S, string T) {
        int A[128] = {};
        int B[128] = {};
        for(int i = 0; i < T.size(); ++i)
            B[T[i]]++;
        int rs = -1, re = S.size(), s = 0, len = 0;
        for(int i = 0; i < S.size(); ++i) {
            if(++A[S[i]] <= B[S[i]]) 
                ++len;
            if(len == T.size()) {
                while(A[S[s]] > B[S[s]])
                    --A[S[s++]];
                if(i - s < re - rs) {
                    rs = s, re = i;
                }
            }
        }
        string F;
        if(rs != -1)
            while(rs <= re)
                F += S[rs++];
        return F;
    }
};

int main() {
    string S("adobecodebanc");
    string T("abc");
    Play pp;

    string F = pp.minWindow(S,T);
    cout << F << '\n';

    S = "acbdbaab";
    T = "aabd";
    F = pp.minWin(S,T);
    cout << F << '\n';

    return 0;
}
