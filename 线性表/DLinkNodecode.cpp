/*
 * @Author: seceast
 * @Date: 2020-10-13 10:55:09
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-13 15:18:47
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode * prior;
    struct DNode * next;
}DLinkNode;

//建立
//头插法
void CreateListF(DLinkNode *&L,ElemType a[],int n){
    DLinkNode *s;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));       //创建头节点
    L->prior = L->next=NULL;                        //前后指针域置为空
    for(int i= 0;i<n;i++){
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];                               //创建数据节点
        s->next=L->next;
        if(L->next!=NULL)
            L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
}

//尾插法
void CreateListR(DLinkNode *&L,ElemType a[],int n){
    DLinkNode *s,*r;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    r=L;                                           //r始终指向尾节点，开始时指向头节点
    for(int i=0;i<n;i++){
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        r->next=s;s->prior=r;                      //将s插入r之后
        r=s;
    }
    r->next=NULL;
}

//插入
bool ListIsert(DLinkNode *& L,int i,ElemType e){
    int j = 0;
    DLinkNode *p=L,*s;
    if(i<0)return false;
    while (j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=e;
        s->next=p->next;
        if(p->next!=NULL)
            p->next->prior=s;
        s->prior=p;
        p->next=s;
        return true;
    }
    
}