#include <iostream>
int all_nodes = 0;
class TreeNode
{
    public:
        int node;
        std::vector <TreeNode*> children;
        TreeNode(int val) : node(val) {}
};

void createcayley(TreeNode *, int, int);

int main()
{
    int num_nodes = 3;
    int num_iters = 3;
    TreeNode* root = new TreeNode(1);
    all_nodes++;
    createcayley(root, num_iters, num_nodes);
    return 0;
}

void createcayley(TreeNode *root, int num_iters, int num_nodes)
{
    if (num_iters == 0) return;
    else
    {
        for (int i = 0; i < num_nodes; i++)
        {
            TreeNode *child = new TreeNode(all_nodes + 1);
            root->children.push_back(child);
            all_nodes++;
            createcayley(child, num_iters - 1, num_nodes);
        }
    }
}