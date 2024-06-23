#include <iostream>
#include <vector>
using namespace std;


// 一个一个取出比较，直到中点
// class Solution
// {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         int mm = 0, nn = 0;
//         bool mmm = true, nnn = true;
//         double le, ri;
//         int left = (m+n+1)/2, right = (m+n+2)/2;
//         for (int i = 0; i < right; ++i) {
//             if (i == left-1) {
//                 if ((nums1[mm] < nums2[nn] || !nnn)&&mmm) {
//                     le = nums1[mm];
//                 } else {
//                     le = nums2[nn];
//                 }
//             }
//             if (i == right-1) {
//                 if ((nums1[mm] < nums2[nn] || !nnn)&&mmm) {
//                     ri = nums1[mm];
//                 } else {
//                     ri = nums2[nn];
//                 }
//             }
//             if ((nums1[mm] < nums2[nn] || !nnn) && mmm) {
//                 mm++;
//             } else{
//                 nn++;
//             }
//             if (mm==m && nnn) mmm=false;
//             if (nn==n && mmm) nnn=false;
//         }
//         return (le+ri)/2;
//     }
// };


// 递归，依次减少k/2,k/4直到k=1。当一个数组数少时，比较其最后一个，可以直接得出。
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k1 = (m + n + 1) / 2;
        int k2 = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, k1) + findKth(nums1, 0, nums2, 0, k2)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        int m = nums1.size(), n = nums2.size();
        if (i == m) return nums2[j + k - 1];
        if (j == n) return nums1[i + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        int a = min((i + k/2), m);
        int b = min((j + k/2), n);
        if (nums1[a-1] < nums2[b-1]) {
            return findKth(nums1,  a, nums2, j, k - a + i);
        } else {
            return findKth(nums1, i, nums2,  b, k - b + j);
        }
    }
};

// 用while代替递归
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         int k1 = (m + n + 1) / 2;
//         int k2 = (m + n + 2) / 2;
//         if ((m+n)%2==0) {
//             return (findKth(nums1, nums2, k1) + findKth(nums1, nums2, k2)) / 2.0;
//         } else {
//             return findKth(nums1, nums2, k1);
//         }
//     }
//     int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
//         int m = nums1.size(), n = nums2.size();
//         int i = 0, j = 0;
//         int a, b;
//         while (true) {
//             if (i == m) return nums2[j + k - 1];
//             if (j == n) return nums1[i + k - 1];
//             if (k == 1) return min(nums1[i], nums2[j]);
//             a = min((i + k/2), m);
//             b = min((j + k/2), n);
//             if (nums1[a-1] < nums2[b-1]) {
//                 k = k - a + i;
//                 i = a;
//             } else {
//                 k = k - b + j;
//                 j = b;
//             }
//         }
//     }
// };


// 用vector容器，每次建立新的数组时淘汰一个数组或k/2
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int k1 = (m + n + 1) / 2;
//         int k2 = (m + n + 2) / 2;
//         return (findKth(nums1, nums2, k1) + findKth(nums1, nums2, k2)) / 2.0;
//     }
//     int findKth(vector<int> nums1, vector<int> nums2, int k) {
//         if (nums1.empty()) return nums2[k - 1];
//         if (nums2.empty()) return nums1[k - 1];
//         if (k == 1) return min(nums1[0], nums2[0]);
//         int i = min((int)nums1.size(), k / 2), j = min((int)nums2.size(), k / 2);
//         if (nums1[i - 1] > nums2[j - 1]) {
//             return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
//         } else {
//             return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
//         }
//     }
// };


// 分割法，找两个数组各自与中点相近的分割点。
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size(), n = nums2.size();
//         if (m < n) return findMedianSortedArrays(nums2, nums1);
//         if (n == 0) return (nums1[(m - 1) / 2] + nums1[m / 2]) / 2.0;
//         int left = 0, right = n * 2;
//         while (left <= right) {
//             int mid2 = (left + right) / 2;
//             int mid1 = m + n - mid2;
//             double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
//             double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
//             double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
//             double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
//             if (L1 > R2) left = mid2 + 1;
//             else if (L2 > R1) right = mid2 - 1;
//             else return (max(L1, L2) + min(R1, R2)) / 2;
//         }
//         return -1;
//     }
// };



int main() {
    int nums1[] = {2};
    int nums2[] = {1};
    vector<int> v_nums1(nums1, nums1 + sizeof(nums1) / sizeof(int));
    vector<int> v_nums2(nums2, nums2 + sizeof(nums2) / sizeof(int));
    Solution solution;
    double answer = solution.findMedianSortedArrays(v_nums1, v_nums2);
    cout << answer << '\n';
    return 0;
}

