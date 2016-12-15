//
// Created by unloop on 16-12-15.
//

#include "MinHeap.h"
#include <stdio.h>
#include <stdlib.h>

MinHeap CreateHeap( int MaxSize )
{ /* 创建容量为MaxSize的空的最大堆 */

    MinHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0]->weight = MINDATA;

    return H;
}

int IsFull( MinHeap H )
{
    return (H->Size == H->Capacity);
}

int Compare(ElementType X,ElementType Y){
    if(X->weight<Y->weight){
        return 1;
    }
    return 0;
}

int Insert( MinHeap H, ElementType X)
{ /* 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 */
    int i;
    if ( IsFull(H) ) {
        return 0;
    }
    i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
    for ( ; Compare(X,H->Data[i/2]); i/=2 )
        H->Data[i] = H->Data[i/2]; /* 上滤X */
    H->Data[i] = X; /* 将X插入 */
    return 1;
}

int IsEmpty( MinHeap H )
{
    return (H->Size == 0);
}

ElementType DeleteMin( MinHeap H)
{
    int Parent, Child;
    ElementType MinItem, X;

    if ( IsEmpty(H) ) {
        return ERROR;
    }

    MinItem = H->Data[1];
    X = H->Data[H->Size--];
    for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child+1] < H->Data[Child]) )
            Child++;
        if( Compare(X, H->Data[Child]) ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;

    return MinItem;
}


void PercolateUp( MinHeap H, int p )
{
    int Parent, Child;
    ElementType X;

    X = H->Data[p]; /* 取出根结点存放的值 */
    for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->Size) && (H->Data[Child+1]<H->Data[Child]))
            Child++;  /* Child指向左右子结点的较大者 */
        if( Compare(X,H->Data[Child]) ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

void BuildHeap( MinHeap H )
{
    int i;
    for( i = H->Size/2; i>0; i-- )
        PercolateUp( H, i );
}

