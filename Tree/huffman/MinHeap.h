//
// Created by unloop on 16-12-15.
//

#include "huffmanCode.h"

typedef HuffmanTree ElementType;
typedef struct HNode *Heap; /* 堆的类型定义 */
struct HNode {
    ElementType *Data; /* 存储元素的数组 */
    int Size;          /* 堆中当前元素个数 */
    int Capacity;      /* 堆的最大容量 */
};
typedef Heap MaxHeap; /* 最大堆 */
typedef Heap MinHeap; /* 最小堆 */

#define ERROR NULL /* 错误标识应根据具体情况定义为堆中不可能出现的元素值 */
#define MINDATA -1000  /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */

MinHeap CreateHeap(int maxSize);
int Insert(MinHeap H,ElementType X);
int IsEmpty(MinHeap H);
int IsFull(MinHeap H);
ElementType DeleteMin(MinHeap H);
void BuildHeap(MinHeap H);
void PercolateUp(MinHeap H,int position);
