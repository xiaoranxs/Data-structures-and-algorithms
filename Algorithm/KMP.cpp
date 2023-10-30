/*
 * @Author: xiaoran
 * @Date: 2023-09-24 19:58:04
 * @LastEditTime: 2023-09-24 21:20:32
 * @Description: 字符串匹配算法 -- KMP
 */

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100;

int nextTable[MAXN];

void GetNextTable(string pattern) {  // 对pattern构造next表
    int m = pattern.size(); 
    int j=0;

    nextTable[j] = -1; 
    int t = nextTable[j];

    while (j < m) {
        if(t==-1 || pattern[j] == pattern[t]) {
            t++;
            j++;
            nextTable[j] = t;
        } else {
            t = nextTable[t];
        }
    }
}

int KMP(string text, string pattern) {  // 返回第一次匹配成功位置
    GetNextTable(pattern);  // 计算next数组

    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;

    while (i<n && j<m) {
        if (j==-1 || text[i]==pattern[j]) {
            i++;
            j++;
        } else {
            j = nextTable[j];
        }
    }

    if (j == m) {
        return i - j;  // 匹配完在字符串后面，须回到字符串开头
    } else {
        return -1;
    }
}

int KMP2(string text, string pattern) {  // 统计匹配次数
    GetNextTable(pattern);  // 计算next数组

    int n = text.size();
    int m = pattern.size();
    int i = 0;
    int j = 0;
    int number = 0;

    while (i<n) {
        if (j==-1 || text[i]==pattern[j]) {
            i++;
            j++;
        } else {
            j = nextTable[j];
        }

        if (j==m) {
            number++;
            j = nextTable[j];  // 允许字符重复匹配
            // j = 0;          // 不允许字符重复匹配
        }
    }

    return number;
}


int main() {
    string text, pattern;
    cin >> text >> pattern;
    
    int position = KMP(text, pattern);  // 返回第一次匹配成功下标
    int count = KMP2(text, pattern);  // 统计匹配次数

    cout << position << endl << count << endl;
}