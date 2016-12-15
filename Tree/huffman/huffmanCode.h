typedef struct TreeNode *HuffmanTree;
struct TreeNode{
    int weight;
    char data;
    HuffmanTree left,right;
};