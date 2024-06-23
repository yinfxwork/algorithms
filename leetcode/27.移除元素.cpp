#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;



// 双指针，直接动数组前k个。
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int l = 0, r = 0;
//         int n = nums.size();
//         for (; r<n; ++r) {
//             if (nums[r] != val) nums[l++] = nums[r];
//         }
//         return l;
//     }
// };


// 左右双指针，改变顺序但减少依次赋值
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l<r) {
            while (l<r && nums[l]!=val) ++l;
            while (l<r && nums[r]==val) --r;
            if (l<r) nums[l++] = nums[r--];
        }
        if (l==r && nums[l]!=val) return l+1;
        return l;
    }
};




int main() {
    int nums[] = {1,1,2};
    int val = 4;
    vector<int> v_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    int answer = solution.removeElement(v_nums, val);
    cout << answer << '\n';
    return 0;
}