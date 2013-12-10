#include<iostream>
#include<stack>
#include<iomanip>
using namespace std;

struct TreeLNode {
    int val;
    TreeLNode *left, *right, *next;
    TreeLNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLNode *root) {
        if(NULL == root) return;
        TreeLNode *l = root;
        while(l->left != NULL) {
            TreeLNode *r = l;
            while(r->next != NULL) {
                (r->left)->next = r->right;
                (r->right)->next = (r->next)->left;
                r = r->next;
            }
            (r->left)->next = r->right;
            l = l->left;
        }
    }

    void connectG(TreeLNode *root) {
        if(NULL == root) return;
        TreeLNode *l = root;
        while(l) {
            TreeLNode *r = NULL; //reset in each loop
            bool lor = false; //looking at left node
            while(l) {
                if(l->left != NULL) {
                    r = l->left;
                    lor = true;
                    break;
                } else if (l->right != NULL) {
                    r = l->right;
                    l = l->next;
                    lor = false;
                    break;
                }
                l = l->next;
            }
            TreeLNode *t = r;
            while(l) {
                if (lor) {
                    lor = false;
                    if(l->right != NULL) {
                        r->next = l->right;
                        r = r->next;
                    }
                    l = l->next;
                    continue;
                } else {
                    lor = true;
                    if(l->left != NULL) {
                        r->next = l->left;
                        r = r->next;
                    }
                    continue;
                }
            }
            l = t;
        }
    }

    int minDepth(TreeLNode *root) {
        if (NULL == root) return 0;
        if(NULL == root->left) return minDepth(root->right) + 1;
        if(NULL == root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }

    int maxDepth(TreeLNode *root){
        if(NULL == root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void printArrayTree(TreeLNode root[], int d) {
        int w = 3 << (d-1);
        int n = 0;
        while(d-- > 0){
            for(int i=0; i <= n; i++) {
                if(root[n+i].val)
                    cout << setw(w) << (root[n+i].val) << setw(w) << "";
                else 
                    cout << setw(2*w) << "";
            }
            cout << '\n';
            for(int i=0; i <= n; i++){
                if((root[n+i].next != NULL) && (root[n+i].val != 0))
                    cout << setw(w-2) << ">"   
                        << setw(2) << (root[n+i].next)->val
                        << setw(w) << "";
                else
                    cout << setw(2*w) << "";
            }
            cout << '\n';
            w >>= 1;
            n = 2 * n + 1;
        }
    }

    void restorePerfectTree(TreeLNode root[], int d) {
        int i = 0;
        for(; i < (1<<(d-1)) - 1; i++) {
            root[i].val = i+1;
            root[i].next = NULL;
            root[i].left = root + 2*i + 1;
            root[i].right = root + 2*i + 2;
        }
        for(; i < (1 << d) - 1; i++) {
            root[i].val = i+1;
            root[i].next = NULL;
            root[i].left = NULL;
            root[i].right = NULL;
        }
    }

    void eraseNode(TreeLNode *node) {
        if(NULL == node)
            return;
        node->val = 0;
        eraseNode(node->left);
        eraseNode(node->right);
        node->left = NULL;
        node->right = NULL;
    }

    void eraseBranch(TreeLNode *node, bool lor) {
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

    void eraseBranch(TreeLNode *node){
        if(NULL == node)
            return;
        eraseNode(node->left);
        eraseNode(node->right);
        node->left = NULL;
        node->right = NULL;
    }    
};

int main() {
    int d = 5;
    int n = (1 << d) - 1;
    TreeLNode *bt = new TreeLNode[n];

    Solution pp;
    pp.restorePerfectTree(bt, d);
    pp.connect(bt);
    pp.printArrayTree(bt, d);

    pp.restorePerfectTree(bt, d);
    pp.eraseBranch(bt + 6, 0);
    pp.eraseBranch(bt + 6, 1);
    pp.eraseBranch(bt+22);
    pp.eraseBranch(bt+8);
    pp.eraseBranch(bt+40);

    pp.connectG(bt);
    pp.printArrayTree(bt, d);
    cout << "Min Depth: " << pp.minDepth(bt)
        << "  Max Depth: " << pp.maxDepth(bt) << '\n';

    delete [] bt;
    return 0;
}
