#pragma once

#include "Plano.h"

class Figura {
	public:

	Figura() {}
	virtual ~Figura() = default;
	virtual void Imprimir(Plano& a ) = 0;
};