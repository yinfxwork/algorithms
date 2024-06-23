#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 把遍历过的数放在哈希表中，当对应的数出现时，返回
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = target - nums[i];
            auto it = dict.find(j);
            if (it != dict.end()) {
                return {dict[j], i};
            }
            dict[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> v_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    vector<int> answer = solution.twoSum(v_nums, target);
    for (vector<int>::iterator i = answer.begin(); i != answer.end(); ++i) {
        cout << *i << ' ';
    }
    return 0;
}
