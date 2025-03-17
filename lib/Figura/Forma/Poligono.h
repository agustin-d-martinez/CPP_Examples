#pragma once

#include <vector>
#include "Forma.h"
#include "../Linea/Linea.h"

class Poligono : public Forma{
	protected:
	
	std::vector<Linea> lineas;

	public: 
	Poligono() {}
	virtual ~Poligono() override {}
};