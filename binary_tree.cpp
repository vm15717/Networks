#include <iostream>
int all_nodes = 0;

class TreeNode
{
    public:
    int node;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): node(val), left(nullptr), right(nullptr) {};
};

void createBinaryTree(TreeNode *, int);
void display(TreeNode*, int depth = 0);
void deleteTree(TreeNode*);

int main(void)
{
    TreeNode *root = new TreeNode(0);
    int num_iters = 3;
    all_nodes++;
    createBinaryTree(root, num_iters);
    display(root);
    deleteTree(root);
    return 0;
}

void createBinaryTree(TreeNode *root, int num_iters)
{
    if (!root || num_iters == 0) return;
    root->left = new TreeNode(all_nodes++);
    root->right = new TreeNode(all_nodes++);
    createBinaryTree(root->left, num_iters - 1);
    createBinaryTree(root->right, num_iters - 1);
}

void display(TreeNode *root, int depth)
{
    if (!root) return;
    for (int i = 0; i < depth; i++) std::cout << " ";
    std::cout << root->node << std::endl;
    display(root->left, depth+1);
    display(root->right, depth+1);
}

void deleteTree(TreeNode *root)
{
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}