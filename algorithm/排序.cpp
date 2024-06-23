#include <iostream>
#include <vector>

using namespace std;

// 二分查找
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 快速排序
int partition(vector<int>& nums, int left, int right) {
    return 1;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
}

