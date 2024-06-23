#include <iostream>
using namespace std;


// 字符串翻转
// class Solution {
// public:
//     int reverse(int x) {
//         if (x < 0) {
//             string str = to_string(x);
//             string s(str.rbegin(), str.rend()-1);
//             if (s.size()==10 && s > "2147483647") {
//                 return 0;
//             } else {
//                 return -1 * stoi(s);
//             }
//         } else {
//             string str = to_string(x);
//             string s(str.rbegin(), str.rend());
//             if (s.size()==10 && s > "2147483647") {
//                 return 0;
//             } else {
//                 return stoi(s);
//             }
//         }
//     }
// };


// 用%和/依次输出
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            if (ans > 214748364 || ans < -214748364) return 0;
            int a = x % 10;
            ans = 10 * ans + a;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    int xx = 2147483642;
    int x = -2147483647;
    Solution solution;
    int answer = solution.reverse(x);
    cout << answer << '\n';
    return 0;
}
