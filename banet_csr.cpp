#include <iostream>
#include <map>
#include <random>
#include <set>

int degree_sum = 0;
int num_nodes = 0;
std::vector <int> row_indices;
std::vector <int> col_indices;
std::map <int, int> degree_map;
std::map <int, double> degree_cum_sum;

void network_init(std::vector <int> &, std::vector <int> &, std::map <int, int> &, std::map <int, double> &, int);
void display_graph(std::vector <int> &, std::vector <int> &);
void degree(std::vector <int> &, std::vector <int> &, std::map <int, int> &);
void display_degree(std::map <int, int> &);
void banet_create(std::vector <int> &, std::vector <int> &, std::map <int, int> &, int);
void probsum(std::map <int, int> &, std::vector <double> &);
int find_node(std::map <int, double> &, double );

int main(void)
{
    num_nodes = 4;
    int num_times = 100;
    int num_links = 2;
    network_init(row_indices, col_indices, degree_map, degree_cum_sum, num_nodes);
    display_graph(row_indices, col_indices);
    display_degree(degree_map);
    banet_create(row_indices, col_indices, degree_map, num_links);
    return 0;
}

void network_init(std::vector <int> &row_indices, std::vector <int> &col_indices, std::map <int, int> &degree_map, 
                    std::map <int, double> &degree_cum_sum, int num_nodes)
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

void display_graph(std::vector <int> &row_indices, std::vector <int> &col_indices)
{
    if (!row_indices.empty())
    {    
        for (int i = 0; i < row_indices.size(); i++)
        {
            std::cout << "(" << row_indices[i] << ", " << col_indices[i] << ")" << ": 1" << std::endl;
        }
    }
}

void degree(std::vector <int> &row_indices, std::vector <int> &col_indices, std::map <int, int> &degree_map)
{
    for (int i = 0; i < row_indices.size(); i++)
    {
        degree_map[row_indices[i]]++;
        degree_sum++;
    }
    for (int j = 0; j < col_indices.size(); j++)
    {
        degree_map[col_indices[j]]++;
        degree_sum++;
    }
}

void display_degree(std::map <int, int> &degree_map)
{
    for (const auto &[node, degree]: degree_map)
    {
        std::cout << node << ": " << degree << std::endl;
    }
}

void probsum(std::map <int, int> &degree_map, std::map <int, double> &degree_cum_sum)
{
    int sum = 0;
    for (const auto &[node, degree]: degree_map)
    {
        sum += degree;
        degree_cum_sum[node] = sum/degree_sum;
    } 
}

void banet_create(std::map <int, int> &degree_map, std::map <int, double> &prob_cum_sum, int num_times, int num_links)
{
    std::random_device rd; 
    std::mt19937 gen(rd());
    for (int j = 0; j < num_times; j++)
    {
        std::set <int> selected_nodes;
        while (selected_nodes.size() != num_links)
        {
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            selected_nodes.insert(find_node(prob_cum_sum, dist(gen)));   
        }
    }
}

int find_node(std::map <int, double> &prob_cum_sum, double randval)
{
    for (int j = 0; j < prob_cum_sum.size(); j++)
    {
        if (randval <= prob_cum_sum[j])
        {
            return j;
        }
    }
    return 0;
}