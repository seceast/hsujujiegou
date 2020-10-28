/*
 * @Author: seceast
 * @Date: 2020-10-29 15:31:56
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-29 15:54:27
 */ 

#include <stdio.h>
#include "rectype.h"

void SelectSort(RecType R[],int n){
    int i,j,k;
    RecType tmp;
    for (i=0;i<n-1;i++){
        k=i;
        for (j=i+1;j<n;j++){        //选择key最小的值并记录位置
            if (R[j].key<R[k].key)
                k=j;
        }
        if(k!=i){                   //i，k元素交换
            tmp=R[i];
            R[i]=R[k];
            R[k]=tmp;
        }
    }
}

//堆排序
void sift(RecType R[],int low,int high){
    int i=low,j=2*i;
    RecType tmp=R[i];
    while (i<=high)
    {
        if (j<high && R[i].key<R[j+1].key)
            j++;
        if (tmp.key<R[j].key){
            R[i]=R[j];
            i=j;
            j=2*i;
        }
        else break;
    }
    R[i]=tmp;
}