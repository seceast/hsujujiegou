/*
 * @Author: seceast
 * @Date: 2020-10-12 10:13:57
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-12 16:06:18
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;


//类型声明
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    
}LinkNode;

//建立单链表
//1头插法
void CreateListF(LinkNode *& L,ElemType a[],int n){
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    for (int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

//2尾插法
void CreateListR(LinkNode *& L,ElemType a[],int n)
{
    LinkNode *s ,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r=s;
    }
    r->next = NULL;
}

//初始化
void InitList(LinkNode *& L){
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next =NULL;
}

