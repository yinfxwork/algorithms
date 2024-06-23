#include <iostream>
using namespace std;


// 两边比较即可得知是否为回文数
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x == 0) return true;
//         if (x < 0 || x%10==0) return false;
//         int tmp = 0;
//         while (x > tmp) {
//             tmp = tmp * 10 + x%10;
//             x /= 10;
//         }
//         if (x == tmp || x == tmp/10) return true;
//         return false;
//     }
// };


//字符串回文比较
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = std::to_string(x);
        int i = 0;
        int n = s.size() - 1;
        while (i < n) {
            if (s[i] != s[n]) return false;
            ++i;
            --n;
        }
        return true;
    }
};



int main() {
    int x = -2147483647;
    Solution solution;
    int answer = solution.isPalindrome(x);
    cout << answer << '\n';
    return 0;
}
