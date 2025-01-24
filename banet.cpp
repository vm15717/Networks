#include <iostream>
#include <map>
#include <random>

void degree(std::vector <std::vector <int>> &, std::vector <int> &);
void display(std::vector <std::vector <int>> & );
void display_degree(std::map <int, int> &);
void banet(std::vector <std::vector <int>> &, int, int);
void create_init_network(std::vector <std::vector <int>> &);
void select_nodes(std::map <int, int> &, int );

int main()
{
    // Number of nodes in the initial graph
    int V = 4;
    // Creating an initial adjacency matrix
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(V, 1));
    create_init_network(adjmat);
    std::map <int, int> degree_vec;
    int new_nodes = 100;
    int links = 3;
    banet(adjmat, new_nodes, links);
    return 0;
}

void create_init_network(std::vector <std::vector <int>> &adjmat)
{
    for (int i = 0; i < adjmat.size(); i++)
    {
        adjmat[i][i] = 0;
    }
}
void degree(std::vector <std::vector <int>> &adjmat, std::map <int, int> &degree_vec)
{
    for (int i = 0; i < adjmat.size(); i++)
    {
        for (int j = 0; j < adjmat[i].size(); j++)
        {
            degree_vec[i] += adjmat[i][j];
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
void display_degree(std::map <int, int> &degree_vec)
{
    for (const auto &key : degree_vec)
    {
        std::cout << "Node " << key.first << " -> " << key.second << std::endl;
    }
}

void banet(std::vector <std::vector <int>> &adjmat, int new_nodes, int links)
{
    int i = 0;
    while (i++ < new_nodes)
    {
        // add a new node 
        std::vector <int> new_rows(adjmat.size(), 0);
        adjmat.push_back(new_rows);   
        for (int i = 0; i < adjmat.size(); i++)
        {
            adjmat[i].push_back(0);
        } 
        std::map <int, int> degree_vec;
        degree(adjmat, degree_vec);
        // select existing nodes
        select_nodes(degree_vec, links);
    }
}

void select_nodes(std::map <int, int> &degree_vec, int links)
{
    std::vector <double> prob_cum;
    for (int i = 0; i < degree_vec.size(); i++)
    {
    }
    std::random_device rd;
    std::mt19937 gen(rd());
}