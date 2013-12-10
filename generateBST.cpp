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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> v;
        v.push_back(0);
        for(int i = 1; i <= n; ++i) {
            int s = v.size();
            for(int j = 0; j < s; ++j) {
                TreeNode *r = v[j];
                TreeNode *t = new TreeNode(i);
                while(r) {
                    t->left = r->right;
                    r->right = t;
                    v.push_back(copyTree(v[j]));
                    r->right = t->left;
                    r = r->right;
                }
                t->left = v[j];
                v[j] = t;
            }
        }
        return v;
    }

    TreeNode *copyTree(TreeNode *r) {
        if(r == 0)
            return 0;
        TreeNode *n = new TreeNode(r->val);
        n->left = copyTree(r->left);
        n->right = copyTree(r->right);
        return n;
    }

    void walk(TreeNode *r) {
        if(r == 0)
            return;
        cout << r->val << " ";
        walk(r->left);
        cout << " # ";
        walk(r->right);
    }
};

int main() {
    Play pp;
    vector<TreeNode *> v = pp.generateTrees(5);
    for(int i = 0; i < v.size(); ++i) {
        cout << "\n NUMBER: " << i << '\n';
        pp.walk(v[i]);
    }

    return 0;
}
