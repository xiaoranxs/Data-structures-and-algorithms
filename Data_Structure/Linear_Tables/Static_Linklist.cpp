/*
 * @Author: xiaoran
 * @Date: 2023-10-08 15:06:47
 * @LastEditTime: 2023-10-08 16:45:23
 * @Description: 线性表的静态链表存储结构--用数组描述的链表
 */

#include <iostream>
using namespace std;

#define MAXSIZE 20    // 初始分配空间大小
#define OK 1    // 成功信号量
#define ERROR 0    // 失败信号量
#define TRUE 1
#define FALSE 0
typedef int ElemType;    // 定义数据类型
typedef int Status;    // 

#define MAXSIZE 10    // 假设最大长度为1000
typedef struct
{
    ElemType data;
    int cur;    // 游标，为0时表示无指向
} Component, StaticLinkList[MAXSIZE];

// 将一维数组space中各分量链成一备用链表
// space[0].cur为头指针，0表示空指针
Status InitList (StaticLinkList& space)
{
    for (int i=0; i<MAXSIZE-1; i++)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;    // 目前静态链表为空，最后一个元素的cur为0

    return OK;
}

// 若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL (StaticLinkList space)
{
    int i = space[0].cur;  // space[0].cur为第一个备用空闲的下标

    if (space[0].cur)
        space[0].cur = space[i].cur;    // 由于要拿一个分量来使用，所以把它的下一个分量用来做备用
    
    return i;
}

// 将下标为k的空闲结点回收到备用链表
void Free_SSL (StaticLinkList& space, int k)
{
    space[k].cur = space[0].cur;    // 把第一个元素cur值赋给要删除的分量cur
    space[0].cur = k;    // 把要删除的分量下标赋值给第一个元素的cur
}

// 静态链表L已存在，返回L中数据元素个数
int ListLength (StaticLinkList& L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;    // 最后一位的cur指向第一个有值的元素下标
    while (i)
    {
        i = L[i].cur;
        j++;
    }

    return j;
}

// 在L中第i个元素之前插入新的数据e
Status ListInsert (StaticLinkList& L, int i, ElemType e)
{
    int j, k;
    k = MAXSIZE - 1;    // L[MAXSIZE-1].cur为第一个有值元素的下标

    if (i<1 || i>ListLength(L)+1)    // 下标越界
        return ERROR;

    j = Malloc_SLL(L);    // 获得空闲分量的下标
    if (j)
    {
        L[j].data = e;    // 赋值
        for (int l=1; l<=i-1; l++)    // 找到第i个元素之前的位置
            k = L[k].cur;
        L[j].cur = L[k].cur;    // 把第i个元素之前的cur赋值给新元素的cur
        L[k].cur = j;    // 把新元素的下标赋值给第i个元素之前元素的cur

        return OK;
    }
}

// 删除在L中第i个数据元素e
Status ListDelete (StaticLinkList& L, int i)
{
    int j;
    if (i<1 || i>ListLength(L))
        return ERROR;
    
    int k = MAXSIZE - 1;
    for (j=1; j<=i-1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);

    return OK;
}

// 测试程序
int main() 
{
    StaticLinkList L;
    InitList(L);
    cout << "Length of list is " << ListLength(L) << endl;
    ListInsert(L, 1, 114514);
    cout << "Length of list is " << ListLength(L) << endl;
    ListDelete(L, 1);

    return 0;
}
