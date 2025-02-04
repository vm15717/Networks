#include <iostream>


class Link
{
    public:
    int val;
    Link *next;
    Link(int val) : val(val), next(nullptr) {};
    void addLink(Link *other)
    {
        this->next = other;   
    }
    void removeLink()
    {
        this->next = nullptr;
    }
};


int main(void)
{
}