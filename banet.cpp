#include <iostream>
#include <map>
#include <random>
#include <set>

void degree(std::vector <std::vector <int>> &, std::map <int, int> &);
void display(std::vector <std::vector <int>> & );
void display_degree(std::map <int, int> &);
void banet(std::vector <std::vector <int>> &, int, int);
void create_init_network(std::vector <std::vector <int>> &);
std::set <int> select_nodes(std::map <int, int> &, int );
int find_node(std::vector <double> &, double);

int main()
{
    // Number of nodes in the initial graph
    int V = 4;
    // Creating an initial adjacency matrix
    std::vector <std::vector <int>> adjmat(V, std::vector <int>(V, 1));
    create_init_network(adjmat);
    std::map <int, int> degree_vec;
    int new_nodes = 1000;
    int links = 3;
    banet(adjmat, new_nodes, links);
    degree(adjmat, degree_vec);
    display_degree(degree_vec);
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
        degree_vec[i] = 0;
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
        for (int k = 0; k < adjmat.size(); k++)
        {
            adjmat[k].push_back(0);
        } 
        std::map <int, int> degree_vec;
        degree(adjmat, degree_vec);
        // select existing nodes
        std::set <int> selected_nodes = select_nodes(degree_vec, links);
        for (int node: selected_nodes)
        {
            adjmat[adjmat.size()-1][node] = 1;
            adjmat[node][adjmat.size()-1] = 1;
        }
    }
}

std::set <int> select_nodes(std::map <int, int> &degree_vec, int links)
{
    std::vector <double> prob_cum;
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::set <int> selected_nodes;
    double sum = 0.0;
    for (int i = 0; i < degree_vec.size(); i++)
    {
        sum+=degree_vec[i];
        prob_cum.push_back(sum);
    }
    for (int j = 0; j < degree_vec.size(); j++)
    {
        prob_cum[j] = prob_cum[j]/sum;
    }
    for (int k = 0;k < links; k++)
    {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        selected_nodes.insert(find_node(prob_cum, dist(gen)));
    }
    return selected_nodes;
}

int find_node(std::vector <double> &prob_cum, double randval)
{
    for (int j = 0; j < prob_cum.size(); j++)
    {
        if (randval <= prob_cum[j])
        {
            return j;
        }
    }
    return 0;
}