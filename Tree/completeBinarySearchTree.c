#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct CBSTNode *CBSTree;

struct CBSTNode{
    ElementType *data;
    int size;
    int capcity;
};

CBSTree createCBSTree(int maxSize){
    CBSTree T=(CBSTree)malloc(sizeof(struct CBSTNode));
    T->data=(ElementType *)malloc(sizeof(ElementType)*(maxSize+1));
    T->size=0;
    T->capcity=maxSize;
    return T;
}

int isFull(CBSTree T){
    return T->size==T->capcity;
}

int findMin(CBSTree T,int root){
    int min=0;
    while(root<=T->size){
        min=root;
        root=root*2;
    }
    return min;
}

int findMax(CBSTree T,int root){
    int max=0;
    while(root<=T->size){
        max=root;
        root=root*2+1;
    }
    return max;
}

int isEmpty(CBSTree T,int root){
    return root>T->size;
}

void shiftLeft(CBSTree T,int root){
    if(isEmpty(T,root)){
        return;
    }
    shiftLeft(T,root*2);
    if(!isEmpty(T,root*2)){
        T->data[findMax(T,root*2)]=T->data[root];
    }
    if(!isEmpty(T,root*2+1)){
        T->data[root]=T->data[findMin(T,root*2+1)];
    }
    shiftLeft(T,root*2+1);
}

void shiftRight(CBSTree T,int root){
    if(isEmpty(T,root)){
        return;
    }
    shiftRight(T,root*2+1);
    if(!isEmpty(T,root*2+1)){
        T->data[findMin(T,root*2+1)]=T->data[root];
        T->data[root]=T->data[findMax(T,root*2)];
    }
    shiftRight(T,root*2);
}

int insert(CBSTree T,ElementType X){
    if(isFull(T)){
        return 0;
    }
    int i=++T->size;
    int j=i;
    while(i!=1){
        if(i%2==0){
            if(X<T->data[i/2]){
                i=i/2;
            }else{
                T->data[findMax(T,i)]=T->data[i/2];
                if(!isEmpty(T,i+1)){
                    if(X<T->data[findMin(T,i+1)]){
                        j=i/2;
                        break;
                    }else if(X<T->data[findMax(T,i+1)]){
                        T->data[i/2]=T->data[findMin(T,i+1)];
                        i=findMin(T,i+1);
                        j=i;
                        continue;
                    }else{
                        T->data[i/2]=T->data[findMin(T,i+1)];
                        shiftLeft(T,i+1);
                        j=findMax(T,i+1);
                    }
                }else{
                    j=i/2;
                }
                i=i/2;
            }
        }else{
            if(X>T->data[i/2]){
                i=i/2;
            }else{
                T->data[findMin(T,i)]=T->data[i/2];
                if(X>T->data[findMax(T,i-1)]){
                    j=i/2;
                    break;
                }else if(X>T->data[findMin(T,i-1)]){
                    T->data[i/2]=T->data[findMax(T,i-1)];
                    i=findMax(T,i-1);
                    j=i;
                    continue;
                }else{
                    T->data[i/2]=T->data[findMax(T,i-1)];
                    shiftRight(T,i-1);
                    j=findMin(T,i-1);
                }
                i=i/2;
            }
        }
    }
    T->data[j]=X;
    return 1;
}

void levelTraversal(CBSTree T){
    int i;
    for (i = 1; i < T->size; ++i) {
        printf("%d ",T->data[i]);
    }
    printf("%d",T->data[i]);
}

int main(){
    CBSTree T=createCBSTree(1000);
    int N;
    int i,temp;
    scanf("%d",&N);
    if(N){
        for ( i = 0; i < N; ++i) {
            scanf("%d",&temp);
            insert(T,temp);
        }
    }
    levelTraversal(T);
    return 0;
}




