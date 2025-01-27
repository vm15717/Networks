#include <iostream>

void degree(std::vector <std::vector <int>> &, std::vector <int> &);
void display(std::vector <std::vector <int>> & );
void display_degree(std::vector <int> &);

int main()
{
    int V = 4;
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(V, 0));
    adjmat[0][1] = 1;
    adjmat[1][0] = 1;
    adjmat[1][2] = 1;
    adjmat[2][1] = 1;
    adjmat[2][3] = 1;
    adjmat[3][2] = 1;
    std::vector <int> degree_vec;
    degree(adjmat, degree_vec);
    display_degree(degree_vec);
    return 0;
}

void degree(std::vector <std::vector <int>> &adjmat, std::vector <int> &degree_vec)
{
    for (const auto &node: adjmat)
    {
        int sum = 0;
        for (const auto &neighbour: node)
        {
            sum += neighbour;
        }
        degree_vec.push_back(sum);
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
void display_degree(std::vector <int> &degree_vec)
{
    for (int i = 0; i < degree_vec.size(); i++)
    {
        std::cout << "Node " << i << " -> " << degree_vec[i] << std::endl;
    }
}