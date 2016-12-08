//BinTree insert(BinTree BST,ElementType X){
//    if(!BST){
//        BST=(PtrToTreeNode)malloc(sizeof(struct TreeNode));
//        BST->data=X;
//        BST->left=BST->right=NULL;
//    }
//    if(X<BST->data){
//        BST->left=insert(BST->left,X);
//    }else if(X>BST->data){
//        BST->right=insert(BST->right,X);
//    }
//    return BST;
//}