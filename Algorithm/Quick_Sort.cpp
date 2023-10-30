/*
 * @Author: xiaoran
 * @Date: 2023-09-23 10:43:32
 * @LastEditTime: 2023-09-23 11:40:36
 * @Description: 快速排序的实现
 */

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN];  // 存储输入数组

int Partition(int left, int right){  // 随机选择一个数并确定其位置（返回，将数组分为左右两部分
    int random = left + rand() % (right - left + 1);
    swap(arr[left], arr[random]);

    while (left < right) {
        while (left < right && arr[left] <= arr[right]) {  // 选定数在left位置
            right--;
        }
        swap(arr[left], arr[right]);
        while (left < right && arr[left] <= arr[right]) {  // 选定数在right位置
            left++;
        }
        swap(arr[left], arr[right]);
    }

    return left;  // left == right == 选定数
}

void QuickSort(int left, int right){
    if (left < right){
        int position = Partition(left, right);
        QuickSort(left, position -1);
        QuickSort(position + 1, right);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }  // 数据输入

    QuickSort(0, n-1);  // 快排
    
    for (int i=0; i<n; i++){
        cout << arr[i];
    }
    cout << endl;  // 输出

    return 0;
}
