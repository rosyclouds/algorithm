#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *PtrToAVLNode;
typedef PtrToAVLNode AVLTree;
typedef int ElementType;

struct AVLNode{
    ElementType data;
    AVLTree left;
    AVLTree right;
    int height;
};

int max(int a,int b){
    return a>b?a:b;
}

int getHeight(AVLTree T){
    if(!T){
        return 0;
    }
    int leftHeight=0;
    int rightHeight=0;
    if(T->left){
        leftHeight=T->left->height;
    }
    if(T->right){
        rightHeight=T->right->height;
    }
    return max(leftHeight,rightHeight)+1;
}

AVLTree singleLeftRotation(AVLTree A){
    AVLTree B=A->left;
    A->left=B->right;
    B->right=A;
    A->height=max(getHeight(A->left),getHeight(A->right))+1;
    B->height=max(getHeight(B->left),A->height)+1;
    return B;
}

AVLTree singleRightRotation(AVLTree A){
    AVLTree B=A->right;
    A->right=B->left;
    B->left=A;
    A->height=max(getHeight(A->left),getHeight(A->right))+1;
    B->height=max(A->height,getHeight(B->right))+1;
    return B;
}

AVLTree doubleLeftRightRotation(AVLTree A){
    A->left=singleRightRotation(A->left);
    return singleLeftRotation(A);
}

AVLTree doubleRightLeftRotation(AVLTree A){
    A->right=singleLeftRotation(A->right);
    return singleRightRotation(A);
}

AVLTree insert(AVLTree T,ElementType X){
    if(!T){
        T=(PtrToAVLNode)malloc(sizeof(struct AVLNode));
        T->data=X;
        T->left=T->right=NULL;
        T->height=0;
    }
     if(X<T->data){
        T->left=insert(T->left,X);
        if(getHeight(T->left)-getHeight(T->right)==2){
            if(X<T->left->data){
                return singleLeftRotation(T);
            }
            return doubleLeftRightRotation(T);
        }
    }else if(X>T->data){
        T->right=insert(T->right,X);
        if(getHeight(T->right)-getHeight(T->left)==2){
            if(X>T->right->data){
                return singleRightRotation(T);
            }
            return doubleRightLeftRotation(T);
        }
    }
    T->height=max(getHeight(T->left),getHeight(T->right))+1;
    return T;
}



void inorderTraversal(AVLTree T){
    if(T){
        inorderTraversal(T->left);
        printf("%d",T->data);
        inorderTraversal(T->right);
    }
}


int main(){
    AVLTree T=NULL;
    T=insert(T,3);
    T=insert(T,2);
    T=insert(T,1);
    T=insert(T,4);
    T=insert(T,7);
    T=insert(T,8);
    T=insert(T,9);
    printf("\nHeight of AVL tree is %d\n",T->height);
    inorderTraversal(T);
    return 0;
}