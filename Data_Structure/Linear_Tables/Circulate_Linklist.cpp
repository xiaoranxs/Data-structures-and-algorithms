/*
 * @Author: xiaoran
 * @Date: 2023-10-25 16:47:31
 * @LastEditTime: 2023-10-26 11:06:26
 * @Description: 循环链表实现
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

// 线性表的循环链表存储结构
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;    // 定义LinkList

// 初始条件：循环链表L已存在
// 操作结果：返回循环链表L的元素个数（不算头结点）
int ListLength (LinkList *L)
{
    LinkList p;
    p = (*L)->next;    // 指向循环链表头结点的下一个结点
    int i=0;    // 计数器，头结点算0号结点
    
    while(p != *L)
    {
        p = p->next;
        i++;
    }

    return i;
}

// 初始条件：循环链表L已存在，1<= i<= ListLength(L)
// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert (LinkList *L, int i, ElemType e)
{
    int j=1;    // 计数器
    int len = ListLength(L);    // 获取链表长度
    if (i < 1 || i > len)    // 下标越界
        return ERROR;

    LinkList p, s;
    p = *L;    // 指向循环链表头结点

    while ( j<i )    // 寻找第i个结点
    {
        p = p->next;
        ++j;
    }

    // s = (LinkList)malloc(sizeof(Node));    // 生成新结点C
    s = (LinkList)new Node;   // 生成新结点C++
    // 链表标准插入操作
    s->data = e;
    s->next = p->next;    // 将p的后继结点赋值成s的后继
    p->next = s;    // 将s赋值成p的后继

    return OK;
}

// 初始条件：循环链表L已存在，1<= i<= ListLength(L)
// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListDelete (LinkList *L, int i, ElemType *e)
{
    int j=1;    // 计数器
    LinkList p, q;
    p = *L;    // 指向循环链表头结点

    int len = ListLength(L);    // 获取链表长度
    if (i < 1 || i > len)    // 下标越界
        return ERROR;

    while ( j<i )    // 寻找第i个结点
    {
        p = p->next;
        ++j;
    }
    
    q = p->next;
    p->next = q->next;    // 社会性死亡
    *e = q->data;    // 将q结点中的数据给e
    free(q);    // 让系统回收此结点，释放内存
    
    return OK;
}

// 随机产生n个元素的值，建立带表头结点的循环链线性表L（头插法）
void CreateListHead (LinkList *L, int n)
{
    LinkList p;
    srand(time(0));    // 初始化随机数种子
    (*L) = new Node;
    (*L)->next = *L;    // 先建立一个带头结点的链表
    (*L)->data = -114514;    // 特殊值以标识头结点
    
    for (int i=0; i<n; i++)
    {
        p = (LinkList)new Node;    // 生成新结点
        p->data = rand()%100 + 1;    // 随机生成100以内的数字
        p->next = (*L)->next;
        (*L)->next = p;    // 插入到表头 
    }
}

// 随机产生n个元素的值，建立带表头结点的循环链线性表L（尾插法）
void CreateListTail (LinkList *L, int n)
{
    LinkList p, r;
    srand(time(0));
    (*L) = (LinkList)new Node;
    (*L)->data = -114514;    // 特殊值以标识头结点
    r = (*L);
    
    for (int i=0; i<n; i++)
    {
        p = (LinkList)new Node;    // 生成新结点
        p->data = rand()%100 + 1;    // 随机生成100以内的数字
        r->next = p;    // 将表尾终端结点的指针指向新结点
        r = p;    // 将当前的新结点定义为表尾终端结点
    }

    r->next = *L;    // 表示当前链表结束
}

// 初始条件：循环链表L已存在
// 操作结果：将L重置为空表
Status ClearList (LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;    // p指向第一个结点

    while (p != *L)    // 没到表尾
    {
        q = p->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL;    // 头结点指针域为空
    return OK;
}

// 初始条件：循环链表L已存在，1<= i<= ListLength(L)
// 操作结果：用e返回第i个数据元素的值
Status GetElem (LinkList L, int i, ElemType *e)
{
    int j=1;    // j为计数器
    LinkList p;    // 声明一结点p
    p = L->next;    // 让p指向链表L的第一个结点

    int len = ListLength(&L);    // 获取链表长度
    if (i < 1 || i > len)    // 下标越界
        return ERROR;

    while ( j<i )
    {
        p = p->next;    // 让p指向下一个结点，关键语句
        ++j;
    }
    
    *e = p->data;    // 取第i个元素的数据
    return OK;
}

// 初始条件：循环链表L已存在
// 操作结果：若循环链表为空，返回true，否则返回false
bool ListEmpty (LinkList *L)
{
    if (!ListLength(L))
        return TRUE;
    else
        return FALSE;
}

// 初始条件：循环链表L已存在，e为要查找的元素
// 操作结果：查找成功则返回序号（从1开始，头结点不算），否则返回0表示失败
int LocateElem (LinkList *L, ElemType e)
{
    LinkList p;
    p = (*L)->next;    // 指向循环链表头结点下一个结点
    int i=1;    // 计数器，头结点算0号结点
    
    while(p != *L)
    {
        if (p->data == e)
            return i;
        p = p->next;
        i++;
    }

    return 0;
}

// 顺序打印线性循环链表
Status Show (LinkList *L)
{
    LinkList p;
    p = (*L)->next;    // 指向链表头结点的下一个结点，不打印头结点
    int i=1;    // 计数器
    
    while(p != *L)
    {
        cout << "# " << i++ << ": " << p->data << endl;
        p = p->next;
    }
    cout << "The end!\n";

    return OK;
}

// 测试程序
int main() {
    LinkList L;
    //Node *L;    // 

    CreateListHead(&L, 3);
    Show(&L);
    cout << "Length of List is " << ListLength(&L) << endl;

    if (ListInsert(&L, 1, -5))
        cout << "Insert succeed" << endl;
    else
        cout << "Insert fail" << endl;
    Show(&L);

    ElemType e;
    ListDelete(&L, 3, &e);
    cout << "delete e: " << e << endl;
    Show(&L);

    GetElem(L, 2, &e);
    cout << "get e: " << e << endl;

    cout << "is emtpy: " << ListEmpty(&L) << endl;
    cout << "LocateElem 3 is " << LocateElem(&L, 3) << endl;

    ClearList(&L);
    return 0;
}
