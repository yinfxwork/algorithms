#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(int x) {
    }
};


int main() {
    int nums[] = {2};
    vector<int> v_nums(nums, nums + sizeof(nums) / sizeof(int));
    Solution solution;
    int answer = solution(v_nums);
    cout << answer << '\n';
    return 0;
}