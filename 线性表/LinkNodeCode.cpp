/*
 * @Author: seceast
 * @Date: 2020-10-12 10:13:57
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-13 10:54:25
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

//求某元素值
bool GetElem(LinkNode * L,int i,ElemType & e){
    int j=0;
    LinkNode *p=L;
    if(i<=0) return false;
    while (j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}

//按元素值查找
int LocateElem(LinkNode *L,ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while (p!=NULL && p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p=NULL)
        return (0);
    else
        return (i);
}

//插入元素
bool ListInsert(LinkNode *&L,int i,ElemType e){
    int j =0;
    LinkNode *p=L,*s;
    if(i<=0) return false;
    while (j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next = p->next;
        p->next=s;
        return true;
    }
    
}

//单链表逆置
void Reverse(LinkNode *& L){
    LinkNode *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        p->next = L->next;
        L->next=p;
        p=q;
    }
    
} 