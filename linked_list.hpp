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
        node* prev;

        node(const T x)
        {
            this->value = x;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    node* first;
    node* last;

public:
    linked_list()
    {
        first = last = NULL;
    }

    ~linked_list()
    {
        auto x = first;

        while (x)
        {
            auto next = x->next;
            delete x;

            x = next;
        }
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
            new_node->prev = last;
            last = new_node;
        }
    }

    void print()
    {
        for (auto x = first; x; x=x->next)
            std::cout << x->value << " ";
        std::cout << "\n";
    }

    void rev_print()
    {
        for (auto x = last; x; x=x->prev)
            std::cout << x->value << " ";
        std::cout << "\n";
    }

};

#endif