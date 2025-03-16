#pragma once
#include "../Punto/Punto.h"

class Linea
{
private:
	Punto inicio , fin ;
public:
	Linea();
	Linea(const Punto& _inicio , const Punto& _fin);
	~Linea(){}
	double getPendiente( void );
	double Largo( void );
	void setOrigen( const Punto& a );
	void setFinal( const Punto& a);

	bool operator== (const Linea& a);
};

