/*
 * @Author: seceast
 * @Date: 2020-10-30 14:23:13
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-30 16:09:34
 */ 


#include <stdio.h>
#include "rectype.h"
#include <malloc.h>

//并归排序
void Merge(RecType R[],int low,int mid,int high){
    RecType *R1;
    int i=low,j=mid+1,k=0;
    R1=(RecType *)malloc((high-low+1)*sizeof(RecType));
    while(i<=mid && j<=high){
        if(R[i].key <= R[j].key){
            R1[k] = R[i];
            i++;k++;
        }
        else {
            R1[k] = R[j];
            j++;k++;
        }
    }
    while (i<=mid){
        R1[k]=R[i];
        i++;k++;
    }
    while (j<=high){
        R1[k]=R[j];
        j++;k++;
    }
    for(k=0,i=low;i<=high;k++,i++)
        R[i]=R1[k];
    free(R1);
}
