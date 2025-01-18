#include <iostream>

void displaygraph(std::vector <std::vector <int>> &);

int main()
{
    int V = 5;
    std::vector <std::vector <int>> adjmat(5, std::vector <int>(5));
    adjmat[0][1] = 1;
    adjmat[1][0] = 1;
    adjmat[1][2] = 1;
    adjmat[2][1] = 1;
    adjmat[2][3] = 1;
    adjmat[3][2] = 1;
    displaygraph(adjmat);
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