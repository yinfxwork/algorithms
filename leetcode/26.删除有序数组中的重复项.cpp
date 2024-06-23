#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// 哈希集合，进行查找与删除工作，效率低下。
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         unordered_set<int> hash;
//         int k = 0;
//         for (auto it = nums.begin(); it != nums.end();) {
//             if (hash.find(*it)!=hash.end()) {
//                 nums.erase(it);
//             } else {
//                 hash.emplace(*it);
//                 ++it;
//                 ++k;
//             }
//         }
//         return k;
//     }
// };


// 双指针，直接动数组前k个。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 1;
        int n = nums.size();
        for (; r<n; ++r) {
            if (nums[l] != nums[r]) nums[++l] = nums[r];
        }
        return l+1;
    }
};


int main() {
    int nums[] = {1,1,2};
    vector<int> v_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    int answer = solution.removeDuplicates(v_nums);
    cout << answer << '\n';
    return 0;
}