#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        if (s == "") return s;
        int n = strs.size();
        int j, num;
        for (int i = 1; i < n; ++i) {
            j = 0;
            num = min(s.size(), strs[i].size());
            while (s[j] == strs[i][j]){
                ++j;
                if (j == num) break;
            }
            if (j == 0) return "";
            s = s.substr(0, j);
        }
        return s;
    }
};


int main() {
    vector<string> strs{""};
    Solution solution;
    string answer = solution.longestCommonPrefix(strs);
    cout << answer << '\n';
    return 0;
}