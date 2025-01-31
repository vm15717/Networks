#include <iostream>
#include <map>
#include <set>

class Banet{
    private:
    int degree_sum;
    int init_nodes;
    int num_nodes;
    int num_links;
    std::vector <int> row_indices;
    std::vector <int> col_indices;
    std::map <int, int> degree_map;
    std::map <int, double> degree_cum_sum;
    std::vector <std::vector <int>> adjmatrix;
    public:
    Banet(int init_nodes = 5, int num_nodes = 2, int num_links = 2) : init_nodes(init_nodes), num_nodes(num_nodes), num_links(num_links)
    {
         for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            row_indices.push_back(j);
            col_indices.push_back(i);
        }
    }
    for (int k = 0; k < num_nodes; k++)
    {
        degree_map[k] = 0;
    }
    degree(row_indices, col_indices, degree_map);
    probsum(degree_map, degree_cum_sum);
    }
};