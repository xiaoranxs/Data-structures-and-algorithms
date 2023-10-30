/*
 * @Author: xiaoran
 * @Date: 2023-09-23 20:40:02
 * @LastEditTime: 2023-09-23 20:47:53
 * @Description: 散列查找 O(1) 自定义
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;
const int RANGE = 1e6;

bool hashTable[RANGE];
int arr[MAXN];

int main() {
    int n, m;
    cin >> n;  // 查找序列大小
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        hashTable[arr[i]] = true;
    }

    cin >> m;  // 查找次数
    while (m--) {
        int target;
        cin >> target;
        if (hashTable[target]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}