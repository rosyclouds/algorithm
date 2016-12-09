#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

typedef int ElementType;
typedef struct TreeNode *BinTree;

struct TreeNode{
    ElementType data;
    BinTree left;
    BinTree right;
    int flag; // to check whether this node has been visited by a new input sequence
};


BinTree insert(BinTree BST,ElementType X){
    if(!BST){
        BST=(BinTree)malloc(sizeof(struct TreeNode));
        BST->data=X;
        BST->left=BST->right=NULL;
        BST->flag=0;
    }
    if(X<BST->data){
        BST->left=insert(BST->left,X);
    }else if(X>BST->data){
        BST->right=insert(BST->right,X);
    }
    return BST;
}

int *readSequence(int seqLength){
    int i;
    int *sequence=(int *)malloc(sizeof(int)*seqLength);
    for (i = 0; i < seqLength; ++i) {
        scanf("%d",sequence+i);
    }
    return sequence;
}

BinTree buildTree(int *sequence,int seqLength){
    BinTree T=NULL;
    int i;
    for (i = 0; i < seqLength; ++i) {
        T=insert(T,sequence[i]);
    }
    return T;
}



int CheckElement(BinTree T,ElementType X){
    if(T){
        if(T->flag==0){
            if(T->data==X){
                T->flag=1;
                return 1;
            }
            return 0;
        }else if(X<T->data){
            return CheckElement(T->left,X);
        }else if(X>T->data){
            return CheckElement(T->right,X);
        }
        return 1; // the tree node has been visted and there is another same element in sequence
    }
    return 0;
}


int CheckSequence(BinTree T,int *sequence,int seqLength) {
    int i;
    for (i = 0; i < seqLength; ++i) {
        if (CheckElement(T, sequence[i]) == 0) {
            return 0;
        }
    }
    return 1;
}

void postorderTraversal(BinTree T, void(*doWork)(BinTree))
{
    if(T){
        postorderTraversal(T->left,doWork);
        postorderTraversal(T->right,doWork);
        doWork(T);
    }
}

void clearFlag(BinTree T){
    T->flag=0;
}

void destroyNode(BinTree T){
    free(T);
}



int main(){
    int seqLength,seqNums;
    BinTree originTree;
    int *originSeq;
    int *compareSeq;
    int i;
    scanf("%d",&seqLength);
    while(seqLength!=0){
        scanf("%d",&seqNums);
        originSeq=readSequence(seqLength);
        originTree=buildTree(originSeq,seqLength);
        free(originSeq);
        for (i = 0; i < seqNums; ++i) {
            compareSeq=readSequence(seqLength);
            if(CheckSequence(originTree,compareSeq,seqLength)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
            postorderTraversal(originTree,clearFlag);
            free(compareSeq);
//            if(i!=seqNums-1){
//                printf("\n");
//            }
        }
        postorderTraversal(originTree,destroyNode);
        scanf("%d",&seqLength);
//        if(seqLength!=0){
//            printf("\n");
//        }
    }
    return 0;
}

