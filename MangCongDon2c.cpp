#include <iostream>
#include <vector>

using namespace std;

constexpr int maxSize = 10000;
int a[maxSize + 1][maxSize + 1];
int prefix[maxSize + 1][maxSize + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin >> n >> m >> q;   /// nhập kích thước mảng n x m
    for ( int i = 1; i <= n; i ++ ){
        for ( int j = 1; j <= m; j ++)
            cin >> a[i][j];     ///nhập mảng
    }
    for ( int i = 1; i <= n; i ++){
        for ( int j = 1; j <= m; j ++){   /// tạo mảng cộng dồn prefix
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
        }
    }
    int row1,row2,col1,col2;
    int sum;
    for ( int i = 1; i <= q; i ++){  /// cần tính
        cin >> row1 >> row2 >> col1 >> col2;
        sum = prefix[row2][col2] - prefix[row1-1][col2] - prefix[row2][col1-1] + prefix[row1-1][col1-1];
        cout << sum << endl;
    }

    return 0;
}
/// độ phức tạp O(m*n*2 + q)
/// mảng prefix: prefix[i][j] là tổng các phần tử từ trong hình chữ nhật i*j
/// cách tìm tổng các phần tử dòng r1 cột c1 đến r2, c2: prefix[r2][c2] - prefix[r2][c1-1] - prefix[r1-1][c2] + prefix[r1-1][c1-1]
///dTrucinUET


