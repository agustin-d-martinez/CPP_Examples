#include <iostream>
#include "lib/LinkedList/LinkedList.h"
#include "lib/Figura/Punto/Punto.h"

#include "lib/Complex/Complex.h"

#include "lib/Figura/Forma/Rectangulo.h"
#include "lib/Figura/Plano.h"
#include "lib/Figura/Forma/Circulo.h"

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

	for (auto& element : lista1 )		// auto iterator. Similar to Python. Element has an the element of the vector.
		std::cout << element << " ";
	std::cout << std::endl << std::endl;

	Complex a(13.5 , 24.8);
	Complex b(10,10);

	a += b;
	std::cout << "suma a=a+b: " << a << std::endl;

	a -= b;
	std::cout << "resta a=a-b: " << a << std::endl;

	a.SetPolar(50 , M_PI/2);
	std::cout << "valor a=50 |_PI: " << a << std::endl << std::endl;
	Punto puntito = a;
	std::cout << puntito << std::endl;

	Plano ui(40 , 40);

	Rectangulo cuadradito(15,15,15,0);
	cuadradito.Rotate(45);
	Circulo circulito(Punto(15,10) , 5);
	Linea recta1(Punto(3,0) , Punto(30,27));

	ui.Add(recta1);
	ui.Add(cuadradito);
	ui.Add(circulito);
	ui.Update();
}
