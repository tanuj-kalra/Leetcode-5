#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Play {
public:
    TreeNode *sortedArrToBST(vector<int> &num) {
        TreeNode *h = helper(num, 0, num.size() - 1);
        return h;
    }

    TreeNode *helper(vector<int> &num, int low, int high) {
        if(high < low)
            return 0;
        int mid = (low + high) / 2;
        TreeNode *h = new TreeNode(num[mid]);
        h->left = helper(num, low, mid - 1);
        h->right = helper(num, mid + 1, high);
        return h;
    }

    TreeNode *sortedListToBST(ListNode *l) {
        return listhelper(l, 0);
    }

    TreeNode *listhelper(ListNode *h, ListNode *t) {
        if(h == t)
            return 0;
        ListNode *p1 = h, *p2 = h->next;
        while(p2 != t) {
            p2 = p2->next;
            p1 = p1->next;
            if(p2 != t)
                p2 = p2->next;
        }
        TreeNode *r = new TreeNode(p1->val);
        r->left = listhelper(h, p1);
        r->right = listhelper(p1->next, t);
        return r;
    }

    void walk(TreeNode *h) {
        if(h == 0)
            return;
        walk(h->left);
        cout << h->val << " ";
        walk(h->right);
    }
};

/* compile with C++ 11 */
int main() {
    vector<int> v{1,2,3,4,5,6,7,8,9,10};

    Play pp;
    TreeNode *h = pp.sortedArrToBST(v);
    pp.walk(h);
    cout << endl;

    ListNode *l, **p = &l;
    for(int i = 0; i < 10; ++i) {
        *p = new ListNode(i);
        p = &(*p)->next;
    }
    TreeNode *f = pp.sortedListToBST(l);
    pp.walk(f);
    cout << endl;

    return 0;
}
