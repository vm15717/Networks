#include <iostream>

void displaygraph(std::vector <std::vector <int>> &);
void bfs(std::vector <std::vector <int>> &, int);

int main()
{
    int V = 4;
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(V));
    adjmat[0][1] = 1;
    adjmat[1][0] = 1;
    adjmat[1][2] = 1;
    adjmat[2][1] = 1;
    adjmat[2][3] = 1;
    adjmat[3][2] = 1;
    displaygraph(adjmat);
    bfs(adjmat, 0);
    return 0;
}

void displaygraph(std::vector <std::vector <int>> &mat)
{
    for (std::vector <int> node : mat)
    {
        for (int neighbour: node)
        {
            std::cout << neighbour << "\t";
        }
        std::cout << "\n";
    }
}

void bfs(std::vector <std::vector <int>> &adjmat, int start)
{
    std::vector <bool> visited(adjmat.size(), false);
    std::queue <int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        std::cout << "Visited node: " << node << std::endl;
        for (int neighbour = 0; neighbour < adjmat[node].size(); neighbour++)
        {
            if (!visited[neighbour] && adjmat[node][neighbour] == 1)
            {
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}