/*
 * @Author: seceast
 * @Date: 2020-10-22 10:20:13
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-26 15:05:48
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MaxSize 100

typedef int ElemType;

//链式二叉树结点类型声明
typedef struct Node{
    ElemType data;
    struct node *lchild;         //指向左孩子
    struct node *rchild;         //指向右孩子
}BTNode;

//创建二叉树
void CreatBTree(BTNOde *& b, char *str){
    BTNode *st[MaxSize], *p;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[i];
    while(ch!='\0'){
        switch (ch){
            case '(':top++;St[top]=p;k=1;break;
            case ')':top--;break;
            case ',':k=2;break;
            default: 
                p=(BTNode *)malloc(sizeof(BTNode));
                p->data=ch;
                p->lchild=p->rchild=NULL;
                if(b==NULL )
                    b=p;
                else{
                    switch (k){
                        case 1:St[top]->lchild=p;break;
                        case 2:St[top]->rchild=p;break;
                    }
                }
        }
        j++;
        ch=str[j];
    }

}

//销毁（递归）
void DestroyBTree(BTNode *& b){
    if(b!=NULL){
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

//查找值为x的结点
BTNode *FindNode(BTNode *& b,ElemType x){
    BTNode *p;
    if(b==NULL)
        return NULL;
    if (b->data==x)
        return b;
    else
    {
        p=FindNode(b->lchild,x)
        if(p!=NULL)
            return p;
        else
            return FindNode(b->rchild,x)
    }
}

//求树高度
int BTHeight(BTNode *b){
    int lchildh,rchildh;
    if(b==NULL) return (0);
    else {
        lchildh=BTHeight(b->lchild);
        rchildh=BTHeight(b->rchild);
        return (lchildh>rchildh) ?(lchildh+1):(rchildh+1);
    }
}

//输出二叉树
void DispBTree(BTNode *b){
    if(b!=NULL){
        printf("%c",b->data);
        if(b->lchild!=NULL || b->rchild!=NULL){
            printf("(");                                //有孩子时输出“（”
            DispBTree(b->lchild);                       //递归处理左子树
            if (b->rchild!=NULL)printf(",");            //有右孩子时输出“，”
            DispBTree(b->rchild);                       //递归处理右孩子
            printf(")");                                //有孩子结点时才输出“）”
        }
    }
}