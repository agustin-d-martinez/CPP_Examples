#pragma once
#include "../Figura.h"


class Forma : public Figura{
	public:

	Forma() {}
	virtual ~Forma() = default;

	virtual double Area( void ) = 0;
	virtual double Perimetro( void ) = 0;
};