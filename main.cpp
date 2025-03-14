#include <iostream>
#include "lib/LinkedList/LinkedList.h"
#include "lib/Complex/Complex.h"

int main(int, char**)
{
	LinkedList<int> lista1(3);
	lista1.append(20);
	lista1.append(100);
	lista1.insertAtBeggining(40);
	lista1.insertAt(4,2);
	lista1 << 20;
	std::cout << lista1 << std::endl;
	lista1.remove(3);
	std::cout << lista1 << std::endl << std::endl;

	Complex a(13.5 , 24.8);
	Complex b;

	std::cout << "Ingrese numero imaginario" << std::endl;
	std::cin >> b;
	std::cout << b << std::endl << std::endl;

	a += b;
	std::cout << "suma a=a+b: " << a << std::endl;

	a -= b;
	std::cout << "resta a=a-b: " << a << std::endl;

	a /= b;
	std::cout << "division a=a/b: " << a << std::endl;

	a.SetPolar(50 , M_PIl);
	std::cout << "valor a=50 |_PI: " << a << std::endl;
}
