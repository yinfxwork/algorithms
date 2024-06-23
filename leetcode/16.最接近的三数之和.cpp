#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int diff = INT_MAX;
        int value;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;




            int s = nums[i] + nums[i + 1] + nums[i + 2];
            if (s > target) { // 后面无论怎么选，选出的三个数的和不会比 s 还小
                if (s - target < diff) {
                    ans = s; // 由于下面直接 break，这里无需更新 min_diff
                }
                break;
            }

            // 优化二
            s = nums[i] + nums[n - 2] + nums[n - 1];
            if (s < target) {
                // x 加上后面任意两个数都不超过 s，所以下面的双指针就不需要跑了
                if (target - s < diff) {
                    diff = target - s;
                    ans = s;
                }
                continue;
            }


            int l = i+1, r = n-1;
            while (l < r) {
                value = nums[i]+nums[l]+nums[r];
                if (value < target) {
                    if (target - value < diff) {
                        ans = value;
                        diff = target - value;
                    }
                    ++l;
                } else if (value > target) {
                    if (value - target < diff) {
                        ans = value;
                        diff = value - target;
                    }
                    --r;
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
};





int main() {
    int nums[] = {0,0,0,0};
    int target = 1;
    vector<int> v_nums({0,0,0});
    Solution solution;
    int answer = solution.threeSumClosest(v_nums,target);
    cout << answer << '\n';
    return 0;
}