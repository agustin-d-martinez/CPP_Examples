#pragma once

#include "Plano.h"

class Figura {
	public:
	double x , y;	//Posicion de la figura. 

	Figura() {}
	virtual ~Figura() = default;
	virtual void Rotate( const double& degree_angle ) = 0;
	virtual void Imprimir(Plano& a ) = 0;
};