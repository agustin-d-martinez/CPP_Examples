#pragma once

#include "Poligono.hpp"

class Rectangulo : public Poligono {
	private:
	double 	largo;
	double	ancho;
	public:
	Rectangulo(double _largo , double _ancho , double _x = 0, double _y = 0);
	~Rectangulo() {}
	double Area( void );
	double Perimetro( void );
	void Imprimir(Plano& a );
	void Rotate ( double degree_angle );
};