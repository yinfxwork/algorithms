#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//回溯法
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> ans;
//         unordered_map<char, string> hashtable {
//             {'2', "abc"},
//             {'3', "def"},
//             {'4', "ghi"},
//             {'5', "jkl"},
//             {'6', "mno"},
//             {'7', "pqrs"},
//             {'8', "tuv"},
//             {'9', "wxyz"}
//         };
//         if (digits.empty()) return ans;
//         string tmp;
//         combine(ans, tmp, 0, digits, hashtable);
//         return ans;
//     }
//
//     void combine(vector<string>& ans, string& tmp, int i, string& digits, unordered_map<char, string>& hashtable) {
//         if (i == digits.size()) {
//             ans.push_back(tmp);
//         } else {
//             string word = hashtable.at(digits[i]);
//             for (int j = 0; j < word.size(); ++j) {
//                 tmp.push_back(word[j]);
//                 combine(ans, tmp, i+1, digits, hashtable);
//                 tmp.pop_back();
//             }
//         }
//     }
// };


// 队列法
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans{""};
        ans.reserve(150);
        unordered_map<char, string> hashtable {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };
        if (digits.empty()) {
            ans.erase(ans.begin());
            return ans;
        }
        string tmp;
        for (char& i : digits) {
            int n = ans.size();
            for (int j = 0; j < n; ++j) {
                tmp = ans[0];
                ans.erase(ans.begin());
                for (auto& k : hashtable.at(i)) {
                    ans.push_back(tmp + k);
                }
            }
        }
        return ans;
    }
};


int main() {
    string s = "23";
    Solution solution;
    vector<string> answer = solution.letterCombinations(s);
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << '\n';
    }
    return 0;
}