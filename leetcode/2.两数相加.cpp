#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

// pc两个结点指针，把l1l2数拿出放在c，最后返回p结点
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *pNode = new ListNode(-1), *cNode = pNode;
        int sum = 0;
        while (l1 || l2 || sum) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            cNode->next = new ListNode(sum%10);
            cNode = cNode->next;
            sum/=10;
        }
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
    int num1[] = {2, 4, 3};
    int n1 = sizeof(num1)/sizeof(num1[0]);
    int num2[] = {5, 6, 4};
    int n2 = sizeof(num2)/sizeof(num2[0]);
    Solution solution;
    ListNode* l1 = solution.change(num1, n1);
    ListNode* l2 = solution.change(num2, n2);
    ListNode* l3 = solution.addTwoNumbers(l1, l2);
    solution.show(l1);
    cout << '\n';
    solution.show(l2);
    cout << '\n';
    solution.show(l3);
    return 0;
}
