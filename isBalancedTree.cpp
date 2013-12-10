#include<iostream>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char c) : val(c), left(NULL), right(NULL) {}
};


class Play {
public:
    bool isBalanced(TreeNode *root) {
        try {
            helper(root);
        }
        catch(int i) {
            return false;
        }
        return true;
    }

    int helper(TreeNode *root) {
        if(root == 0)
            return 0;

        int l = helper(root->left);
        int r = helper(root->right);

        if(l - r < -1 || l - r > 1)
            throw 1;
        return max(l,r) + 1;
    }
};

int main() {
    TreeNode A('A');
    TreeNode B('B');
    TreeNode C('C');
    TreeNode D('D');
    TreeNode E('E');
    TreeNode F('F');
    TreeNode G('G');
    TreeNode H('H');
    TreeNode I('I');

    F.left = &B, F.right = &G;
    B.left = &A, B.right = &D;
//    D.left = &C, D.right = &E;
    G.right = &I;
    I.left = &H;
    G.left = &C;

    TreeNode *h = &F;
    Play pp;
    if(pp.isBalanced(h))
        cout << "Is balanced \n";

    return 0;
}
