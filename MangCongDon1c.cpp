/// nhập mảng a có n phần tử
/// nhập q truy vấn gồm x<y
/// tính tổng các phần tử từ a[x] tới a[y]
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;  /// nhập số phần tử n của mảng
    int a[n + 1];
    int prefix[n] = {0};  /// predix có dạng {0, pre1,pre2,....}
    for ( int i = 1; i <= n; i ++){
        cin >> a[i];              /// nhập mảng
        prefix[i] = prefix[i-1] + a[i]; /// tình predix {0;0 + a1; pre1 + a2,....}
    }
    int q; cin >> q;    /// số truy vấn q
    for ( int i = 1; i <= q; i ++){
        int x,y; cin >> x >> y;    /// nhập độ dài cần tính
        int sum = prefix[y] - prefix[x-1];
        cout << sum << endl;
    }

    return 0;
}
/// độ phức tạp O(n)
///dTrucinUET
