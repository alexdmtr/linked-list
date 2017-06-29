#ifndef _INCL_GUARD_LINKED_LIST_HPP
#define _INCL_GUARD_LINKED_LIST_HPP
#include <iostream>
#include <functional>
#include <memory>

using namespace std;

template<typename T>
class linked_list
{
private:
    struct node
    {
        T value;
        shared_ptr<node> next;
        shared_ptr<node> prev;

        node(const T x)
        {
            this->value = x;
            this->next = NULL;
            this->prev = NULL;
        }
        ~node()
        {
            cout << ">> destruct " << this->value << "\n";
        }
    };

    shared_ptr<node> first;
    shared_ptr<node> last;

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
            x->prev = x->next = NULL;
            x = next;
        }
        // first = last = NULL;
    }


    void push(const T x)
    {
        if (first == NULL)
        {
            first = shared_ptr<node>(new node(x));
            last = first;
        }
        else
        {
            auto new_node = shared_ptr<node>(new node(x));
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }
    }

    void remove(function<bool(T)> predicate)
    {
        while (predicate(first->value))
        {
            auto next = first->next;
            if (next)
                next->prev = NULL;
            first = next;
        }


        auto x = first;
        while (x)
        {
            if (predicate(x->value))
            {
                auto prev = x->prev;
                auto next = x->next;
                prev->next = next;

                if (next)
                    next->prev = prev;

                if (x == last)
                    last = prev;
            }

            x = x->next;
        }
    }

    void print() const
    {
        for (auto x = first; x; x=x->next)
            std::cout << x->value << " ";
        std::cout << "\n";
    }

    void rev_print() const
    {
        for (auto x = last; x; x=x->prev)
            std::cout << x->value << " ";
        std::cout << "\n";
    }

};

#endif