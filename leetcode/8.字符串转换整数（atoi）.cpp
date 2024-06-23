#include <iostream>
#include <string>
using namespace std;


// 遍历字符，依次加到ans上，注意不合规字符
// class Solution {
// public:
//     int myAtoi(string s) {
//         int ans = 0;
//         int flag = 1;
//         bool b = false;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == 32 && !b) {
//             } else if (s[i] == 45) {
//                 if (b) return ans * flag;
//                 flag = -1;
//                 b = true;
//             } else if (s[i] == '+') {
//                 if (b) return ans * flag;
//                 b = true;
//             } else if (48 <= s[i] && s[i] <= 57) {
//                 b = true;
//                 if (ans >= 214748364) {
//                     if (flag == 1) {
//                         if (ans == 214748364) {
//                             if (s[i] > '7') return INT_MAX;
//                         } else {
//                             return INT_MAX;
//                         }
//                     } else {
//                         if (ans == 214748364) {
//                             if (s[i] > '7') return INT_MIN;
//                         } else {
//                             return INT_MIN;
//                         }
//                     }
//                 }
//                 ans = 10 * ans + (s[i] - '0');
//             } else {
//                 return ans * flag;
//             }
//         }
//         return ans * flag;
//     }
// };


// 简化依次加上ans
class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int i = 0;
        int flag = 1;
        while (i < s.size() && s[i] == ' ') ++i;
        if (s[i] == '-') flag = -1;
        if (s[i] == '-' || s[i] == '+') ++i;
        while (i < s.size()) {
            if ('0' > s[i] || s[i] > '9') break;
            if (ans > 214748364 || ans == 214748364 && s[i] > '7') return flag==1?INT_MAX:INT_MIN;
            ans = 10 * ans + (s[i] - '0');
            ++i;
        }
        return ans * flag;
    }
};




// 遍历字符，先组成字符串，最后变为整数。
// class Solution {
// public:
//     int myAtoi(string s) {
//         string str = "";
//         int ans = 0;
//         int flag = 1;
//         bool b = false;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == 32 && !b) {
//             } else if (s[i] == 45) {
//                 if (b) break;
//                 flag = -1;
//                 b = true;
//             } else if (s[i] == '+') {
//                 if (b) break;
//                 b = true;
//             } else if (s[i] == '0' && str == "") {
//                 b = true;
//             } else if (48 <= s[i] && s[i] <= 57) {
//                 b = true;
//                 str+=s[i];
//             } else {
//                 break;
//             }
//         }
//         if (str == "") return 0;
//         if (flag == 1) {
//             if (str.size() == 10 && str > "2147483647") {
//                 return INT_MAX;
//             } else if (str.size() > 10) {
//                 return INT_MAX;
//             } else {
//                 return stoi(str);
//             }
//         } else {
//             if (str.size() == 10 && str > "2147483648") {
//                 return INT_MIN;
//             } else if (str.size() > 10) {
//                 return INT_MIN;
//             } else {
//                 str = "-" + str;
//                 return stoi(str);
//             }
//         }
//     }
// };


int main() {
    string s = "-2147483648";
    Solution solution;
    int answer = solution.myAtoi(s);
    cout << answer << '\n';
    return 0;
}
