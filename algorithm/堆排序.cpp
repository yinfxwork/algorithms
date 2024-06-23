#include <iostream>
#include <vector>
#include  <ctime>
#include <iomanip>
using namespace std;

static vector<int> t;



void heapSort(vector<int> &v, int index, int len) {
    int l = index * 2 + 1, r = index * 2 + 2;
    int maxi = index;
    if (l < len && v[l] > v[maxi]) maxi = l;
    if (r < len && v[r] > v[maxi]) maxi = r;
    if (maxi != index) {
        swap(v[index], v[maxi]);
        heapSort(v, maxi, len);
    }
}

int main() {
    clock_t start, end;


    vector<int> v{10, 5, 3, 1, 7, 5, 2,1,1,1,1,1,1,1,5,3,2,5,6,2,7,23,99,45,34,63,24,76};
    int len = v.size();
    t.reserve(len);
    start = clock();
    for (int i = len / 2 - 1; i >= 0; --i) {
        heapSort(v, i, len);
    }
    for (int i = len - 1; i > 0; --i) {
        swap(v[0], v[i]);
        heapSort(v, 0, i);
    }

    end = clock();


    for (auto i : v) {
        cout << i << " ";
    }
    cout << '\n' << 1 <<'\n';
    cout << '1' <<'\n';
    cout << setiosflags(ios::fixed) <<static_cast<double>(end-start)/(CLOCKS_PER_SEC/1000) << endl;



    return 0;

}

