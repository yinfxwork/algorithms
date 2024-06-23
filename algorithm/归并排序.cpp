#include <iostream>
#include <vector>
#include  <ctime>
#include <iomanip>
using namespace std;

static vector<int> t;



void merge(vector<int> &v, int start, int mid, int end) {

    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (v[i] <= v[j]) {
            t[k++] = v[i++];
        } else {
            t[k++] = v[j++];
        }
    }
    while (i <= mid) {
        t[k++] = v[i++];
    }
    while (j <= end) {
        t[k++] = v[j++];
    }
    for (;start <= end; end--, k--) {
        v[end] = t[k - 1];
    }
}

void mergeSort(vector<int> &v, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (end + start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    merge(v, start, mid, end);
}



int main() {
    clock_t start, end;

    vector<int> v{10, 5, 3, 1, 7, 5, 2,1,1,1,1,1,1,1,5,3,2,5,6,2,7,23,99,45,34,63,24,76};
    t.reserve(v.size());
    // start = clock();
    // mergeSort(v, 0, v.size() - 1);
    // end = clock();

    int len = v.size();
    for (int seg = 1; seg < len; seg *= 2) {
        for (int i = 0; i < len; i += 2 * seg) {
            int k = i;
            int mid = min(i + seg, len);
            int high = min(i + 2 * seg, len);
            int s1 = i, e1 = mid;
            int s2 = mid, e2 = high;
            while (s1 < e1 && s2 < e2) {
                t[k++] = v[s1] < v[s2] ? v[s1++] : v[s2++];
            }
            while (s1 < e1) {
                t[k++] = v[s1++];
            }
            while (s2 < e2) {
                t[k++] = v[s2++];
            }
            --k;
            for (;k >= i; --k) {
                v[k] = t[k];
            }
        }
    }



    for (auto i : v) {
        cout << i << " ";
    }
    cout << '\n' << 1 <<'\n';
    cout << '1' <<'\n';
    cout << setiosflags(ios::fixed) <<static_cast<double>(end-start)/(CLOCKS_PER_SEC/1000) << endl;



    return 0;

}

