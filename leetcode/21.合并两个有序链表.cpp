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
    // 创建新结点，一个一个加，比较慢
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     ListNode* dummy = new ListNode(0), *cur = dummy;
    //     while (list1 && list2) {
    //         if (list1->val < list2->val) {
    //             cur->next = new ListNode(list1->val);
    //             cur = cur->next;
    //             list1 = list1->next;
    //         } else {
    //             cur->next = new ListNode(list2->val);
    //             cur = cur->next;
    //             list2 = list2->next;
    //         }
    //     }
    //     if (list1) {
    //         cur->next = list1;
    //     } else {
    //         cur->next = list2;
    //     }
    //     return dummy->next;
    // }


    //递归或迭代，直接连结点
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy->next;
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
    int n1 = sizeof(num1)/sizeof(num1[0]);
    int num2[] = {1, 3, 5};
    int n2 = sizeof(num2)/sizeof(num2[0]);
    Solution solution;
    ListNode* l1 = solution.change(num1, n1);
    ListNode* l2 = solution.change(num2, n2);
    ListNode* l3 = solution.mergeTwoLists(l1, l2);
    solution.show(l1);
    cout << '\n';
    solution.show(l2);
    cout << '\n';
    solution.show(l3);
    return 0;
}

