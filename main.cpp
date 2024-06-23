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




    return 0;

}

