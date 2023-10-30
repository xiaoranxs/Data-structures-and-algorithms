/*
 * @Author: xiaoran
 * @Date: 2023-09-24 13:51:34
 * @LastEditTime: 2023-09-24 14:21:49
 * @Description: 归并排序 O(NlogN) 分治法
 */

#include <iostream>
using namespace std;

const int MAXN = 1000 + 10;
int arr[MAXN], temp[MAXN];  // 输入数组、辅助数组

void Combine(int left, int middle, int right) {
    int i=left, j=middle+1, k=left;
    
    while(i <= middle && j <= right) {  // 从两个队列中循环选出最小值赋给辅助数组
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= middle) {  // 序列剩余部分直接复制
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int i=left; i<=right; i++) {  // 辅助数组复制给源数组
        arr[i] = temp[i];
    }
}

void MergeSort(int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;  // 防止直接相加的数据溢出
        MergeSort(left, middle);  // 递归处理
        MergeSort(middle+1, right);
        Combine(left, middle, right);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    MergeSort(0, n-1);  // 参数为下标
    
    for (int i=0l; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
