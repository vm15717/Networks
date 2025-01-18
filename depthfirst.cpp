#include <iostream>

void dfs(std::vector <std::vector <int>> &adjmat, int);
int main()
{
    int V = 4;
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(V));
    adjmat[0][1] = 1;
    adjmat[0][2] = 1;
    adjmat[1][0] = 1;
    adjmat[2][0] = 1;
    adjmat[0][3] = 1;
    adjmat[3][0] = 1;
    dfs(adjmat, 0);
}

void dfs(std::vector <std::vector <int>> &adjmat, int start)
{
    std::vector <bool> visited(adjmat.size(), false);
    std::stack <int> gstack;
    gstack.push(start);
    visited[start] = true;
    while (!gstack.empty())
    {
        int node = gstack.top();
        gstack.pop();
        std::cout << "Visited node: " << node << std::endl;
        for (int i = adjmat[node].size()-1; i >= 0; i--)
        {
            if (adjmat[node][i] == 1 && !visited[i])
            {
                gstack.push(i);
                visited[i] = true;
            }
        }
    }
}