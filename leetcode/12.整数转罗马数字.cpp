#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        int n = num/1000;
        num %= 1000;
        s.append(n, 'M');
        if (num >= 900) {
            num %= 900;
            s += "CM";
        }
        if (num >= 500) {
            num %= 500;
            s += "D";
        }
        if (num >= 400) {
            num %= 400;
            s += "CD";
        }
        n = num/100;
        num %= 100;
        s.append(n, 'C');
        if (num >= 90) {
            num %= 90;
            s += "XC";
        }
        if (num >= 50) {
            num %= 50;
            s += "L";
        }
        if (num >= 40) {
            num %= 40;
            s += "XL";
        }
        n = num/10;
        num %= 10;
        s.append(n, 'X');
        if (num >= 9) {
            num %= 9;
            s += "IX";
        }
        if (num >= 5) {
            num %= 5;
            s += "V";
        }
        if (num >= 4) {
            num %= 4;
            s += "IV";
        }
        s.append(num, 'I');
        return s;
    }
};

int main() {
    int num = 994;
    Solution solution;
    string answer = solution.intToRoman(num);
    cout << answer << '\n';
    return 0;
}
