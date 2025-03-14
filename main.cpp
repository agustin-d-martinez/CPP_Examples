#include <iostream>
#include "lib/LinkedList/LinkedList.h"

int main(int, char**)
{
    LinkedList<int> a(3);
    a.append(20);
    a.append(100);
    a.insertAtBeggining(40);
    a.insertAt(4,2);
    a << 20;
    std::cout << "Hello, from CPP_Examples!\n";
    std::cout << a << std::endl;

    a.remove(3);
    std::cout << a;
}
