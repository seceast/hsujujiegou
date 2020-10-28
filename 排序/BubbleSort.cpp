/*
 * @Author: seceast
 * @Date: 2020-10-29 10:56:28
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-29 15:10:23
 */ 
#include <stdio.h>
#include "rectype.h"

//冒泡排序
void BubbleSort(RecType R[],int n){
    int i,j;
    RecType tmp;
    for (i=0;i<n-1;i++){
        for(j=n-1;j<i;j--){
            if(R[j].key<R[j-1].key){
                tmp=R[j];
                R[j]=R[j-1];
                R[j-1]=tmp;
            }
        }
    }
}

//快速排序
int Partition(RecType R[],int s,int t){
    int i=s,j=t;
    RecType tmp = R[i];                //以R[i]为基准
    while(i<j){                        //从两端交替向中间扫描
        while(j>i && R[j].key>tmp.key)
            j--;
        R[i]=R[j];
        while(i<j && R[i].key<tmp.key)
            i++;
        R[j]=R[i];
    }
    R[i]=tmp;
    return i;
}

void QuickSort(RecType R[],int s,int t){
    int i;
    if(s<t){
        i=Partition(R,s,t);
        QuickSort(R,s,i-1);
        QuickSort(R,i+1,t);
    }
}