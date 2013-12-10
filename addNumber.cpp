#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *s = new ListNode(0);
    ListNode *c = s;
    bool f1 = (NULL != l1);
    bool f2 = (NULL != l2);
    while(1) {
        if(f1) {
            c->val += l1->val;
            l1 = l1->next;
            f1 = (NULL != l1);
        }
        if(f2) {
            c->val += l2->val;
            l2 = l2->next;
            f2 = (NULL != l2);
        }
        bool carry = c->val / 10;
        c->val %= 10;
        if(f1 || f2 || carry) {
            c->next = new ListNode(carry);
            c = c->next;
        } else
            break;
    }
    return s;
}

void print_list(ListNode *l) {
    while(NULL != l){
        cout << l->val;
        l = l->next;
    }
    cout << '\n';
}

void del_list(ListNode *head) {
    while(NULL != head) {
        ListNode *temp = head->next;
        delete head;
        head = temp;
    }
}

ListNode *random_list(int len) {
    int i;
    ListNode *head = new ListNode(rand() % 10);
    ListNode *cr = head;
    for(i=1; i < len; ++i) {
        cr->next = new ListNode(rand() % 10);
        cr = cr->next;
    }
    return head;
}

int main() {
    srand(time(0));
    int i;
    for(i=0; i < 10000000; ++i) {
        ListNode *a = random_list(10);
        ListNode *b = random_list(10);
        print_list(a);
        print_list(b);
        ListNode *c = addTwoNumbers(a,b);
        print_list(c);

        del_list(a);
        del_list(b);
        del_list(c);
    }
    return 0;
}

