#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Play {
public:
    void recoverTree(TreeNode *h) {
        TreeNode *f1, *f2;
        bool found = false;
        TreeNode *pre, *par = 0; // previous AND parent
        while(h) { // Morris Traversal
            if(h->left == 0) {
                if(par && par->val > h->val) {  // inorder previous is: par
                    if(!found) {
                        f1 = par;
                        found = true;
                    }
                    f2 = h;
                }
                par = h;
                h = h->right;
                continue;
            }
            pre = h->left;
            while(pre->right != 0 && pre->right != h) 
                pre = pre->right;
            if(pre->right == 0) {
                pre->right = h;
                h = h->left;
            } else {
                pre->right = 0;
                if(pre->val > h->val) { // inorder previous is: pre
                    if(!found) {
                        f1 = pre;
                        found =true;
                    }
                    f2 = h;
                }
                par = h;
                h = h->right;
            }
        }
        if(found)
            swap(f1->val, f2->val);
    }

    void walk(TreeNode *h) {
        if(h == 0)
            return;
        walk(h->left);
        cout << h->val << " ";
        walk(h->right);
    }
};

int main() {
    Play pp;
    TreeNode A(1), B(2), C(3), D(4), E(5), F(6), G(7), H(8);

    TreeNode *r = &E;
    E.left = &B, E.right = &G;
    B.left = &A, B.right = &D;
    D.left = &C;
    G.left = &F, G.right = &H;
    pp.walk(r);
    cout << endl;

    swap(C.val, G.val);
    pp.walk(r);
    cout << endl;

    pp.recoverTree(r);
    pp.walk(r);
    cout << endl;

    return 0;
}
