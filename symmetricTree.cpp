#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Play {
public:
    bool isSymmetric(TreeNode *root) {
        /* How about iterative version ? */
        if(root)
            try {
                sympare(root->left, root->right);
            } catch(int x) {
                return false;
            }
        return true;
    }

    void sympare(TreeNode *l, TreeNode *r) {
        if(l == 0 && r != 0 || l != 0 && r == 0)
            throw 1;
        if(l) {
            if(l->val != r->val)
                throw 1;
            sympare(l->left, r->right);
            sympare(l->right, r->left);
        }
    }
};

int main() {
    Play pp;
    TreeNode A(1), B(2), C(2), D(3), E(4), F(5), G(4), H(3);

    TreeNode *r = &A;
    A.left = &B, A.right = &C;
    if(pp.isSymmetric(r)) cout << "Symmetric !\n";

    B.left = &D, B.right = &E;
    C.left = &G, C.right = &H;
    if(pp.isSymmetric(r)) cout << "Symmetric !\n";

    G.left = &F;
    if(pp.isSymmetric(r)) cout << "Symmetric !\n";

    return 0;
}

