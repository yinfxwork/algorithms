#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 左右双指针，改变顺序但减少依次赋值
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n1 = haystack.size();
//         int n2 = needle.size();
//         for (int i = 0; i <= n1-n2; ++i) {
//             int l = i;
//             int r = 0;
//             while (haystack[l++] == needle[r++]) {
//                 if (r == n2) return i;
//                 if(l == n1) return -1;
//             }
//         }
//         return -1;
//     }
// };


// KMP算法之添加哨兵，从零开始、、从-1开始
class Solution {
public:
    int strStr(string s, string p) {
        int n = s.size(), m = p.size();
        if (m == 0) return 0;
        vector<int> next(m);
        next[0] = -1;
        for (int i = 1, j = -1; i < m; ++i) {
            while (j!=-1 && p[i] != p[j+1]) j = next[j];
            if (p[i] == p[j+1]) ++j;
            next[i] = j;
        }
        for(int i = 0, j = -1; i < n; ++i) {
            while (j!=-1 && s[i] != p[j+1]) j = next[j];
            if (s[i] == p[j+1]) ++j;
            if (j == m-1) return i-m+1;
        }
        return -1;
    }
};




int main() {
    string str = "sadbutsad";
    string s = "sad";
    Solution solution;
    int answer = solution.strStr(str, s);
    cout << answer << '\n';
    return 0;
}