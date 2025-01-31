#include <iostream>
#include <random>

void all_combs(int);
void generate_random(int);
void generate_graph(int, double);
void display_graph();

std::vector <int> row_indices;
std::vector <int> col_indices;
std::vector <double> probs;


int main(void)
{
    int num_nodes = 4;
    double p = 0.3;
    all_combs(4);
    generate_random(4);
    display_graph();
    std::cout << "Random graph: " << std::endl;
    generate_graph(4, 0.3);
    display_graph();
    return 0;
}

void all_combs(int num_nodes)
{
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            row_indices.push_back(j);
            col_indices.push_back(i);
        }
    }
}

void generate_random(int num_nodes)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < row_indices.size(); i++)
    {
        std::uniform_real_distribution <double> dist(0.0, 1.1);
        probs.push_back(dist(gen));
    }
}

void generate_graph(int num_nodes, double p)
{
    int j = 0;
    for (int i = 0; i < row_indices.size(); i++)
    {
        if (probs[i] < p)
        {
            row_indices[j] = row_indices[i];
            col_indices[j] = col_indices[i];
            probs[j] = probs[i];
            j++;
        }
    }
    row_indices.resize(j);
    probs.resize(j);
    col_indices.resize(j);
}

void display_graph()
{
    for (int i = 0; i < row_indices.size(); i++)
    {
        std::cout << "(" << row_indices[i] << ", " << col_indices[i] << ")" << std::endl;
    }
}