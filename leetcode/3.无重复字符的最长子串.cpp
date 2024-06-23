#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//哈希表放遍历过的字符与对应位置，当出现重复时判断位置与left大小，相减得出距离
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> dict;
//         int max_num = 0;
//         int n = s.size();
//         int left = 0;
//         int i;
//         for (i = 0; i < n; ++i) {
//             auto it = dict.find(s[i]);
//             if (it != dict.end()) {
//                 max_num = (max_num > i-left) ? max_num : i-left;
//                 left = max(left, it->second + 1);
//             }
//             dict[s[i]] = i;
//         }
//         return (max_num > i-left) ? max_num : i-left;
//     }
// };


//用哈希集合从左侧依次向下，看右侧最远是多少。
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> hashset;
//         int max_num = 0;
//         int n = s.size();
//         int rp = -1;
//         for (int i = 0; i < n; ++i) {
//             if (i != 0) {
//                 hashset.erase(s[i-1]);
//             }
//             while (rp+1 < n && hashset.find(s[rp+1]) == hashset.end()) {
//                 hashset.insert(s[rp+1]);
//                 ++rp;
//             };
//             max_num = max(max_num,rp-i+1);
//         }
//         return max_num;
//     }
// };



//用数组存放对应字母最新位置
class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        int nums[128] = {0};
        int ans = 0;
        int n = s.size();
        int left = 0;
        int ss = 0, i = 0;
        for (; i < n; ++i) {
            ss = nums[s[i]];
            if (ss > left) {
                ans = max(ans, i - left);
                left = ss;
            }
            nums[s[i]] = i+1;
        }
        return max(ans, i - left);
    }
};



int main() {
    string s = "aaa";
    Solution solution;
    int max_num = solution.lengthOfLongestSubstring(s);
    cout << max_num;
    // int nums[128] = {-1};
    // cout << s[0] << '\n';
    // nums[s[0]] = 10;
    // // cout << nums[s[0]];
    // cout << nums['Z'];

    return 0;
}
