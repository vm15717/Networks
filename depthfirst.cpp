#include <iostream>


void displaygraph(std::vector <std::vector <int>> &);
void dfs(std::vector <std::vector <int>> &, int, std::vector <bool> &);
int main()
{
    int V = 4;
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(V));
    adjmat[0][1] = 1;
    adjmat[1][0] = 1;
    adjmat[1][3] = 1;
    adjmat[0][2] = 1;
    adjmat[2][0] = 1;
    adjmat[3][2] = 1;
    adjmat[2][3] = 1;
    adjmat[3][1] = 1;
    displaygraph(adjmat);
    std::vector <bool> visited(V, false);
    dfs(adjmat, 0, visited);
    return 0;
}

void displaygraph(std::vector <std::vector <int>> &adjmat)
{
    for (auto const &node:adjmat)
    {
        for (auto const &neighbour:node)
        {
            std::cout << neighbour << "\t";   
        }
        std::cout << "\n";
    }
}

void dfs(std::vector <std::vector <int>> &adjmat, int start, std::vector <bool> &visited)
{
    visited[start] = true;
    std::cout << "Visited node: " << start << std::endl;
    for (int i = 0; i < adjmat[start].size(); i++)
        {
            if (!visited[i] && adjmat[start][i] == 1)
            {
                visited[i] = true;
                dfs(adjmat, i, visited);
            }
        }
}