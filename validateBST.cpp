#include<iostream>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Play {
public:
    bool isValidBST(TreeNode *root) {
        try {
            helper(root, INT_MIN, INT_MAX);
        } catch(int x) {
            return false;
        }
        return true;
    }

    void helper(TreeNode *r, int low, int high) {
        if(r == 0)
            return;
        if(r->val <= low || r->val >= high)
            throw 1;
        helper(r->left, low, r->val);
        helper(r->right, r->val, high);
    }

};

int main() {
    Play pp;
    TreeNode A(1), B(2), C(3), D(4), E(4), F(5), G(6), H(7);

    TreeNode *r = &D;
    D.left = &A, D.right = &G;
    if(pp.isValidBST(r)) cout << "is Valid! \n";

    A.left = 0 , A.right = &C;
    C.left = &B, C.right = &E;
    if(pp.isValidBST(r)) cout << "is Valid! \n";

    G.left = &H;
    if(pp.isValidBST(r)) cout << "is Valid! \n";

    return 0;
}
