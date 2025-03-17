#include "Plano.h"
#include "Figura.h"

Plano::Plano (int largo , int ancho ) : ui(largo, std::vector<char>(ancho, ' '))  {}

void Plano::Add(Figura& a){
	a.Imprimir(*this);
	formas.push_back(a);
}

void Plano::Set(const int &x, const int &y)
{
	ui[y][x] = '*';
}
void Plano::Set(const double &x, const double &y)
{
	ui[static_cast<int>(y)][static_cast<int>(x)] = '*';
}


void Plano::Update( void ){
	for (auto& y_vector : ui)
	{
		for (auto& x : y_vector)
			std::cout << x;
		std::cout << std::endl;
	}
}
