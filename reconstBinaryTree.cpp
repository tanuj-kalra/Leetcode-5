#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Play {
public:
    TreeNode *buildTreeIP(vector<int> &inorder, vector<int> &postorder) {
        return IPhelper(inorder, 0, inorder.size() - 1,
                postorder, 0, postorder.size() - 1);
    }

    TreeNode *IPhelper(vector<int> &I, int il, int ih, 
            vector<int> &P, int pl, int ph) {
        if(pl > ph)
            return 0;
        TreeNode *r = new TreeNode(P[ph]);
        int t = ih;
        while(I[t] != P[ph])
            --t;
        r->left = IPhelper(I, il, t-1, P, pl, pl-il+t-1);
        r->right = IPhelper(I, t+1, ih, P, pl-il+t, ph-1);
        return r;
    }

    TreeNode *buildTreePreI(vector<int> &preorder, vector<int>inorder) {
        return PreIhelper(preorder, 0, preorder.size() - 1,
                inorder, 0, inorder.size() - 1);
    }

    TreeNode *PreIhelper(vector<int> &P, int pl, int ph,
            vector<int> &I, int il, int ih) {
        if(pl > ph)
            return 0;
        TreeNode *r = new TreeNode(P[pl]);
        int t = il;
        while(I[t] != P[pl])
            ++t;
        r->left = PreIhelper(P, pl+1, pl+t-il, I, il, t-1);
        r->right = PreIhelper(P, pl+t-il+1, ph, I, t+1, ih);
        return r;
    }

    void walk(TreeNode *r) {
        walkhelper(r);
        cout << endl;
    }

    void walkhelper(TreeNode *r) {
        if(r == 0)
            return;
        walkhelper(r->left);
        cout << r->val << " ";
        walkhelper(r->right);
    }
};


int main() {
    vector<int> in {1,2,3,4,5,6,7};
    vector<int> post {1,3,2,6,7,5,4};

    Play pp;
    TreeNode *r = pp.buildTreeIP(in, post);
    pp.walk(r);

    vector<int> pre {4,2,1,3,5,7,6};
    TreeNode *s = pp.buildTreePreI(pre, in);
    pp.walk(s);

    return 0;
}
