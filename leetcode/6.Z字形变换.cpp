#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int left = 2 * (numRows - 1);
        int right = 0;
        int i = 0, j = 0;
        if (numRows == 1 || s.size() <= numRows) return s;
        while (true){
            if (j == numRows) break;
            if (left != 0) {
                ans += s[i];
                i += left;
            }
            if (i >= s.size()) {
                ++j;
                i = j;
                left -= 2;
                right += 2;
                continue;
            }
            if (right != 0) {
                ans += s[i];
                i += right;
            }
            if (i >= s.size()) {
                ++j;
                i = j;
                left -= 2;
                right += 2;
            }
        }
        return ans;
    }
};


int main() {
    string s = "PAYPALISHIRING";
    int numRows = 1;
    Solution solution;
    string answer = solution.convert(s, numRows);
    cout << answer;
    return 0;
}
