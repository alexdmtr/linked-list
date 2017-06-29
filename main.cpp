#include <iostream>
#include "linked_list.hpp"

using namespace std;

int main()
{
    auto v = linked_list<int>();

    v.push(15);
    v.push(17);
    v.push(12);
    v.push(14);
    v.push(21);


    v.print();

    cout << "|| REMOVE ODDS\n";
    v.remove([](int x) {
        return x%2 == 1;
    });

    v.print();


    // v.rev_print();

    cout << "|| FINISH\n";
    return 0;
}