#include <iostream>
#include "lib/LinkedList/LinkedList.h"

int main(int, char**)
{
    LinkedList a(3);
    a.append(20);
    std::cout << "Hello, from CPP_Examples!\n";
    std::cout << a;
}
