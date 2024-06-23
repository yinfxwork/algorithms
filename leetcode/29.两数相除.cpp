#include <iostream>
using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        bool flag = false;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend<0 && divisor>0 || dividend>0 && divisor<0) flag = true;
        dividend = dividend<0 ? dividend : -dividend;
        divisor = divisor<0 ? divisor : -divisor;
        while (dividend <= divisor) {
            int d = divisor, q = 1;
            while (d >= dividend-d) {
                d <<= 1;
                q <<= 1;
            }
            dividend -= d;
            ans += q;
        }
        return flag ? -ans : ans;
    }
};




int main() {
    int m = 10;
    int n = 3;
    Solution solution;
    int answer = solution.divide(m, n);
    cout << answer << '\n';
    return 0;
}