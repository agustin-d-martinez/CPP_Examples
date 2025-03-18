#pragma once

#include <vector>
#include "Forma.hpp"
#include "../Linea/Linea.hpp"

class Poligono : public Forma{
	protected:
	
	std::vector<Linea> lineas;

	public: 
	Poligono() {}
	virtual ~Poligono() override {}
};