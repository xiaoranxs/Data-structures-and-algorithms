/*
 * @Author: xiaoran
 * @Date: 2023-10-04 19:52:02
 * @LastEditTime: 2023-10-07 23:35:18
 * @Description: 线性表的顺序存储实现
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

typedef struct
{
    ElemType data[MAXSIZE];    // 数组储存数据元素
    int length;    // 当前长度
}SqList;

// 初始条件：顺序线性表L已存在
// 操作结果：将L的长度置为0
Status InitList (SqList *L)
{
    L->length = 0;

    return OK;
}

// 初始条件：顺序线性表L已存在
// 操作结果：若线性表为空，返回true，否则返回false
bool ListEmpty (SqList *L)
{
    return !L->length;
}

// 初始条件：顺序线性表L已存在
// 操作结果：将线性表清空
Status ClearList (SqList *L)
{
    L->length = 0;    // 不必真清空表，只需将表长置为0，以写入新数据覆盖原数据

    return OK;
}

// 初始条件：顺序线性表L已存在，1<= i <= ListLength(L)
// 操作结果：用e返回L中第i个数据元素的值
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length==0 || i<1 || i>L.length)    // 空表or下标越界，则获取失败
        return ERROR;    
    *e = L.data[i-1];    // 数组下标从0开始，线性表下标从1开始
    return OK;
}

// 初始条件：顺序线性表L已存在，e为要查找的元素
// 操作结果：查找成功则返回序号（从1开始），否则返回0表示失败
int LocateElem (SqList *L, ElemType e)
{
    for (int i=0; i< L->length; i++) 
    {
        if (L->data[i] == e) 
            return i+1; 
    }

    return 0;
}

// 初始条件：顺序线性表L已存在，1<= i <= ListLength(L)
// 操作结果：在L中第i个位置之前插入新的元素e，L长度加1
Status ListInsert (SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE)    // 表满
        return ERROR;
    if (i<1 || i>L->length+1)    // 下标越界
        return ERROR;
    
    if (i <= L->length)    // 插入位置不在表尾
    {
        for(int k=L->length-1; k>= i-1; k--)
            L->data[k+1] = L->data[k];    // 从i-1开始所有元素往后移一位
    }
    L->data[i-1] = e;    // 插入
    L->length++;    // 表长度+1

    return OK;
}

// 初始条件：顺序线性表L已存在，1<= i <= ListLength(L)
// 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
Status ListDelete (SqList *L, int i, ElemType *e)
{
    if (L->length == 0)    // 表空
        return ERROR;
    if (i<1 || i>L->length)    // 删除位置越界
        return ERROR;

    *e = L->data[i-1];    // 取值
    if (i < L->length)    // 若删除位置不在表尾
    {
        for (int k=i; k<L->length; k++)    // 将删除位置后继元素前移
            L->data[k-1] = L->data[k];
    }
    L->length--;    // 长度-1

    return OK;
}

// 初始条件：顺序线性表L已存在
// 操作结果：返回线性表L的元素个数
int ListLength (SqList *L)
{
    return L->length;
}

// 顺序打印线性表
Status Show (SqList *L)
{
    for (int i=0; i < L->length; i++)
    {
        cout << "# " << i+1 << ": " << L->data[i] << endl;
    }
    cout << "The end!\n";

    return OK;
}

// 测试程序
int main() {
    SqList L;
    
    InitList(&L);
    cout << "T/F: " << ListEmpty(&L) << endl;
    
    ListInsert(&L, 1, 3);
    cout << "T/F: " << ListEmpty(&L) << endl;

    cout << "Locate 3: " << LocateElem(&L, 6) << endl;
    
    Show(&L);
    
    int e;
    GetElem(L, 1, &e);
    cout << "e: " << e << endl;

    return 0;
}