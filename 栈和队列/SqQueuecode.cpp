/*
 * @Author: seceast
 * @Date: 2020-10-19 14:26:12
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-22 10:13:57
 */ 

//队列，先进先出，进入端叫队尾，删除端叫队头
//顺序对列

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

//队空：q->front==q->rear
//队满：q->==Maxsize-1

//初始化,将头尾指针设为初始状态（-1）
void InitQueue(SqQueue *& q){
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = -1;
}

//销毁 free(q)
//判断空 return(q->front == q->rear)

//进队
bool enQueue(SqQueue *& q,ElemType e){
    if(q->rear == MaxSize - 1)             //队满
        return false;                      
    q->rear++;                             //队尾加1
    q->data[q->rear] = e;                  
    return true;
}

//出队列
bool dequeue(SqQueue *& q, ElemType &e){
    if(q->front==q->rear)
        return false;
    q->front++;
    e = q->data[q->front];
    return true;
}

