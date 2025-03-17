#include "Plano.h"
#include "Figura.h"

Plano::Plano (int largo , int ancho ) : ui(largo, std::vector<char>(ancho, ' '))  {}

void Plano::Add(Figura& a){
	a.Imprimir(*this);
}

void Plano::Set(const int &x, const int &y)
{
	if ( y >= 0 && y <= ui.size() && x >= 0 && x <= ui[y].size() )
		ui[ui.size() - 1 - y][x] = '*';
}
void Plano::Set(const double &x, const double &y)
{
	if ( y >= 0 && y <= ui.size() && x >= 0 && x <= ui[y].size() )
		ui[ui.size() -1 -static_cast<int>(y)][static_cast<int>(x)] = '*';
}

void Plano::Update( void ){
	for (auto& y_vector : ui)
	{
		for (auto& x : y_vector)
			std::cout << x;
		std::cout << std::endl;
	}
}

void Plano::Clear(void)
{
	for (auto& fila : ui)
		std::fill(fila.begin(),fila.end(),' ');
}
