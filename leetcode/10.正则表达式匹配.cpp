#include <iostream>
#include <string>
#include <vector>
using namespace std;


//遍历失败
// class Solution {
// public:
//     bool test(string s, string p, int &te) {
//         int i = 0, j = 0;
//         while (i < s.size()) {
//             if (j == p.size()) return false;
//             if (j+1<p.size() && p[j+1] == '*') {
//                 if (p[j] == '.') {
//                     j += 2;
//                     if (j==p.size()) return true;
//                     while (j+1<p.size() && p[j+1] == '*') {
//                         j+=2;
//                         if (j==p.size()) return true;
//                     }
//                     while (p[j] == '.') {
//                         ++i;
//                         ++j;
//                         while (j+1<p.size() && p[j+1] == '*') {
//                             j+=2;
//                             if (j==p.size()) return true;
//                         }
//                         if (j==p.size()) return true;
//                         if (i==s.size()) return false;
//                     }
//                     while (true) {
//                         while (s[i] != p[j]) {
//                             ++i;
//                             if (i==s.size()) {
//                                 te = 3;
//                                 return false;
//                             }
//                         }
//
//                         if (te == 0) break;
//                         ++i;
//                         --te;
//
//                         int one = j;
//                         while (true) {
//                             if(one + 1 == p.size()) break;
//                             if(p[one] == '.' && p[one+1] == '*') {
//                                 string str = p.substr(one, p.size()-one);
//                                 string strstr = s.substr(i, s.size()-i);
//                                 int onete = 0,onest = 0;
//                                 while (!test(strstr,str,onete)) {
//                                     ++onest;
//                                     onete = onest;
//                                     if (onete == 8) return false;
//                                 }
//                                 return true;
//                             }
//                             ++one;
//                         }
//                     }
//                     continue;
//                 }
//                 if (s[i] != p[j]) {
//                     j += 2;
//                     if (j==p.size()) return false;
//                     continue;
//                 }
//                 char tmp = p[j];
//                 int m = 0, n = 0;
//                 while (s[i] == p[j]) {
//                     ++i;
//                     ++m;
//                     if (i == s.size()) break;
//                 }
//                 j+=2;
//                 if (j == p.size()) {
//                     if (i == s.size()) return true;
//                     return false;
//                 }
//                 if (i == s.size()) {
//                     while (true) {
//                         if (j+1<p.size() && p[j+1] == '*') {
//                             j+=2;
//                             if (j == p.size()) break;
//                         }
//                         if (p[j] == tmp) {
//                             ++j;
//                             ++n;
//                             if (j == p.size()) break;
//                             continue;
//                         }
//                         return false;
//                     }
//                 } else {
//                     while (true) {
//                         if (p[j] == tmp) {
//                             if (j+1<p.size() && p[j+1] == '*') {
//                                 j+=2;
//                                 if (j == p.size()) break;
//                                 continue;
//                             }
//                             ++j;
//                             ++n;
//                             if (j == p.size()) return false;
//                             continue;
//                         }
//                         if (p[j] == s[i] || p[j] == '.') break;
//                         if (j+1<p.size() && p[j+1] == '*') {
//                             j+=2;
//                             if (j == p.size()) break;
//                         } else {
//                             return false;
//                         }
//                     }
//                 }
//                 if (m < n) return false;
//                 continue;
//             }
//             if (s[i] == p[j] || p[j] == '.') {
//                 ++i;
//                 ++j;
//             } else {
//                 return false;
//             }
//         }
//         if (j == p.size()) return true;
//         while (j+1<p.size() && p[j+1] == '*') {
//             j+=2;
//             if (j == p.size()) return true;
//         }
//         return false;
//     }
//
//     bool isMatch(string s, string p) {
//         int te = 0, st = 0;
//         while (!test(s, p, te)) {
//             ++st;
//             te = st;
//             if (te == 4) return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;

        auto match = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                return true;
            }
            return false;
        };

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (match(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (match(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};




int main() {
    string s = "cbaacacaaccbaabcb";
    string p = "c*b*b*.*ac*.*bc*a*";
    Solution solution;
    bool answer = solution.isMatch(s, p);
    cout << answer << '\n';
    return 0;
}
