/*
 * @Author: xiaoran
 * @Date: 2023-09-23 19:55:37
 * @LastEditTime: 2023-09-23 20:25:25
 * @Description: 查找算法之二分查找 O(logn) 要求序列有序
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;
int arr[MAXN];

bool BinarySearch(int n, int target) {
    int left = 0, right = n-1;
    int middle;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (arr[middle] < target) {
            left = middle + 1;
        } else if (arr[middle] > target) {
            right = middle - 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n;  // 查找序列大小
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);  // 二分查找要求序列有序

    cin >> m;  // 查找次数
    while (m--) {
        int target;
        cin >> target;
        if (BinarySearch(n, target)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}