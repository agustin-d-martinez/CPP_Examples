#pragma once

#include "../Punto/Punto.h"
#include <vector>
#include "Forma.h"

class Poligono : public Forma{
	protected:
	std::vector<Punto> puntos;

	public: 
	Poligono() {}
	virtual ~Poligono() override {}
};