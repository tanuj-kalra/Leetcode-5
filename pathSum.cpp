#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node {
    int val;
    Node *l; 
    Node *r;
    Node(int x) : val(x), l(NULL), r(NULL) {}
};

class Play {
public:
    int maxPathSum(Node *h) {
        int m = h->val;
        stack<Node *> ss;
        stack<int> ms;
        Node *ret = NULL;
        while(h || !ss.empty()) {
            if(h) {
                ss.push(h);
                h = h->l;
                continue;
            }
            h = ss.top();
            if(NULL == h->r || ret == h->r) {
                int mr = 0, ml = 0;
                if(h->r) { mr = max(ms.top(), 0); ms.pop();}
                if(h->l) { ml = max(ms.top(), 0); ms.pop();}
                m = max(m, h->val + mr + ml);
                ms.push(h->val + max(mr, ml));
                ret = h;
                h = NULL;
                ss.pop();
            }
            else
                h = h->r;
        }
        return m;
    }

    int maxPathSII(Node *h) {
        int m = h->val;
        int res = helper(h, m);
        return m;
    }

    int helper(Node *h, int &m) {
        if(NULL == h) return 0;
        int ml = max(helper(h->l, m), 0);
        int mr = max(helper(h->r, m), 0);
        m = max(m, h->val + mr + ml);
        return h->val + max(mr, ml);
    }

    bool pathSum(Node *h, int sum) {
        /* check if theres a root-leaf path sum up to SUM */
        if(h == 0)
            return false;
        sum -= h->val;
        if(h->l == 0 && h->r == 0 && sum == 0)
            return true;
        return pathSum(h->l, sum) || pathSum(h->r, sum);
    }

    vector<vector<int> > pathSumII(Node *h, int sum) {
        vector<vector<int> > v;
        vector<int> st;
        sumHelper(h, sum, v, st);
        return v;
    }

    void sumHelper(Node *h, int sum, 
            vector<vector<int> > &v, vector<int> &st) {
        if(h == 0)
            return;
        sum -= h->val;
        if(h->l == 0 && h->r == 0 && sum == 0) {
            st.push_back(h->val);
            v.push_back(st);
            st.pop_back();
        }
        st.push_back(h->val);
        sumHelper(h->l, sum, v, st);
        sumHelper(h->r, sum, v, st);
        st.pop_back();
    }

};

int main() {
    Node A = Node(-2);
    Node B = Node(1);
    Node C = Node(4);
    Node D = Node(-3);
    Node E = Node(4);

    A.l = &B, A.r = &C;
    C.l = &D;
    D.r = &E;

    Node *h = &A;
    Play pp;
    cout << pp.maxPathSum(h) << '\n';
    cout << pp.maxPathSII(h) << '\n';

    if(pp.pathSum(h, 3))
        cout << "Is path sum \n";

    vector<vector<int> > v = pp.pathSumII(h, 3);
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
