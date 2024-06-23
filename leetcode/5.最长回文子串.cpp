#include <iostream>
#include <string>
using namespace std;

// 第一层for循环从左侧开始递增，第二层while循环从右侧递减，第三层while循环从两侧向中间判断是否回文
// class Solution
// {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         int max_num = 0;
//         int max_l = 0;
//         for (int i = 0; i < n; ++i) {
//             int left = i, right = n-1;
//             while (left<=right) {
//                 int l = left, r = right;
//                 while (s[l]==s[r]) {
//                     if (l==r || l+1==r) {
//                         if (max_num < right - left + 1) {
//                             max_l=left;
//                             max_num = right-max_l+1;
//                         }
//                         if (max_num >= n - i) {
//                             return s.substr(max_l,max_num);
//                         }
//                         break;
//                     };
//                     l++;
//                     r--;
//                 }
//                 right--;
//             }
//         }
//         return s.substr(max_l,max_num);
//     }
// };


// 从中间开始中心拓展算法，并根据答案提前结束
class Solution
{
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_num = 1;
        int max_l = 0;
        int i = n / 2;
        int m = -1;
        int v = 1;
        while (i >= 0 && i < n) {
            int left = i, right = i+1;
            while (left >=0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (max_num < right - left - 1) {
                max_num = right - left - 1;
                max_l = left+1;
            }
            left = i-1, right = i+1;
            while (left >=0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (max_num < right - left - 1) {
                max_num = right - left - 1;
                max_l = left+1;
            }
            if (max_num > 2 * (n - i)) {
                return s.substr(max_l,max_num);
            }
            i = i + v * m;
            v = v + 1;
            m = -m;
        }
        return s.substr(max_l,max_num);
    }
};


int main() {
    string s = "aba";
    Solution solution;
    string answer = solution.longestPalindrome(s);
    cout << answer << ' ';
    return 0;
}
