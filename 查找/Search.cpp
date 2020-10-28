/*
 * @Author: seceast
 * @Date: 2020-10-28 16:20:11
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-28 16:30:41
 */ 

//线性表查找
#include <stdio.h>

typedef int KeyType;
typedef int InfoType;

typedef struct{
    KeyType key; 
    InfoType data;
}RecType;

//顺序查找
int SeqSearch(RecType R[],int n,KeyType k){
    int i =0;
    R[n].key=k;           //尾部增加哨兵，无需判断i是否越界
    while(R[i].key!=k)
        i++;
    if(i==n) return 0;
    else return i+1;      //返回逻辑序号
}

//折半查找（只能有序表使用）
int BinSearch(RecType R[],int n,KeyType k){
    int low = 0,high =n-1,mid;
    while(low < high){
        mid=(low+high)/2;
        if(k=R[mid].key)
            return mid+1;
        if(k<R[mid].key)
            low=mid-1;
        else 
            low=mid+1;
    }
    return 0;
}