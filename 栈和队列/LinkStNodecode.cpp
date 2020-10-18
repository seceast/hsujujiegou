/*
 * @Author: seceast
 * @Date: 2020-10-18 11:24:47
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-18 17:14:47
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 50 

typedef int ElemType;

typedef struct linknode
{
    ElemType data;
    struct linknode * next;
}LinkStNode;

//初始化
void InitStack(LinkStNode *& s){
    s=(LinkStNode *)malloc(sizeof(LinkStNode));
    s->next=NULL;
}

//销毁栈
void DestroyStack(LinkStNode *& s){
    LinkStNode *pre =s,*p=s->next;       //pre指向头结点，p指向首结点
    while (p!=NULL)                      //循环到p为空
    {
        free(pre);
        pre=p;
        p=pre->next;
    }
    free(pre);
}

//判断空  return(s->next==NULL)
//进栈
void Push(LinkStNode *& s,ElemType e){
    LinkStNode *p;
    p=(LinkStNode *)malloc(sizeof(LinkStNode));
    p->data=e;
    p->next=s->next;
    s->next=p;
}

//出栈
bool  Pop(LinkStNode *& s,ElemType &e){
    LinkStNode *p;
    if(s->next==NULL)
        return false;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
    return true;
}

//取栈顶值
bool GetTop(LinkStNode *&s,ElemType e){
    if (s->next==NULL)
        return false;
    e=s->next->data;              
    return true;
}
