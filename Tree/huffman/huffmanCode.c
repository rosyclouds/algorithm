#include <stdio.h>
#include <stdlib.h>

#include "MinHeap.h"


typedef struct PrefixNode *PrefixTree;
typedef PrefixTree *PtrPrefixTree;
struct PrefixNode{
    int leaf;
    PrefixTree left,right;
};

HuffmanTree createHuffmanTree(MinHeap H){
    HuffmanTree T;
    int i;
    for (i = 1; i < H->Size; ++i) {
        T=(HuffmanTree)malloc(sizeof(struct TreeNode));
        T->left=DeleteMin(H);
        T->right=DeleteMin(H);
        T->weight=T->left->weight+T->right->weight;
        Insert(H,T);
    }
    T=DeleteMin(H);
    return T;
}



int IsPrefixEncode(PtrPrefixTree T,char *code){
    if(code[0]=='\0'){
        if((*T)){
            return 1;
        }
        (*T)=(PrefixTree)malloc(sizeof(struct PrefixNode));
        (*T)->left=(*T)->right=NULL;
        (*T)->leaf=1;
        return 0;
    }
    if(code[0]=='0'){
        if(!(*T)){
            (*T)=(PrefixTree)malloc(sizeof(struct PrefixNode));
            (*T)->left=(*T)->right=NULL;
            (*T)->leaf=0;
        }else{
            if((*T)->leaf==1){
                return 1;
            }
        }
        return IsPrefixEncode(&((*T)->left),code+1);
    }
    else{
        if(!(*T)){
            (*T)=(PrefixTree)malloc(sizeof(struct PrefixNode));
            (*T)->left=(*T)->right=NULL;
            (*T)->leaf=0;
        }else{
            if((*T)->leaf==1){
                return 1;
            }
        }
        return IsPrefixEncode(&((*T)->right),code+1);
    }
}

int main(){
    PrefixTree T=NULL;
    printf(IsPrefixEncode(&T,"001")?"Yes\n":"No\n");
    printf(IsPrefixEncode(&T,"0001")?"Yes\n":"No\n");
    printf(IsPrefixEncode(&T,"11")?"Yes\n":"No\n");
    printf(IsPrefixEncode(&T,"111")?"Yes\n":"No\n");


    return 0;
}