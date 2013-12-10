#include<iostream>
#include<iomanip>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) { // pre order transversal
        if(NULL == root) return;
        stack<TreeNode *> b;
        b.push(root);
        TreeNode *p = NULL;
        while(!b.empty()) {
            TreeNode *t = b.top();
            b.pop();

            if(p)
                p->right = t;
            p = t;

            if(t->right) {
                b.push(t->right);
            }
            if(t->left) {
                b.push(t->left);
            }
        }
    }

    void flatten2(TreeNode *r) { // In place way
        while(r) {
            if(r->right == NULL) {
                r->right = r->left;
                r->left = NULL; // leetcode require this
            } else if(r->left != NULL) {
                TreeNode *t = r->left;
                while(t->right)
                    t = t->right;
                t->right = r->right;
                r->right = r->left;
                r->left = NULL; // leetcode require this
            }
            r = r->right;
        }
    }

    void printRightNodeList(TreeNode *r) {
        while (r) {
            cout << setw(3) << r->val;
            r = r->right;
        }
        cout << '\n' << '\n';
    }

    // Modified from populatingNextRight.cpp
    void printArrayTree(TreeNode root[], int d) {
        int w = 2 << (d-1);
        int n = 0;
        while(d-- > 0){
            for(int i=0; i <= n; i++) {
                if(root[n+i].val)
                    cout << setw(w) << (root[n+i].val) << setw(w) << "";
                else
                    cout << setw(2*w) << "";
            }
            cout << '\n';
            w >>= 1;
            n = 2 * n + 1;
        }
        cout << '\n';
    }

    void restorePerfectTree(TreeNode root[], int d) {
        int i = 0;
        for(; i < (1<<(d-1)) - 1; i++) {
            root[i].val = i+1;
            root[i].left = root + 2*i + 1;
            root[i].right = root + 2*i + 2;
        }
        for(; i < (1 << d) - 1; i++) {
            root[i].val = i+1;
            root[i].left = NULL;
            root[i].right = NULL;
        }
    }

    void eraseNode(TreeNode *node) {
        if(NULL == node)
            return;
        node->val = 0;
        eraseNode(node->left);
        eraseNode(node->right);
        node->left = NULL;
        node->right = NULL;
    }

    void eraseBranch(TreeNode *node, bool lor) {
        if(NULL == node)
            return;
        if(lor){
            eraseNode(node->right);
            node->right = NULL;
        } else {
            eraseNode(node->left);
            node->left = NULL;
        }
    }

    void eraseBranch(TreeNode *node){
        if(NULL == node)
            return;
        eraseNode(node->left);
        eraseNode(node->right);
        node->left = NULL;
        node->right = NULL;
    }
    // End from populatingNextRight.cpp
};

int main() {
    Solution pp;
    TreeNode *r = new TreeNode[5];
    for(int i = 0; i < 5; i++)
        r[i].val = i;
    r[0].left = r + 1;
    r[0].right = r + 2;
    r[1].left = r + 3;
    r[1].right = r + 4;

    pp.flatten(r);
    pp.printRightNodeList(r);

    delete [] r;

    int d = 5;
    int n = (1 << d) - 1;
    TreeNode *bt = new TreeNode[n];

    pp.restorePerfectTree(bt, d);
    pp.printArrayTree(bt, d);
    pp.flatten2(bt);
    pp.printRightNodeList(bt);

    pp.restorePerfectTree(bt, d);
    pp.eraseBranch(bt + 6, 0);
    pp.eraseBranch(bt+22);
    pp.eraseBranch(bt+12, 0);
    pp.eraseBranch(bt+8);
    pp.eraseBranch(bt+30);
    pp.printArrayTree(bt, d);
    pp.flatten2(bt);
    pp.printRightNodeList(bt);

    delete [] bt;

    return 0;
}
