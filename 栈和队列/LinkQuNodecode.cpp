/*
 * @Author: seceast
 * @Date: 2020-10-19 15:39:44
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-21 10:36:53
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType; 

//链队中数据结点类型声明
typedef struct qnode
{
    ElemType data;              //存储元素
    struct qnode *next;         //下一个结点指针
}DataNode;

//链队（头）结点声明
typedef struct{
    DataNode * front;           //指向队首结点
    DataNode * rear;            //指向队尾结点
}LinkQuNode;

//初始化
void InitQueue(LinkQuNode *&q){
    q=(LinkQuNode *)malloc(sizeof(LinkQuNode));
    q->front=q->rear=NULL;
}

//销毁 
void DestroyQueue(LinkQuNode *& q){
    DataNode *pre=q->front, *p;       //pre指向队首结点
    if(pre!=NULL){
        p=pre->next;                  //p指向pre的后继结点
        while(p!=NULL){               //p不为空循环
            free(pre);                //释放pre
            pre=p;p=p->next;          //pre和p同步后移
        }
        free(pre);                    //释放最后一个数据结点
    }
    free(q);                          //释放链队结点
}

//判断空 return(q->rear==NULL)

//进队
void enQueue(LinkQuNode *& q,ElemType e){
    DataNode *p;
    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=e;
    p->next=NULL;
    if(q->rear==NULL)
        q->front=q->rear=p;           //若链队为空，则新结点就hi首尾结点
    else
    {
        q->rear->next=p;             //若不为空，P链到队尾，并将rear指向p
        q->rear=p;
    }
}

//出队
bool  deQueue(LinkQuNode *& q,ElemType &e){
    DataNode *t;
    if(q->rear==NULL)               //原队列为空，返回false
        return false;
    t=q->front;                     //t指向首结点
    if(q->front==q->rear)           //原来对列中只有一个数据结点时
        q->front=q->rear=NULL;
    else                            //有两个或以上结点时
        q->front=q->front->next;
    e=t->data;
    free(t);
    return true;
}