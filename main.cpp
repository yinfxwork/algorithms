#include <iostream>
#include <vector>
#include  <ctime>
#include <iomanip>
using namespace std;




void mySort(int f, int t, int n, int& ans) {
    if(n==1) {
        cout << "从" << f <<"到" << t<<"   第"<<ans  << "\n";
    }
    if (n){
        ++ans;
        mySort(f, 6-f-t, n-1, ans);
        mySort(6-f-t, t, n-1, ans);
    }
}





int main() {

    clock_t start, end;
    // int arr[]{45,34,63,-24,76};
    // vector<int> v{10, 5, 3, 1, 7, 5, 2,1,1,1,1,1,1,1,5,3,2,5,6,2,7,23,99,45,34,63,24,76};
    // int len = sizeof(arr)/sizeof(int);



    start = clock();
    int ans = 0;
    mySort(1, 3, 4, ans);

    cout << ans << '\n';



    end = clock();



    // for (int i = 0; i < len; ++i) {
    //     cout << arr[i] << " ";
    // }
    cout << '\n' << 1 <<'\n';
    cout << '1' <<'\n';
    cout << setiosflags(ios::fixed) <<static_cast<double>(end-start)/(CLOCKS_PER_SEC/1000) << endl;



    return 0;

}

