#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

struct Node {
    char val;
    Node *l;
    Node *r;
    Node(char c) : val(c), l(NULL), r(NULL) {}
};

class Play {
public:
    void inOrderRecur(Node *h) {
        if (NULL == h) return;
        inOrderRecur(h->l);
        cout << " " << h->val << " ";
        inOrderRecur(h->r);
    }

    void inOrderStack(Node *h) {
        stack<Node *> ss;
        Node *cur = h;
        while(1) {
            if(NULL != cur) {
                ss.push(cur);
                cur = cur->l;
            }
            else {
                if(!ss.empty()) {
                    cur = ss.top();
                    ss.pop();
                    cout << " " << cur->val << " ";
                    cur = cur->r;
                }
                else
                    break;
            }
        }
    }

    void inOrderNoStack(Node *h) { 
        // Morris Traversal, the inorder prenode always have 
        // NULL right pointer.
        Node *pre;
        while(h) {
            if(NULL == h->l) {
                cout << " " << h->val << " ";
                h = h->r;
                continue;
            } 
            pre = h->l;
            while(NULL != pre->r && h != pre->r)
                pre = pre->r;
            if(NULL == pre->r) {
                pre->r = h;
                h = h->l;
            } else {
                pre->r = NULL;
                cout << " " << h->val << " ";
                h = h->r;
            }
        }
    }


    void postOrderRecur(Node *h) {
        if (NULL == h) return;
        postOrderRecur(h->l);
        postOrderRecur(h->r);
        cout << " " << h->val << " ";
    }
    
    void postOrderStack(Node *h) {
        stack<Node *> ss;
        if(NULL == h) return;
        Node *cur = h;
        Node *ret = NULL;
        while(1) {
            if(NULL == ret) {
                ss.push(cur);
                if(NULL != cur->l)
                    cur = cur->l;
                else if(NULL != cur->r)
                    cur = cur->r;
                else {
                    cout << " " << cur->val << " ";
                    ss.pop();
                    ret = cur;
                }
            } else {
                if(ss.empty())
                    break;
                cur = ss.top();
                if((ret == cur->l && NULL == cur->r) || ret == cur->r) {
                    cout << " " << cur->val << " ";
                    ss.pop();
                    ret = cur;
                } else {
                    cur = cur->r;
                    ret = NULL;
                }
            }
        }
    }

    int maxDepth(Node *h) { // simpler postorder traversal
        int dp = 0;
        stack<Node*> ss;
        Node *ret = NULL;
        while(h || !ss.empty()) {
            if(h) { // h is a better signal than ret
                ss.push(h);
//                cout << h->val;
                h = h->l;
                dp = dp > ss.size() ? dp : ss.size();
                continue;
            }
            h = ss.top();
            if(NULL == h->r || ret == h->r) {
                cout << " " << h->val << " ";
                ret = h;
                ss.pop();
                h = NULL;
            }
            else 
                h = h->r;
        }
        cout << '\n';
        return dp;
    }

    vector<vector<char> >levelOrder(Node *h) { // postorder solution
        vector<vector<char> > v;
        if(NULL == h) return v;
        stack<Node *> ss;
        Node *ret = NULL;
        while(h || !ss.empty()) {
            if(h) {
                ss.push(h);
                h = h->l;
                continue;
            }
            h = ss.top();
            if(NULL == h->r || ret == h->r) {
                if(v.size() < ss.size()) v.resize(ss.size());
                v[ss.size()-1].push_back(h->val);
                ret = h;
                h = NULL;
                ss.pop();
            } else
                h = h->r;
        }
        return v;
    }

    vector<vector<char> >levelDecOrder(Node *h) { // preorder solution
        vector<vector<char> >v;
        if(NULL == h) return v;
        queue<Node*> ss[2]; // two queue 
        int in = 0, out = 1, i = 1;
        ss[in].push(h);
        while(!ss[in].empty()) {
            v.resize(i);
            while(!ss[in].empty()) {
                Node * t = ss[in].front();
                v[i-1].push_back(t->val);
                if(t->l) ss[out].push(t->l);
                if(t->r) ss[out].push(t->r);
                ss[in].pop();
            }
            i++;
            in ^= 1, out ^= 1;
        }
        reverse(v.begin(), v.end()); // reverse from algorithm
        return v;
    }


};


int main() {
    Node A('A');
    Node B('B');
    Node C('C');
    Node D('D');
    Node E('E');
    Node F('F');
    Node G('G');
    Node H('H');
    Node I('I');

    F.l = &B, F.r = &G;
    B.l = &A, B.r = &D;
    D.l = &C, D.r = &E;
    G.r = &I;
    I.l = &H;

    Node *h = &F;


    Play pp;
    pp.inOrderRecur(h);
    cout << '\n';
    pp.inOrderStack(h);
    cout << '\n';
    pp.inOrderNoStack(h);
    cout << '\n';
    pp.postOrderRecur(h);
    cout << '\n';
    pp.postOrderStack(h);
    cout << '\n';
    cout << "Max Depth: " << pp.maxDepth(h) << '\n';

    vector<vector<char> > level = pp.levelOrder(h);
    for(int i = 0; i < level.size(); i++) {
        for(int j = 0; j < level[i].size(); j++)
            cout << level[i][j] << " ";
        cout << '\n';
    }

    level = pp.levelDecOrder(h);
    for(int i = 0; i < level.size(); i++) {
        for(int j = 0; j < level[i].size(); j++)
            cout << level[i][j] << " ";
        cout << '\n';
    }

    return 0;
}


