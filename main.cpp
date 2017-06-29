#include <iostream>
#include "linked_list.hpp"

using namespace std;

int main()
{
    auto v = linked_list<int>();

    v.push(15);
    v.push(17);
    v.push(12);

    v.print();
    return 0;
}