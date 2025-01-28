#include <iostream>

void to_adjacencymatrix(std::vector <int> &, std::vector <int> &, std::vector <std::vector <int>> &);
void display(std::vector <std::vector <int>> & );

int main()
{
    int num_nodes = 3;
    std::vector <int> row_indices;
    std::vector <int> col_indices;
    // Define the graph
    row_indices.push_back(0);
    col_indices.push_back(1);
    row_indices.push_back(0);
    col_indices.push_back(2);
    std::vector <std::vector <int>> adjmat(num_nodes, std::vector <int>(num_nodes, 0));
    to_adjacencymatrix(row_indices, col_indices, adjmat);
    display(adjmat);
    return 0;
}

void to_adjacencymatrix(std::vector <int> &row_indices, std::vector <int> &col_indices, std::vector <std::vector <int>> &adjmat)
{
    for (int &row : row_indices)
    {
        for (int &col: col_indices)
        {
            adjmat[row][col] = 1;
            adjmat[col][row] = 1;
        }
    }
}

void display(std::vector <std::vector <int>> &adjmat)
{
    for (const auto &node: adjmat)
    {
        for (const auto &neighbour: node)
        {
            std::cout << neighbour << "\t";   
        }
        std::cout << "\n";
    }
}