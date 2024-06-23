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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = k;
        ListNode* last = head;
        while (i--) {
            if (!last) return head;
            last = last->next;
        }
        ListNode* cur = head->next;
        head->next = reverseKGroup(last, k);
        while (--k) {
            ListNode* tmp = cur->next;
            cur->next = head;
            head = cur;
            cur = tmp;
        }
        return head;
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
    int num1[] = {2, 3, 4};
    int k = 3;
    int n1 = sizeof(num1)/sizeof(num1[0]);
    Solution solution;
    ListNode* l1 = solution.change(num1, n1);
    ListNode* l3 = solution.reverseKGroup(l1, k);
    solution.show(l1);
    cout << '\n';
    solution.show(l3);
    cout << '\n';
    return 0;
}

