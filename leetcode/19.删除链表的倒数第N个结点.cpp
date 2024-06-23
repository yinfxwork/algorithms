#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pNode = new ListNode(0, head), *cNode = pNode;
        int num = 0;
        while (head) {
            ++num;
            head = head->next;
        }
        for(int i = 0; i < num - n; ++i) {
            cNode = cNode->next;
        }
        cNode->next = cNode->next->next;
        return pNode->next;
    }

    ListNode *change(int num[], int n) {
        ListNode *pNode = new ListNode(-1), *cNode = pNode;
        for (int i = 0; i < n; i++) {
            cNode->next = new ListNode(num[i]);
            cNode = cNode->next;
        }
        return pNode->next;
    }

    void show(ListNode *l) {
        while (l) {
            cout << l->val << ' ';
            l = l->next;
        }
    }
};




int main() {
    int num1[] = {1};
    int n1 = sizeof(num1)/sizeof(num1[0]);
    int n = 1;

    Solution solution;
    ListNode* l1 = solution.change(num1, n1);
    ListNode* l3 = solution.removeNthFromEnd(l1, n);
    solution.show(l1);
    cout << '\n';
    solution.show(l3);
    return 0;
}
