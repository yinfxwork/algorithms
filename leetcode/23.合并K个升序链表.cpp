#include <iostream>
#include <vector>
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
    //递归或迭代，直接连结点
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     ListNode* dummy = new ListNode(0), *cur = dummy;
    //     merge(lists, cur);
    //     return dummy->next;
    // }
    // void merge(vector<ListNode*>& lists, ListNode* cur) {
    //     int min_num = 10001;
    //     auto min_it = lists.begin();
    //     for (auto it = lists.begin(); it != lists.end();) {
    //         if (!*it) {
    //             it = lists.erase(it);
    //         } else if ((*it)->val < min_num) {
    //             min_num = (*it)->val;
    //             min_it = it;
    //             ++it;
    //         }else {
    //             ++it;
    //         }
    //     }
    //     if (lists.size()==0) return;
    //     cur->next = *min_it;
    //     cur = cur->next;
    //     *min_it = (*min_it)->next;
    //     merge(lists, cur);
    // }

    //两两合并或依次合并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return two(lists, 0, lists.size()-1);
    }
    ListNode* two(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = (l + r) / 2;
        return merge(two(lists,l,mid), two(lists, mid+1, r));
    }
    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l || !r) return l ? l : r;
        ListNode* dummy = new ListNode(), *cur = dummy;
        while (l && r) {
            if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        cur->next = l ? l : r;
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
    vector<ListNode*> lists;
    int num1[] = {2, 3, 4};
    int n1 = sizeof(num1)/sizeof(num1[0]);
    int num2[] = {1, 3, 5};
    int n2 = sizeof(num2)/sizeof(num2[0]);
    Solution solution;
    ListNode* l1 = solution.change(num1, n1);
    ListNode* l2 = solution.change(num2, n2);
    lists.push_back(l1);
    lists.push_back(l2);
    ListNode* l3 = solution.mergeKLists(lists);
    solution.show(l1);
    cout << '\n';
    solution.show(l2);
    cout << '\n';
    solution.show(l3);
    return 0;
}

