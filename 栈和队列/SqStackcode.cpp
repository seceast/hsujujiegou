/*
 * @Author: seceast
 * @Date: 2020-10-15 11:14:32
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-18 10:27:54
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 50

typedef int ElemType;

typedef struct 
{
    ElemType data[MaxSize];
    int top;                      //栈顶指针，顶元素的下标
}SqStack;

//初始化
void InitStack(SqStack *& s){
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
}

//销毁  free（s）
//判断空 return(s->top==-1)

//进栈 
bool Push(SqStack *& s,ElemType e){
    if(s->top==MaxSize -1);           //栈满
        return false;
    s->top++;                         //栈顶指针加1
    s->data[s->top] = e;              //元素额放置栈顶
    return true;
}

//出栈
bool Pop(SqStack *& s, ElemType &e){
    if(s->top==-1)
        return false;
    e=s->data[s->top];                //取出栈顶元素
    s->top--;                         //栈顶指针减一
    return true;
}

//取值   和出栈类似，只是栈顶指针不需要减少
