#include <iostream>


class Link
{
    public:
    int val;
    Link *link;
    Link(int val) : val(val), link(nullptr) {};
    void addLink(Link *other)
    {
        this->link = other;   
    }
    void removeLink()
    {
        this->link = nullptr;
    }
};


int main(void)
{

}