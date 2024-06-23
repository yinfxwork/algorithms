#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//四数i，l，find，r，效率不足。
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> ans;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n - 3; ++i) {
//             if (i > 0 && nums[i] == nums[i-1]) continue;
//
//             long scope = nums[i];
//             scope+=nums[i+1];
//             scope+=nums[i+2];
//             scope+=nums[i+3];
//             if (scope > target) break;
//             scope = nums[i];
//             scope += nums[n-1];
//             scope += nums[n-2];
//             scope += nums[n-3];
//             if (scope < target) continue;
//
//             int l = i+1;
//             while (n-l>=3) {
//                 int r = n-1;
//                 while (r-l>=2) {
//                     mysum(nums, target, ans, i, l, r);
//                     while (nums[r] == nums[--r]) {
//                         if (r-l<2) break;
//                     }
//                 }
//                 while (nums[l] == nums[++l]) {
//                     if (l>n-3) break;
//                 }
//             }
//         }
//         return ans;
//     }
//     void mysum(const vector<int>& nums, const int& target, vector<vector<int>>& ans, int i, int l, int r) {
//         long scope = nums[i];
//         scope+=nums[l];
//         scope+=nums[r];
//         if(scope > 1000000000 || scope < -1000000000) return;
//         int value = target - (scope);
//         if (find(nums.begin()+l+1, nums.end()-(nums.size()-r), value) != nums.end()-(nums.size()-r)) {
//             ans.push_back({nums[i], nums[l], value, nums[r]});
//         }
//     }
// };


// 四数i，j，l，r
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if ((long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if ((long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if ((long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;

                int l = j + 1, r = n - 1;
                while (l < r) {
                    long value = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (value < target) {
                        ++l;
                    } else if (value > target) {
                        --r;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[++l]);
                        while (r > l && nums[r] == nums[--r]);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    int nums[] = {1,0,-1,0,-2,2};
    int target = 0;
    vector<int> v_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    vector<vector<int>> answer = solution.fourSum(v_nums, target);
    for (int i = 0; i < answer.size(); ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            cout << answer[i][j];
        }
        cout << endl;
    }
    return 0;
}