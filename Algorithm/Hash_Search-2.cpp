/*
 * @Author: xiaoran
 * @Date: 2023-09-23 20:48:07
 * @LastEditTime: 2023-09-23 20:50:28
 * @Description: 散列查找 O(1) 内置函数
 */

#include <iostream>
#include <unordered_map>
using namespace std;

const int MAXN = 100 + 10;
const int RANGE = 1e6;

unordered_map<int, bool> hashTable;
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