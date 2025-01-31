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

void network_init(int);
void display_graph();
void degree();
void display_degree();
void banet_create(int, int);
void probsum();
int find_node(double);
//void update(std::map <int, int> &, std::map <int, double> &);

int main(void)
{
    num_nodes = 10;
    int num_times = 30;
    int num_links = 3;
    network_init(num_nodes);
    display_graph();
    display_degree();
    banet_create(num_times, num_links);
    display_graph();
    display_degree();
    return 0;
}

void network_init(int num_nodes)
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
    degree();
    probsum();
}

void display_graph()
{
    if (!row_indices.empty())
    {    
        for (int i = 0; i < row_indices.size(); i++)
        {
            std::cout << "(" << row_indices[i] << ", " << col_indices[i] << ")" << ": 1" << std::endl;
        }
    }
}

void degree()
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

void display_degree()
{
    for (const auto &[node, degree]: degree_map)
    {
        std::cout << node << ": " << degree << std::endl;
    }
}

void probsum()
{
    int sum = 0;
    for (const auto &[node, degree]: degree_map)
    {
        sum += degree;
        degree_cum_sum[node] = sum;
    } 
}

void banet_create(int num_times, int num_links)
{
    for (int j = 0; j < num_times; j++)
    {
        std::set <int> selected_nodes;
        for (int k = 0; k < num_links; k++)
        {
            std::random_device rd; 
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            selected_nodes.insert(find_node(dist(gen))); 
        }
        degree_map[num_nodes] = 0;
        for (int node:selected_nodes)
        {
            row_indices.push_back(node);
            degree_map[node]++;
            degree_map[num_nodes]++;
            degree_sum++;
            col_indices.push_back(num_nodes);
        }
        probsum();
        num_nodes++;
    }
}

int find_node(double randval)
{
    for (int j = 0; j < degree_cum_sum.size(); j++)
    {
        double prob = degree_cum_sum[j]/degree_sum;
        if (randval <= prob)
        {
            return j;
        }
    }
    return degree_cum_sum.size()-1;
}
