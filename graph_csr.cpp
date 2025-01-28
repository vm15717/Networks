#include <iostream>

void to_adjacencymatrix(std::vector <int> &, std::vector <int> &, std::vector <std::vector <int>> &);
void display_adjacencymatrix(std::vector <std::vector <int>> & );
void display_sparsematrix(std::vector <int> &, std::vector <int> &);

int main(void)
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
    display_adjacencymatrix(adjmat);
    display_sparsematrix(row_indices, col_indices);
    return 0;
}

void to_adjacencymatrix(std::vector <int> &row_indices, std::vector <int> &col_indices, std::vector <std::vector <int>> &adjmat)
{
    for (int j = 0; j < row_indices.size(); j++)
    {
        adjmat[row_indices[j]][col_indices[j]] = 1;
        adjmat[col_indices[j]][row_indices[j]] = 1;
    }
}

void display_adjacencymatrix(std::vector <std::vector <int>> &adjmat)
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

void display_sparsematrix(std::vector <int> &row_indices, std::vector <int> &col_indices)
{
    for (int j = 0; j < row_indices.size(); j++)
    {
        std::cout << "(" << row_indices[j] << ", " << col_indices[j] << ")" << ":  1" << std::endl;
    }
}