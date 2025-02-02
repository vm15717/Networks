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
void display(TreeNode *, int depth = 0);
void deleteTree(TreeNode *);

int main()
{
    int num_nodes = 3;
    int num_iters = 3;
    TreeNode* root = new TreeNode(1);
    all_nodes++;
    createcayley(root, num_iters, num_nodes);
    display(root);
    deleteTree(root);
    return 0;
}

void createcayley(TreeNode *root, int num_iters, int num_nodes)
{
    if (num_iters == 0 || !root) return;
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

void display(TreeNode *root, int depth)
{
    if (!root) return;
    else
    {
        for (int i = 0; i < depth; i++) std::cout << " ";
        std::cout << root->node << std::endl;
        for (auto child: root->children)
        {
            display(child, depth+1);
        }
    }
}

void deleteTree(TreeNode *root)
{
    if (!root) return;
    else
    {
        for (auto child: root->children)
        {
            deleteTree(child);
        }
    }
    delete root;
}