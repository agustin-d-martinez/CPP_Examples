#pragma once
#define _USE_MATH_DEFINES 
#include <cmath>

#include "Forma.hpp"
#include "../Punto/Punto.hpp"

class Circulo : public Forma {
	private:
	Punto centro;
	double radio;

	public:
	Circulo(const double& _x , const double& _y , const double& _radio);
	Circulo(const Punto& a , const double& _radio);
	~Circulo() {}

	double Area ( void );
	double Perimetro ( void );

	void setRadio( const double& _radio );
	void setPos ( const double& x , const double& y );
	void setPos ( const Punto& a );
	void Rotate( double degree_angle );
	void Imprimir(Plano& a);
};