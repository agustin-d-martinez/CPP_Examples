#pragma once

#include <vector>
#include "Forma.h"
#include "../Punto/Punto.h"

class Poligono : public Forma{
	protected:
	
	std::vector<Punto> puntos;

	public: 
	Poligono() {}
	virtual ~Poligono() override {}
};