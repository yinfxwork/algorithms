#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 失败，哈希表过多，循环过多
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         int target;
//         int zero = 0;
//         unordered_set<int> hashset_negative;
//         unordered_set<int> hashset_positive;
//         unordered_set<int> hashset_two;
//         unordered_set<int> hashset;
//         for (int i = 0; i < n; ++i) {
//             if (nums[i] < 0) {
//                 if (hashset_negative.find(nums[i])==hashset_negative.end()) {
//                     hashset_negative.emplace(nums[i]);
//                     hashset.emplace(nums[i]);
//                 } else {
//                     hashset_two.emplace(nums[i]);
//                 }
//             } else if (nums[i] > 0) {
//                 if (hashset_positive.find(nums[i])==hashset_positive.end()) {
//                     hashset_positive.emplace(nums[i]);
//                     hashset.emplace(nums[i]);
//                 } else {
//                     hashset_two.emplace(nums[i]);
//                 }
//             } else {
//                 ++zero;
//             }
//         }
//
//         if (zero >= 3) {
//             vector<int> v;
//             v.push_back(0);
//             v.push_back(0);
//             v.push_back(0);
//             ans.push_back(v);
//         }
//
//
//         for (auto it = hashset_two.begin(); it != hashset_two.end(); ++it) {
//             target = -2 * *it;
//             if (hashset.find(target) != hashset.end()) {
//                 vector<int> v;
//                 v.push_back(*it);
//                 v.push_back(*it);
//                 v.push_back(target);
//                 ans.push_back(v);
//             }
//         }
//
//         for (auto it = hashset_negative.begin(); it != hashset_negative.end(); ++it) {
//             for (auto itp = hashset_positive.begin(); itp != hashset_positive.end(); ++itp) {
//                 hashset.erase(*it);
//                 target = -*it - *itp;
//                 if (target == 0 && zero > 0) {
//                     vector<int> v;
//                     v.push_back(*it);
//                     v.push_back(0);
//                     v.push_back(*itp);
//                     ans.push_back(v);
//                 }
//                 if (target != *itp && hashset.find(target)!=hashset.end()) {
//                     vector<int> v;
//                     v.push_back(*it);
//                     v.push_back(target);
//                     v.push_back(*itp);
//                     ans.push_back(v);
//                 }
//             }
//         }
//         return ans;
//     }
// };


// 左右指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int value = nums[i] + nums[i+1] + nums[i+2];
            if (value > 0) break;
            value = nums[i] + nums[n-1] + nums[n-2];
            if (value < 0) continue;

            int l = i+1, r = n-1;
            while (l < r) {
                value = nums[i]+nums[l]+nums[r];
                if (value < 0) {
                    ++l;
                } else if (value > 0) {
                    --r;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++l]);
                    while (r > l && nums[r] == nums[--r]);
                }
            }
        }
        return ans;
    }
};

int main() {
    int nums[] = {0,0,0,0};
    vector<int> v_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    vector<vector<int>> answer = solution.threeSum(v_nums);
    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            cout << answer[i][j];
        }
        cout << endl;
    }
    return 0;
}