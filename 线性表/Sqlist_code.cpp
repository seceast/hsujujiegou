/*
 * @Author: seceast 
 * @Date: 2020-09-29 09:34:53 
 * @Last Modified by: seceast
 * @Last Modified time: 2020-09-29 09:47:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;

#define LIST_INIT_SIZE 100
typedef struct 
{
    ElemType data[LIST_INIT_SIZE];
    int length;
}SqList;

//创建顺序表
void CreateList(SqList * &L,ElemType a[],int n)     //由a中的n个元素建立顺序表
{
    int i = 0,k = 0;
    L=(SqList*)malloc(sizeof(SqList));              //分配空间
    while (i<n)
    {
        L->data[k]=a[i];
        k++;i++;
    }
    L->length=k;
}

//初始化线性表
Status InitList(SqList * &L){                      
    L= (SqList*)malloc(sizeof(SqList));
    L->length = 0;
}

//线性表逆序
void Inversion(SqList *L)                          
{
    int a,b,i;
    a = L->length;
    for (i = 1;i <= a/2;i++){
        b = L->data[i-1];
        L->data[i-1] = L->data[a-i];
        L->data[a-i] = b;
    }
} 

//销毁线性表
void DestroyList(SqList * & L)
{
    free(L);
}

//判断是否为空
bool ListEmpty(SqList * L)
{
    return (L->length==0);
}

//求长度
int ListLength(SqList * L)
{
    return (L->length);
}

//输出线性表
void DispList(SqList * L)
{
    for (int i = 0;i<L->length;i++){
        printf("%d",L->data[i]);
    }
    printf("\n");
}

//
