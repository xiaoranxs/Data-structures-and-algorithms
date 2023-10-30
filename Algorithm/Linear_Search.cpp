/*
 * @Author: xiaoran
 * @Date: 2023-09-23 19:55:37
 * @LastEditTime: 2023-09-23 20:10:54
 * @Description: 查找算法之线性查找 O(n)
 */

#include <iostream>
using namespace std;

const int MAXN = 100 + 10;
int arr[MAXN];

bool LinearSearch(int n, int target) {
    for (int i=0; i<n; i++) {
        if( arr[i] == target ) { return true; }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n;  // 查找序列大小
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    cin >> m;  // 查找次数
    while (m--) {
        int target;
        cin >> target;
        if (LinearSearch(n, target)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}