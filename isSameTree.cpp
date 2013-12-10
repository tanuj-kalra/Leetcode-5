#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> ps, qs;
        ps.push(p);
        qs.push(q);
        while((!qs.empty()) && (!ps.empty())) {
            TreeNode *pt = ps.top();
            ps.pop();
            TreeNode *qt = qs.top();
            qs.pop();
            if((NULL == pt) ^ (NULL == qt)) return false;
            if(NULL == pt) continue;
            if((pt->val) != (qt->val)) return false;
            ps.push(pt->right);
            ps.push(pt->left);
            qs.push(qt->right);
            qs.push(qt->left);
        }
        if(qs.empty() ^ ps.empty()) return false;
        return true;
    }

    bool idTree(TreeNode *p, TreeNode *q) { // recursive version
        return((!p && !q) || (p && q) &&
                p->val == q->val && idTree(p->left, q->left) &&
                idTree(p->right, q->right)) ;
    }
};

int main(){
    TreeNode *t;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    t = p->left;
//    t->left = new TreeNode(3);
    t->right = new TreeNode(4);
    t = p->right;
    t->left = new TreeNode(5);
    t->right = new TreeNode(6);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(1);
    q->right = new TreeNode(2);
    t = q->left;
//    t->left = new TreeNode(3);
    t->right = new TreeNode(4);
    t= q->right;
//    t->left = new TreeNode(5);
    t->right = new TreeNode(6);

    Solution pp;
    if(pp.isSameTree(p, q))
        cout << "Same Tree\n";
    if(pp.idTree(p,q))
        cout << "Identical Tree\n";
    return 0;
}

