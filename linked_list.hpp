#ifndef _INCL_GUARD_LINKED_LIST_HPP
#define _INCL_GUARD_LINKED_LIST_HPP
#include <iostream>

template<typename T>
class linked_list
{
private:
    struct node
    {
        T value;
        node* next;

        node(const T x)
        {
            this->value = x;
            this->next = NULL;
        }
    };

    node* first;
    node* last;

public:
    linked_list()
    {
        first = last = NULL;
    }

    void push(const T x)
    {
        if (first == NULL)
        {
            first = new node(x);
            last = first;
        }
        else
        {
            auto new_node = new node(x);
            last->next = new_node;
            last = new_node;
        }
    }

    void print()
    {
        for (auto x = first; x; x=x->next)
            std::cout << x->value << " ";
        std::cout << "\n";
    }
};

#endif