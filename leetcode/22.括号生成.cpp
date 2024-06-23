#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 回溯法复制分法
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        // ans.reserve();
        generate(ans, s, n, 0, 0);
        return ans;
    }

    void generate(vector<string>& ans, string s, int& n, int i, int j) {
        if (j == n) ans.push_back(s);
        else {
            if (i <= j) {
                generate(ans, s+'(', n, i+1, j);
            } else if(i == n) {
                generate(ans, s+')', n, i, j+1);
            }
            else {
                generate(ans, s+'(', n, i+1, j);
                generate(ans, s+')', n, i, j+1);
            }
        }
    }
};

int main() {
    int n = 8;
    Solution solution;
    vector<string> answer = solution.generateParenthesis(n);
    int i = 0;
    for (; i < answer.size(); ++i) {
        cout << answer[i] << '\n';
    }
    cout << i;
    return 0;
}