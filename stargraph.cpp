#include <iostream>
void disp_mat(const std::vector <std::vector <int>> &);
void degree(const std::vector <std::vector <int>> &);

int main()
{
    int V = 5;
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(5, 0));
    for (int i = 1; i < adjmat[0].size(); i++)
    {
        adjmat[0][i] = 1;
        adjmat[i][0] = 1;
    }
    disp_mat(adjmat);
    return 0;
}

void disp_mat(const std::vector <std::vector <int>> &adjmat)
{
    for (const auto &node:adjmat)
    {
        for (const auto &neighbour: node)
        {
            std::cout << neighbour << "\t";
        }
        std::cout << "\n";
    }
}