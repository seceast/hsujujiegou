/*
 * @Author: seceast
 * @Date: 2020-10-30 16:08:40
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-30 16:32:32
 */ 


#include <stdio.h>

#define MAXD 50

//基数排序
typedef struct node{
    char data[MAXD];
    struct node *next;
}NodeType;

void RadixSort(NodeType  *& p,int r,int d){
    NodeType *head[MAXD], *tail[MAXD], *t;
    int i,j,k;
    for(i=0;i<=d-1;i++)
        head[j]=tail[j]=NULL;
    while(p!=NULL){
        k=p->data[i]-'0';
        if (head[k]==NULL){
            head[k]=p;
            tail[k]=p;
        }
        else{
            tail[k]->next=p;
            tail[k]=p;
        }
        p=p->next;
    }
    p=NULL;
    for (j=0;j<r;j++){
        if (head[j]!=NULL){
            if(p==NULL){
                p=head[j];
                t=tail[j];
            }
            else{
                t->next=head[j];
                t=tail[j];
            }
        
        }
        t->next=NULL;
    }
}